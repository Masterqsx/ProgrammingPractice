class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool result=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    result=result||search(board,word,i,j);
                }
            }
        }
        return result;
    }
    
    bool search(vector<vector<char> >& board,string word,int i,int j){
        if(word.size()==0){
            return true;
        }
        if((i<0)||(j<0)||(i>=board.size())||(j>=board[i].size())){
            return false;
        }
        
        if(board[i][j]=='\0'){
            return false;
        }
        if(board[i][j]==word[0]){
            board[i][j]='\0';
            bool result=search(board,word.substr(1,word.size()-1),i-1,j)||search(board,word.substr(1,word.size()-1),i+1,j)||search(board,word.substr(1,word.size()-1),i,j-1)||search(board,word.substr(1,word.size()-1),i,j+1);
            board[i][j]=word[0];
            return result;
        }
        return false;
    }
    
    
};