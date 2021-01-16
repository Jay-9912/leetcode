#数组模拟hash
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128,-1);
        int cnt=0;
        int head=0;
        for (int i=0;i<s.length();++i)
        {
            if (m[int(s[i])]!=-1&&m[int(s[i])]>=head)
            {
                head=m[int(s[i])]+1;
            }
            m[int(s[i])]=i;
            cnt=max(cnt,i-head+1);
        }
        return cnt;
    }
};
