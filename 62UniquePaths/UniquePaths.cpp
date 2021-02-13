class Solution {
public:
    int uniquePaths(int m, int n) {
        long int fac=1;
        for (int i=1;i<m;++i)
        {
            fac=fac*(i+n-1)/i;
        }
        return fac;
    }
};
