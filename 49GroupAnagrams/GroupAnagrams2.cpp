class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,vector<string>> m;
        int n=0;
        vector<vector<string>> res;
        const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        const int MOD=1e9+7;
        for (int i=0;i<strs.size();++i)
        {
            long int hash=1;
            for (int j=0;j<strs[i].length();++j)
                hash=hash*prime[strs[i][j]-'a']%MOD;
            if (m.count(hash)==0)
            {
                vector<string> tmp;
                m[hash]=tmp;
            }
            m[hash].push_back(strs[i]);
        }
        //unordered_map<string,vector<string>>:: iterator iter;
        for (auto iter=m.begin();iter!=m.end();iter++)
            res.push_back(iter->second);
        return res;
    }
};
