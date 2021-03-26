class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i=0;i<(1<<nums.size());++i)
        {
            tmp.clear();
            for (int j=0;j<nums.size();++j)
            {
                if (i&(1<<j))
                    tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
