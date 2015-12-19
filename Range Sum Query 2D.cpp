// https://leetcode.com/problems/range-sum-query-2d-immutable/
// 注意是一般化的n*m的矩阵，而不是方阵，然后输入可能为空
class NumMatrix {
public:
    vector<vector<int> > pre;
    NumMatrix(vector<vector<int> > &matrix) {
        if (matrix.size() == 0)
            return ;
        int Rsize = matrix.size() + 1, Csize = matrix[0].size() + 1;
        pre = vector<vector<int> >(Rsize, vector<int>(Csize, 0));
        for (int i = 1; i < Rsize; ++i) {
            vector<int> now(Csize, 0);
            for (int j = 1; j < Csize; ++j) {
                now[j] = now[j-1] + matrix[i-1][j-1];
                pre[i][j] = pre[i-1][j] + now[j];
                //printf("i=%d, j=%d, pre=%d, now=%d\n", i, j, pre[i][j], now[j]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1;
        ++col1;
        ++row2;
        ++col2;
        return pre[row2][col2] - pre[row2][col1-1] - pre[row1-1][col2] + pre[row1-1][col1-1];
    }
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

// [[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]],sumRegion(2,1,4,3),sumRegion(1,1,2,2),sumRegion(1,2,2,4)
// Output: [-5,-4,-6]
// Expected: [8,11,12]

/*
5
3 0 1 4 2
5 6 3 2 1
1 2 0 1 5
4 1 0 1 7
1 0 3 0 5
2 1 4 3
1 1 2 2
1 2 2 4
*/