class Solution {
public:
    bool dfs(int n, string word, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& m)
    {
        bool f=false;
        if (board[i][j]==word[n])
        {
            if (n==word.size()-1)
                return true;
            m[i][j]=true;
            vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (const auto& dir: directions) {
                        int newi = i + dir.first, newj = j + dir.second;
                        if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                            if (!m[newi][newj]) {
                                bool flag = dfs(n+1, word, newi, newj, board, m);
                                if (flag) {
                                    f = true;
                                    break;
                                }
                            }
                        }
                    }
        }
        m[i][j]=false;
        return f;

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> m(board.size(), vector<bool>(board[0].size(), false));
        for (int i=0;i<board.size();++i)
            for (int j=0;j<board[0].size();++j)
                {
                    bool f=dfs(0, word, i, j, board, m);
                    if (f)
                        return f;
                }
        return false;
    }
};
