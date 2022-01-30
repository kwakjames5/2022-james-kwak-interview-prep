class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int total = 0;
        
        while(left < right)
        {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(left_max > right_max)
            {
                total = max(total, right_max * (right - left));
                right--;
            }
            else
            {
                total = max(total, left_max * (right - left));
                left++;
            }
        }
        
        return total;
    }
};