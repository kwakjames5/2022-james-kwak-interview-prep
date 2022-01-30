class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        addParenthesis(results, "", n, 0);
        return results;
    }
    
    void addParenthesis(vector<string> &v, string str, int n, int m) {
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0) {
            addParenthesis(v, str + ")", n, m - 1); 
        }
        if(n > 0) { 
            addParenthesis(v, str + "(", n - 1, m + 1); 
        }
    }
};