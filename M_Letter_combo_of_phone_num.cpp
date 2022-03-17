class Solution {
public:
    const vector<string> numberpad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) {
            return result;
        }
        
        result.push_back("");
        
        for(char i : digits) {
            vector<string> temp;
            for(char j : numberpad[i - '0']) {
                for(string k : result) {
                    temp.push_back(k + j);
                }
            }
            result.swap(temp);
        }
        
        
        return result;
    }
};