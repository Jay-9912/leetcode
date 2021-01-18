class Solution {
public:
    bool match(char a, char b)
    {
        if (b=='.') return true;
        return a==b;
    }
    bool isMatch(string s, string p) {
        int l1=s.length();
        int l2=p.length();
        //vector<vector<int>> dp(l1+1,vector<int>(l2+1));
        bool **dp;
        dp = new bool*[l1+1];
        for (int i=0;i<=l1;++i)
            dp[i]=new bool[l2+1];
        dp[0][0]=true;
        for (int j=1;j<=l2;++j)
        {
            if (p[j-1]=='*')
                dp[0][j]=dp[0][j-2];
            else dp[0][j]=false;
        }
        for (int i=1;i<=l1;++i)
            dp[i][0]=false;
        for (int i=1;i<=l1;++i)
        {
            for (int j=1;j<=l2;++j)
            {
                if (p[j-1]=='*')
                {
                    if (match(s[i-1],p[j-2]))
                    {
                        dp[i][j]=dp[i-1][j]|dp[i][j-2];
                    }
                    else dp[i][j]=dp[i][j-2];
                }
                else
                    dp[i][j]=match(s[i-1],p[j-1])&dp[i-1][j-1];
            }
        }
        bool tmp=dp[l1][l2];
        for (int i=0;i<=l1;++i)
            delete [] dp[i];
        delete [] dp;
        return tmp;
    }
};
