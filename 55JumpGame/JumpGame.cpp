class Solution {
public:
    bool canJump(vector<int>& nums) {
        int p=nums.size()-2;
        while(p>=0)
        {
            if (nums[p]>0) p--;
            else
            {
                int q=p-1;
                while (q>=0)
                {
                    if (nums[q]+q>p)
                    {
                        p=q-1;
                        break;
                    }
                    q--;
                }
                if (q<0) return false;
            }
        }
        return true;
    }
};
