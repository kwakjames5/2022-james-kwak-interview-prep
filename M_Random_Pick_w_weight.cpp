class Solution {
public:
    int sum = 0;
    vector<int> pick_vector;
    
    Solution(vector<int>& w) {
        for(int i = 0; i < w.size(); i++) {
            sum += w[i];
            pick_vector.push_back(sum);
        }
        // for(int i = 0; i < w.size(); i++) {
            // for(int j = 0; j < w[i]; j++) {
            //     pick_vector.push_back(w[i]);
            // }
        // }
        
        for(int i = 0; i < pick_vector.size(); i++) {
            std::cout << pick_vector[i] << std::endl;
        }
    }
    
    int pickIndex() {
        int num = rand()%(sum); // random num between 0 and sum
        auto it = upper_bound(pick_vector.begin(), pick_vector.end(), num); // iterator to first index in pick_vector greater than random num between 0 and sum
        // return pick_vector[num];
        return it - pick_vector.begin(); // returns index of iterator
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */