class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0]<b[0];
    }
    struct cmp2
    {
        bool operator() (const vector<int>& s1, const vector<int>& s2)
        {
           return s1[0]<s2[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& o1,const vector<int>& o2) { return (o1[0]<o2[0]); });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i=1;i<intervals.size();++i)
        {
            if (intervals[i][0]<=res.back()[1])
            {
                if (res.back()[1]<intervals[i][1])
                    res.back()[1]=intervals[i][1];
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
