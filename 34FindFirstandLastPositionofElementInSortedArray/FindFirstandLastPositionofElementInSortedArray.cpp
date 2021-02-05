class Solution {
public:
    int binary_search(const vector<int>& nums, int l, int r, bool left, int target)
    {
        int s=nums.size();
        int ans=s;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if ((left && nums[mid]>=target) || (!left && nums[mid]>target))
            {
                r=mid-1;
                ans=mid;
            }
            else 
                l=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lidx=binary_search(nums,0,nums.size()-1,true,target);
        int ridx=binary_search(nums,0,nums.size()-1,false,target)-1;
        if (lidx<=ridx && lidx>=0 && ridx<=nums.size()-1) 
            return vector<int> {lidx,ridx};
        else return vector<int> {-1,-1};
    }
};
