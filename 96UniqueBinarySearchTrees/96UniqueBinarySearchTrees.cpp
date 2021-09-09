class Solution {
public:
    int numTrees(int n) {
        int bst[20];
        bst[0] = 1;
        for (int i=1; i<=n; ++i)
        {
            bst[i] = 0;
            for (int j=0; j<i; ++j)
                bst[i] += bst[j] * bst[i-1-j];
        }
        return bst[n];
    }
};
