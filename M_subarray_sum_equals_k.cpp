class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int sum = 0;
        map<int, int> map;
        map[0]++;
        for(int n : nums) {
            sum += n;
            result += map[sum - k];
            map[sum]++;
        }
        
        return result;
    }
};