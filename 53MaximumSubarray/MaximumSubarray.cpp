class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp=nums[0];
        int maxi=tmp;
        for (int i=1;i<nums.size();++i)
        {
            tmp=tmp>0?(tmp+nums[i]):nums[i];
            maxi=maxi<tmp?tmp:maxi;
        }
        return maxi;
    }
};
