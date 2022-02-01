class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> int_count;
        for(int i = 0; i < nums.size(); i++)
        {
            int_count[nums[i]]++;
        }
        
        map<int, int>::iterator map_it;
        for(map_it = int_count.begin(); map_it != int_count.end(); map_it++)
        {
            if(map_it->second == 1)
            {
                return map_it->first;
            }
        }
        
        return 0;
    }
};