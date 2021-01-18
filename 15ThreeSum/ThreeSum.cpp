class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int la,lb,lc;
        la=lb=lc=100001;
        int b,c;
        int l=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int i=0;i<l-2;++i)
        {
            if (nums[i]==la)
                continue;
            b=i+1;
            c=l-1;
            la=nums[i];
            while(b<c)
            {
                lb=nums[b];
                lc=nums[c];
                if (nums[i]+nums[b]+nums[c]==0)
                {
                    vector<int> tmp={nums[i],nums[b],nums[c]};
                    res.push_back(tmp);
                }

                if (nums[i]+nums[b]+nums[c]>0)
                {
                    c--;
                    while(c>b && nums[c]==lc)
                        --c;
                }
                else
                {
                    b++;
                    while(c>b && nums[b]==lb)
                        b++;
                }

            }
        }
        return res;
    }
};
