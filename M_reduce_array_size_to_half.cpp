class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> int_track;
        for(int i = 0; i < arr.size(); i++)
        {
            int_track[arr[i]]++;
        }
        vector<int> int_count_vec;
        map<int, int>::iterator map_it;
        for(map_it = int_track.begin(); map_it != int_track.end(); map_it++)
        {
            int_count_vec.push_back(map_it->second);
        }
        sort(int_count_vec.begin(), int_count_vec.end(), greater<int>());
        int remove_set_count = 0;
        int half_check = 0;
        
        vector<int>::iterator vector_it;
        for(vector_it = int_count_vec.begin(); vector_it != int_count_vec.end(); vector_it++)
        {
            if(2 * half_check >= arr.size())
            {
                break;
            }
            remove_set_count++;
            half_check += *vector_it;
        }
        
        return remove_set_count;
        
    }
};