class Solution {
public:
    //segment tree
    struct segtree
    {
        int lsum;
        int rsum;
        int msum;
        int sum;
    };
    segtree pushup(segtree l, segtree r)
    {
        int lsum=max(l.lsum,l.sum+r.lsum);
        int rsum=max(r.rsum,r.sum+l.rsum);
        int msum=max(max(l.rsum+r.lsum,l.msum),r.msum);
        int sum=l.sum+r.sum;
        return (segtree){lsum,rsum,msum,sum};
    }
    segtree get(const vector<int>& nums, int l, int r)
    {
        if (l==r)
            return (segtree){nums[l],nums[l],nums[l],nums[l]};
        int m=(l+r)>>1;
        segtree lt=get(nums, l, m);
        segtree rt=get(nums, m+1, r);
        return pushup(lt, rt);
    }
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size()-1).msum;
    }
};
