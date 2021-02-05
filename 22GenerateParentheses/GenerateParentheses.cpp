class Solution {
public:
    void dfs(int l,int r, string p, vector<string> &res)
    {
        if (l==0&&r==0)
        {
            res.push_back(p);
            return;
        }
        if (l>0)
        {
            p.append(1,'(');
            dfs(l-1,r,p,res);
            p.pop_back();
        }
        if (r>l)
        {
            p.append(1,')');
            dfs(l,r-1,p,res);
            p.pop_back();      
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string p="";
        dfs(n,n,p,res);
        return res;
    }
};
