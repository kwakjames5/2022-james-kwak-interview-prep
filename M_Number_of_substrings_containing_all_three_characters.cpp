class Solution {
public:
    int numberOfSubstrings(string s) {
        // A B C will hold the indexes of where these letters occurred in the string
        vector<int> A, B, C;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a')
            {
                A.push_back(i);
            }
            else if(s[i] == 'b')
            {
                B.push_back(i);
            }
            else
            {
                C.push_back(i);
            }
        }
        
        int total = 0, i = 0, j = 0, k = 0;
        while(i < A.size() && j < B.size() && k < C.size())
        {
            // figure out the first index where 'a', 'b' AND 'c' are all present
            int max_index = max(A[i], max(B[j], C[k]));
            
            // s.size() - max_index is because now that a substring with all three letters are found,
            // any substrings until the end of the string including these three letters
            // will add to the total
            // s.size() is the total number of substrings that can be made with this current substring
            // and max_index is the last index of the current substring
            total += s.size() - max_index;
            
            if(A[i] < B[j] && A[i] < C[k])
            {
                i++;
            }
            else if(B[j] < A[i] && B[j] < C[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }
        
        return total;
        
    }
};