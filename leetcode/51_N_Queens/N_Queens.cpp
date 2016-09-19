class Solution {
public:
    vector<int> board;
    int length;
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;i++) board.push_back(i);
        length=n;
        vector<vector<string>> re;
        backtracking(0,re);
        return re;
    }
    void backtracking(int level,vector<vector<string>>& re){
        if(level>=length) print_board(re);//is very important,
        else{
            for(int i=level;i<length;i++){//the int i = level is very important, the traverse in each level start from the first number
                if(isvalid(level,i)){
                    swap(board[level],board[i]);
                    backtracking(level+1,re);
                    swap(board[level],board[i]);
                }
            }
        }
    }
    bool isvalid(int level,int i){
        for(int n=0;n<level;n++){
            if(n-level==board[i]-board[n]||n-level==board[n]-board[i]) return false;
        }
        return true;
    }
    void print_board(vector<vector<string>>& re){
        vector<string> solution=vector<string>(length,string(length,'.'));
        for(int i=0;i<length;i++) solution[i].at(board[i])='Q';
        re.push_back(solution);
    }
    
    
};