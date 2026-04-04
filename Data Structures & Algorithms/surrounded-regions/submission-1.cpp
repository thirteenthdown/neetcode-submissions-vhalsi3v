class Solution {
private: 
    void dfsCheck(int i, int j, int n, int m, vector<vector<char>>& board){
        if(i>=n || j>=m || i<0 || j<0 || board[i][j] != 'O'){
            return;
        }
        board[i][j] = 'S';          //marking safe
        dfsCheck(i-1, j, n, m, board);
        dfsCheck(i+1, j, n, m, board);
        dfsCheck(i, j-1, n, m, board);
        dfsCheck(i, j+1, n, m, board);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n < 3 || m < 3) return;

        for(int i=0; i<n; i++){
            if(board[i][0] == 'O')  dfsCheck(i, 0, n, m, board);
            if(board[i][m-1] == 'O') dfsCheck(i, m-1, n, m, board);
        }
        for(int j=1; j<m-1; j++){
            if(board[0][j] == 'O')  dfsCheck(0, j, n, m, board);
            if(board[n-1][j] == 'O') dfsCheck(n-1, j, n, m, board);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'S') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
