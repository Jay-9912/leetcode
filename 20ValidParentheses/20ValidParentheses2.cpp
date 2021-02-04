class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> pair={
            {')','('},
            {']','['},
            {'}','{'},
        };
        for (char i:s)
        {
            if (pair.count(i))
            {
                if (st.empty()||st.top()!=pair[i])
                    return false;
                else st.pop();
            }
            else st.push(i);
        }
        return st.empty();
    }
};
