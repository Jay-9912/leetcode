class Solution {
public:
    bool isValid(string s) {
        char stack[10001];
        stack[0]='!';
        int head=0;
        for (int i=0;i<s.length();++i)
        {
            switch (s[i])
            {
                case ')':
                    if (stack[head]=='(')
                    {
                        head--;
                        continue;
                    }
                    else return false;
                case ']':
                    if (stack[head]=='[')
                    {
                        head--;
                        continue;
                    }
                    else return false;
                case '}':
                    if (stack[head]=='{')
                    {
                        head--;
                        continue;
                    }
                    else return false;
                default:
                    stack[++head]=s[i];
            }
        }
        if (head==0) return true;
        else return false;
    }
};
