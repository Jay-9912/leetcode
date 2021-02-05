class Solution {
public:
    int kthval(vector<int>& nums1,vector<int>& nums2,int k)
    {
        int l1=0;
        int l2=0;
        int len1=nums1.size();
        int len2=nums2.size();
        int res=k;
        while (true)
        {
            if (l1>=len1) return nums2[k-len1-1];
            if (l2>=len2) return nums1[k-len2-1];
            if (res==1) return min(nums1[l1],nums2[l2]);
            int len3=min(res/2,min(len1-l1,len2-l2));
            res-=len3;
            if (nums1[l1+len3-1]>nums2[l2+len3-1])
                l2+=len3;
            else
                l1+=len3;

        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        if (len&1)
            return kthval(nums1,nums2,(len+1)/2);
        else return (kthval(nums1,nums2,len/2)+kthval(nums1,nums2,len/2+1))/2.0;
    }
};
