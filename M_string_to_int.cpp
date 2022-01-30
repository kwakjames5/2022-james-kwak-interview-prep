class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0)
        {
            return 0;
        }
        
        int counter = 0;
        int size = s.length();
        
        while(counter < size && s[counter] == ' ')
        {
            counter++;
        }
        
        int sign = 1;
        
        if(counter < size && (s[counter] == '-' || s[counter] == '+'))
        {
            if(s[counter] == '-')
            {
                sign = -1;
            }
            counter++;
        }
        
        int answer = 0;
        
        while(counter < size && isdigit(s[counter]))
        {
            if(answer > (INT_MAX - (s[counter] - '0')) / 10)
            {
                if(sign == -1)
                {
                    return INT_MIN;
                }
                else
                {
                    return INT_MAX;
                }
            }
            answer = (answer * 10) + (s[counter] - '0');
            cout << answer << endl;
            counter++;
        }
        
        return answer * sign;
    }
};