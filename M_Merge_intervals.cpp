class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> return_vector;
        vector<int> temp_interval = intervals[0];
        
        for(auto it : intervals) {
            if(it[0] <= temp_interval[1]) {
                temp_interval[1] = max(it[1], temp_interval[1]);
            } else {
                return_vector.push_back(temp_interval);
                temp_interval = it;
            }
        }
        return_vector.push_back(temp_interval);
        
        return return_vector;
    }
};