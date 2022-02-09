class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> int_count;
        for(int i = 0; i < arr.size(); i++)
        {
            int_count[arr[i]]++;
        }
        
        map<int, int> occurence_count;
        map<int, int>::iterator map_it;
        bool unique_or_not = true;
        for(map_it = int_count.begin(); map_it != int_count.end(); map_it++)
        {
            if(occurence_count.find(map_it->second) == occurence_count.end())
            {
                occurence_count[map_it->second]++;
            }
            else
            {
                unique_or_not = false;
                return unique_or_not;
            }
        }
        
        return unique_or_not;
    }
};