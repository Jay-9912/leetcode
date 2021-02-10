class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& r, int loc,  const vector<int> & candidates, const int& target, int sum)
    {
        if (sum>target)
            return;
        if (sum==target)
        {
            res.push_back(r);
            return; 
        }
        for (int i=loc;i<candidates.size();++i)
        {
            if (sum+candidates[i]>target)
                break;
            r.push_back(candidates[i]);
            dfs(res, r, i, candidates, target, sum+candidates[i]);
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> r;
        dfs(res, r, 0, candidates, target, 0);
        return res;  
    }
};
