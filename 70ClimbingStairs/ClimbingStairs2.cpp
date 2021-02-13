class Solution {
public:
    // matrix fast pow
    vector<vector<long>> mul(const vector<vector<long>>& a, const vector<vector<long>>& b)
    {
        vector<vector<long>> c(2,vector<long>(2));
        for (int i=0;i<2;++i)
            for (int j=0;j<2;++j)
                c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];
        return c;
    }
    vector<vector<long>> fastpow(vector<vector<long>> a, int n)
    {
        vector<vector<long>> ret={{1,0},{0,1}};
        while(n>0)
        {
            if (n&1)
                ret=mul(ret,a);
            n>>=1;
            a=mul(a,a);
        }
        return ret;
    }
    int climbStairs(int n) {
        vector<vector<long>> base={{1,1},{1,0}};
        return fastpow(base,n)[0][0];
    }
        
};
