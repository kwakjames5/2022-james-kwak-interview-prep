class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> return_words;
        for(string word : words) {
            if(pattern_check(word) == pattern_check(pattern)) {
                return_words.push_back(word);
            }
        }
        return return_words;
    }
    
    string pattern_check(string word) {
        unordered_map<char, int> pattern_map;
        for(char c : word) {
            if(pattern_map.find(c) == pattern_map.end()) {
                pattern_map[c] = pattern_map.size();
            }
        }
        for (int i = 0; i < word.length(); ++i) {
            word[i] = 'a' + pattern_map[word[i]];    
        } 
        return word;
    }
};