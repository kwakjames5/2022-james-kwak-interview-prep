class Solution {
public:
    bool detectCapitalUse(string word) {
        bool proper_use = true;
        bool upper_case = false;
        if(word[1] >= 'A' && word[1] <= 'Z')
        {
            upper_case = true;
            if(word[0] >= 'a' && word[0] <= 'z')
            {
                proper_use = false;
                return proper_use;
            }
        }
        
        if(word.size() <= 2)
        {
            return proper_use;
        }
        
        for(int i = 2; i < word.size(); i++)
        {
            if(!upper_case)
            {
                if(word[i] >= 'A' && word[i] <= 'Z')
                {
                    proper_use = false;
                    break;
                }
            }
            else
            {
                if(word[i] >= 'a' && word[i] <= 'z')
                {
                    proper_use = false;
                    break;
                }
            }
        }
        
        return proper_use;
    }
};