class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         if (s.size() <= 1)
//     {
//         return s.size();
//     }
        
//     int curr_length = 0;
//     int max_length = 0;
//     std::string check_string = "";
//     int flag = 0;
      
//     for(int i = 0; i < s.size(); i++)
//     {
//         if(check_string.empty())
//         {
//             check_string += s[i];
//             curr_length++;
//             flag = 0;
//             std::cout << check_string << std::endl;
//             std::cout << curr_length << std::endl;
//         }
//         else
//         {            
//             for(int j = 0; j < check_string.size(); j++)
//             {
//                 if(check_string[j] == s[i])
//                 {
//                     if(curr_length > max_length)
//                     {
//                         max_length = curr_length;
//                         curr_length = 0;
//                         check_string.clear();
//                         flag = 1;
//                         check_string += s[i];
//                         curr_length++;
//                 std::cout << check_string << std::endl;
//                 std::cout << curr_length << std::endl;
//                     }
//                 }
//             }

//             if(flag == 0)
//             {
//                 check_string += s[i];
//                 curr_length++;
//                 std::cout << check_string << std::endl;
//                 std::cout << curr_length << std::endl;
//             }
//             else
//             {
//                 flag = 0;
//             }
//         }
//     }

//     std::cout << "EXITTED check_string: " << check_string << std::endl;
//     std::cout << "EXITTED curr_length: " << curr_length << std::endl;
       
//     if(curr_length > max_length)
//     {
//         max_length = curr_length;
//         check_string.clear();
//     }
      
//     return max_length;
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    
    }
};