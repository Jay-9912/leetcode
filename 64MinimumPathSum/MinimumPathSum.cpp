class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> m(grid.size(),vector<int>(grid[0].size(),0));
        m[0][0]=grid[0][0];
        for (int i=1;i<m.size();++i)
            m[i][0]=m[i-1][0]+grid[i][0];
        for (int i=1;i<m[0].size();++i)
            m[0][i]=m[0][i-1]+grid[0][i];
        for (int i=1;i<m.size();++i)
            for (int j=1;j<m[0].size();++j)
                m[i][j]=min(m[i-1][j],m[i][j-1])+grid[i][j];
        return m[grid.size()-1][grid[0].size()-1];
    }
};
