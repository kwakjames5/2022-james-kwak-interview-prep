class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> int_count_map;
        for(int i : nums) {
            int_count_map[i]++;
        }
        
        priority_queue<pair<int, int>> priority_q;
        
        for(auto pair: int_count_map) {
            priority_q.push({pair.second, pair.first});
        }
        vector<int> result;
        while(k > 0) {
            result.push_back(priority_q.top().second);
            priority_q.pop();
            k--;
        }
        
        return result;
    }
};