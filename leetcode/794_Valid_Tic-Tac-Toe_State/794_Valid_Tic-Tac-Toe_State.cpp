class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countX = 0, countO = 0;
        int columnX[3] = {0, 0, 0};
        int columnO[3] = {0, 0, 0};
        int rowX[3] = {0, 0, 0};
        int rowO[3] = {0, 0, 0};
        int diagX[3] = {0, 0, 0};
        int diagO[3] = {0, 0, 0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    countX++;
                    columnX[j]++;
                    rowX[i]++;
                    if (i == j) diagX[0]++;
                    if (i + j == 2) diagX[1]++;
                }
                else if (board[i][j] == 'O'){
                    countO++;
                    columnO[j]++;
                    rowO[i]++;
                    if (i == j) diagO[0]++;
                    if (i + j == 2) diagO[1]++;
                }
            }
        }
        if (!(countX - countO >= 0 && countX - countO < 2)) return false;
        int countx = 0;
        int counto = 0;
        for ( int i = 0; i < 3; i++) {
            if (columnX[i] >= 3) countx++;
            if (columnO[i] >= 3) counto++;
            if (rowX[i] >= 3) countx++;
            if (rowO[i] >= 3) counto++;
            if (diagX[i] >= 3) countx++;
            if (diagO[i] >= 3) counto++;
        }
        if (countx > 2 || counto > 2 || (countx > 0 && counto > 0)) return false;
        else if (countx > 0 && countX - countO == 0) return false;
        else if (counto > 0 && countX > countO) return false;
        else return true;
    }
};
