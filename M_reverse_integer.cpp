class Solution {
public:
    int reverse(int x) {
        int returnNum = 0;
        while(x) {
            int popNum = x%10;
            x /= 10;
            /* CHECK FOR OUT OF BOUNDS HERE W/ INT_MAX and INT_MIN */
            if (returnNum > INT_MAX / 10 || returnNum == INT_MAX / 10 && popNum > INT_MAX % 10) {
                return 0;
            } 
            if (returnNum < INT_MIN / 10 || returnNum == INT_MIN / 10 && popNum < INT_MIN % 10) {
                return 0;
            } 
            
            returnNum = returnNum * 10 + popNum;
        }
        
        return returnNum;
    }
};