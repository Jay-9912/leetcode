class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int cnt=0;
        int head=0;
        for (int i=0;i<s.length();++i)
        {
            if (m.find(s[i])!=m.end()&&m[s[i]]>=head)
            {
                head=m[s[i]]+1;
                
            }
            m[s[i]]=i;
            cnt=max(cnt,i-head+1);
        }
        return cnt;
    }
};
