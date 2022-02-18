class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0 || s.size() == 1)
        {
            return false;
        }
        stack<char> store;
        for(int i = 0; i < s.size(); i++)
        {
            if((s[i]=='(' || s[i]=='{' || s[i]=='['))
            {
                store.push(s[i]);
            }
            else if((s[i]==')' || s[i]=='}' || s[i]==']'))
            {
                if(store.empty())
                {
                    return false;
                }
                
                if((store.top()=='(' && s[i]!=')') || (store.top()=='{' && s[i]!='}') || (store.top()=='[' && s[i]!=']'))
                {
                    return false;
                }
                else
                {
                    store.pop();
                }
            }
        }
        
        return store.empty();
    }
};