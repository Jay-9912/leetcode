class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int cnt=0;
        int head=0;
        for (int i=0;i<s.length();++i)
        {
            if (m.count(s[i])==0)
            {
                m[s[i]]=i;
            }
            else
            {
                int k=head;
                head=m[s[i]]+1;
                for (;k<=m[s[i]];++k)
                    m.erase(s[k]);

                m[s[i]]=i;
            }
            cnt=max(cnt,i-head+1);
        }
        return cnt;
    }
};
