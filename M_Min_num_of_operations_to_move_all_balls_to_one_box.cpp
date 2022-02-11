class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result(boxes.length()); 
        int ops = 0, cnt = 0;
        for (int i = 0; i < boxes.length(); ++i) {
           result[i] += ops;
           cnt += boxes[i] == '1' ? 1 : 0;
           ops += cnt;
        }
        ops = 0, cnt = 0;
        for (int i = boxes.length() - 1; i >= 0; --i) {
            result[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        
        return result;
    }
};