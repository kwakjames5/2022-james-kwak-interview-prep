class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string sb = "";
        
        int open = 0;
        for(char c : s) {
            if(c == '(') {
                open++;
            } else if(c == ')') {
                if(open == 0) {
                    continue;
                }
                open--;
            }
            
            sb += c;
        }
        
        string result = "";
        stack<char> char_stack;
        for(int i = sb.size() - 1; i >= 0; i--) {
            if(sb[i] == '(' && open-- > 0) {
                continue;
            }
            char_stack.push(sb[i]);
        }        
        
        while(!char_stack.empty()) {
            result += char_stack.top();
            char_stack.pop();
        }
        
        return result;
    }
};