class Solution {
public:
    void sum(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& curr, int index) {
        if(target == 0)
        {
            result.push_back(curr);
            return;
        }
        else
        {
            for(int i = index; i < candidates.size(); i++) // iterative component
            {
                if(candidates[i]>target) 
                {
                    return;
                }
                if(i && candidates[i] == candidates[i - 1] && i > index) 
                {
                    continue; // check duplicate combination
                }
                curr.push_back(candidates[i]),
                sum(candidates, target - candidates[i], result, curr, i + 1); // recursive componenet
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.empty()) {
            return result;
        }
        
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        
        sum(candidates, target, result, curr, 0);
        
        return result;
    }
};