class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total_time = 0;
        
        for(int i = 0; i < points.size() - 1; i++)
        {
            int x_time = abs(points[i][0] - points[i + 1][0]);
            int y_time = abs(points[i][1] - points[i + 1][1]);
            if(x_time >= y_time)
            {
                total_time += x_time;
            }
            else
            {
                total_time += y_time;
            }
            
        }
        
        return total_time;
    }
};