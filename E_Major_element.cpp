class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // when nums only has 1 int, return that int
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        // map to keep track of count of integers in nums
        map<int, int> track_map;
            
        // iterate nums
        for(int i = 0; i < nums.size();i++)
        {
            // make a pair if nums[i] is not in track_map yet
            if(track_map.find(nums[i]) == track_map.end())
            {
                track_map.insert(pair<int, int>(nums[i], 1));
            }
            else if(track_map.find(nums[i]) != track_map.end())
            {
                // if the pair already is in the map, increment the count by 1
                track_map[nums[i]]++;
            }
            
            // if ever the nums[i]'s count is greater than half of the size of 
            // the nums vector, return the majority element
            if(track_map[nums[i]] > nums.size()/2)
            {
                return nums[i];
            }
        }
        
        return 0;
    }
};