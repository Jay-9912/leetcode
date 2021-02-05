class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> res(s.length()+1,0);
        for (int i=1;i<s.length();++i)
        {
            if (s[i]==')')
            {
                if (s[i-1]=='(')
                    res[i+1]=res[i-1]+2;
                else
                {
                    if (i-1-res[i]>=0 && s[i-1-res[i]]=='(')
                        res[i+1]=res[i]+2+res[i-1-res[i]];
                }
            }
        }
        return *max_element(res.begin(),res.end());
    }
};
