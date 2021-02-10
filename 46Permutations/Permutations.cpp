class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& r, int no, const vector<int>& nums, vector<bool>& m)
    {
        if (no==nums.size())
        {
            res.push_back(r);
            return;
        }
        for (int i=0;i<nums.size();++i)
        {
            if (!m[i]) continue;
            r.push_back(nums[i]);
            m[i]=false;
            dfs(res,r,no+1,nums,m);
            m[i]=true;
            r.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> r;
        vector<bool> m(nums.size(),true);
        dfs(res,r,0,nums,m);
        return res;
    }
};
