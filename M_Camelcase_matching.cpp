class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> return_vector;
        for(int i = 0; i < queries.size(); i++)
        {
            string curr = queries[i];
            int j = 0;
            int k = 0;
            bool to_push = true;
            
            while(j < curr.size())
            {
                if(k < pattern.size() && pattern[k] == curr[j])
                {
                    k++;
                }
                else if(curr[j] >= 'A' && curr[j] <= 'Z')
                {
                    to_push = false;
                    break;
                }
                
                j++;
            }
            
            if(to_push && k == pattern.size())
            {
                return_vector.push_back(true);
            }
            else
            {
                return_vector.push_back(false);
            }
        }
        
        return return_vector;
    }
};