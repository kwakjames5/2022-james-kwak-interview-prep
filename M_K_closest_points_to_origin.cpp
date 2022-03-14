class Solution {
public:
    double distance(vector<int> temp_point) {
        return sqrt((temp_point[0] * temp_point[0]) + (temp_point[1] * temp_point[1]));
    }
    
    // priority queue puts everything from greatest to least and pushes and pops front only
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> return_vector;
        priority_queue<pair<double, vector<int>>> distance_points;
        for(int i = 0; i < points.size(); i++)
        {
            distance_points.push(make_pair(distance(points[i]), points[i]));
            if(distance_points.size() > K)
            {
                distance_points.pop();
            }
        }
        
        for(int i = 0; i < K; i++)
        {
            return_vector.push_back(distance_points.top().second);
            distance_points.pop();
        }
        
        return return_vector;
    }
};