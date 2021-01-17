class Solution {
public:
    unordered_map<char, string> m{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void backtrack(const string &digits,int loc,string &comb,vector<string> &res)
    {
        if (loc==digits.length())
        {
            res.push_back(comb);
            return;
        }
        for (int i=0;i<m[digits[loc]].length();++i)
        {
            comb.push_back(m[digits[loc]][i]);
            backtrack(digits,loc+1,comb,res);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int l=digits.length();
        string comb;
        vector<string> res;
        if (l==0)
            return res;
        backtrack(digits,0,comb,res);
        return res;
    }
};
