class Solution {
public:
    void sum(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& curr, int index)
    {
        
        if(target == 0)
        {
            result.push_back(curr);
            return;
        }
        
        while(index <  candidates.size() && target - candidates[index] >= 0)
        {
            curr.push_back(candidates[index]);
            
            sum(candidates, target - candidates[index], result, curr, index);
            index++;
            
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        sum(candidates, target, result, curr, 0);
        
        return result;
    }
};