class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int sum=0;
        int leftmax=0;
        int rightmax=0;
        while(l<=r)
        {
            if (height[l]<height[r])
            {
                if (height[l]<leftmax)
                    sum+=leftmax-height[l++];
                else
                    leftmax=height[l++];
            }
            else 
            {
                if (height[r]<rightmax)
                    sum+=rightmax-height[r--];
                else 
                    rightmax=height[r--];
            }
        }
        return sum;
    }
};
