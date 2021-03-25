class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1=0;
        int p2=nums.size()-1;
        for (int i=0;i<=p2;++i)
        {
            while (i<=p2 && nums[i]==2)
            {
                swap(nums[i],nums[p2--]);
            }
            if (nums[i]==0)
                swap(nums[i],nums[p1++]);
        }
    }
};
