class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int sub_count = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if(i >= k)
            {
                sum -= arr[i - k];
            }
            if(sum/k >= threshold && i >= k - 1)
            {
                sub_count++;
            }
        }
        
        return sub_count;
    }
};