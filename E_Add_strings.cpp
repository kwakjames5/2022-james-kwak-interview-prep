class Solution {
public:
    string addStrings(string num1, string num2) {
        string output;
        int num1_track = num1.length() - 1;
        int num2_track = num2.length() - 1;
        int carry = 0;
        
        while(num1_track >= 0 || num2_track >= 0)
        {
            int sum = carry;
            if(num1_track >= 0)
            {
                sum += num1.at(num1_track) - '0';
                num1_track--;
            }
            if(num2_track >= 0)
            {
                sum += num2.at(num2_track) - '0';
                num2_track--;
            }
            output.push_back(sum%10 + '0');
            
            carry = sum/10;
        }
        
        if(carry != 0)
        {
            output.push_back(carry + '0');
        }
        
        reverse(output.begin(), output.end());
        return output;
        
        /*
        while(sum >= 0)
        {
            if(sum > 10)
            {
                temp = to_string(sum%10);
            }
            else
            {
                temp = to_string(sum);
            }
            sum/10;
            output += temp;
            if(sum == 0)
            {
                break;
            }
        }
        
        for(int i = 0; i < sum.length(); i++)
        {
            if(sum > 10)
            {
                temp = to_string(sum%10);
                sum/10;
            }
            else
            {
                temp = to_string(sum);
            }
            output += temp;
        }
        */
    }
};