class Solution {
public:
    pair<int,int> findstr(string s,int begin,int end)
    {
        int i=1;
        while (begin-i>=0&&end+i<s.length())
        {
            if (s[begin-i]!=s[end+i])
                break;
            i++;
        }
        pair<int,int> res=make_pair(begin-i+1,end+i-1);
        return res; 
    }
    string longestPalindrome(string s) {
        pair<int,int> res;
        res=make_pair(0,0);
        for (int i=0;i<s.length();++i)
        {
            pair<int,int> r;
            r=findstr(s,i,i);
            if (i+1<s.length()&&s[i]==s[i+1])
            {
                pair<int,int> tmp;
                tmp=findstr(s,i,i+1);
                if (tmp.second-tmp.first>r.second-r.first)
                    r=tmp;
            }
            if (res.second-res.first<r.second-r.first)
                res=r;
        }
        return s.substr(res.first,res.second-res.first+1);
    }
};
