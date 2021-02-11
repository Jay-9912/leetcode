class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        int n=0;
        vector<vector<string>> res;
        for (int i=0;i<strs.size();++i)
        {
            string t=strs[i];
            sort(t.begin(),t.end());
            if (m.count(t)==0)
            {
                vector<string> tmp;
                m[t]=tmp;
            }
            m[t].push_back(strs[i]);
        }
        //unordered_map<string,vector<string>>:: iterator iter;
        for (auto iter=m.begin();iter!=m.end();iter++)
            res.push_back(iter->second);
        return res;
    }
};
