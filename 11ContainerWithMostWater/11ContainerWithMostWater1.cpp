class Solution {
public:
    int maxArea(vector<int>& height) {
        int head=0;
        int tail=height.size()-1;
        int res=0;
        while(head<tail)
        {
            res=max(res,min(height[head],height[tail])*(tail-head));
            if (height[head]>height[tail])
                tail--;
            else head++;
        }
        return res;
    }
};
