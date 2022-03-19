class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> return_vector;
        priority_queue<pair<int, int>> store;
        for(int i = 0; i < arr.size(); i++)
        {
            store.push(make_pair(abs(arr[i] - x), arr[i]));
            if(store.size() > k)
            {
                store.pop();
            }
        }
        
        for(int i = 0; i < k ; i++)
        {
            return_vector.push_back(store.top().second);
            store.pop();
        }
        sort(return_vector.begin(), return_vector.end());
        
        return return_vector;
    }
};