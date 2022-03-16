class Solution {
public:
    string reverseWords(string s) {
//         stack<string> string_stack;
        
//         string curr = "";
//         for(int i = 0; i < s.size(); i++) {
//             if(s[i] == ' ' || i == s.size() - 1) {
//                 if(i == s.size() - 1) {
//                     curr += s[i];
//                 }
//                 string_stack.push(curr);
//                 curr = "";
//             }
//             else
//             {
//                 curr += s[i];
//             }
//         }
        
//         string result = "";
//         bool first = true;
        
//         while(!string_stack.empty()) {
//             if(first) {
//                 first = false;
//                 result += string_stack.top();
//                 string_stack.pop();
//             }
//             else {
//                 result += (" " + string_stack.top());
//                 string_stack.pop();
//             }
//         }
        
        string result = "";
        stringstream stream(s);
        string curr;
        while(stream >> curr) {
            result = curr + " " + result;
        }
        
        return result.substr(0, result.length()-1);
    }
};