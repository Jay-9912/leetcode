class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> loc;
        vector<int> res(2,-1);
        for (int i=0;i<n;++i)
        {
            if (loc.count(target-nums[i])==1&&loc[target-nums[i]]!=i)
            {
                res[1]=i;
                res[0]=loc[target-nums[i]];
                return res;
            }
            loc[nums[i]]=i;
        }
        return res;
    }
};
