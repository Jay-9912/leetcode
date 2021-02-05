class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int maxi=nums[nums.size()-1];
        for (int i=nums.size()-2;i>=0;--i)
        {
            if (nums[i]<maxi)
            {
                int mini=101;
                int idx;
                for (int j=nums.size()-1;j>i;--j)
                {
                    if (nums[j]>nums[i]&&nums[j]<=mini)
                    {
                        idx=j;
                        mini=nums[j];
                    }
                }
                swap(nums[i],nums[idx]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
            maxi=max(maxi,nums[i]);
        }
        sort(nums.begin(),nums.end());
    }
};
