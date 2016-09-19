#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class Solution {
  public:
    vector<vector<vector<bool> > > check;
    void solveSudoku(vector<vector<char> > &board) {
      check_initial(board);
      vector<vector<char> > result=board;
      recursive(board,result,0);
      board=result;
    }
    bool recursive(vector<vector<char> >board,vector<vector<char> >&result,int n){
      int row=n/9;
      int col=n%9;
      if(n==81)
        return true;
      else if(board[row][col]=='.'){
        for(int num=0;num<9;num++){
          if( (check[0][row][num]==true)&&(check[1][col][num]==true)&&(check[2][row/3*3+col/3][num]==true) ){
            result[row][col]=num+'1';
            check[0][row][num]=false;
            check[1][col][num]=false;
            check[2][row/3*3+col/3][num]=false;
            if(recursive(board,result,n+1))
              return true;
            result[row][col]='.';
            check[0][row][num]=true;
            check[1][col][num]=true;
            check[2][row/3*3+col/3][num]=true;
          }
        }
      }
      else{
        if(recursive(board,result,n+1))
          return true;
      }
      return false;
    }
    void check_initial(vector<vector<char> > board){
      vector<bool> temp(9,true);
      vector<vector<bool> > line(9,temp);
      vector<vector<vector<bool> > > matrix(3,line);
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          if(board[i][j]!='.'){
            int nu=board[i][j]-'1';
            matrix[0][i][nu]=false;
            matrix[1][j][nu]=false;
            matrix[2][i/3*3+j/3][nu]=false;
          }
        }
      }
      check=matrix;
    }
};   
int main(){
  vector<vector<char> > board(9,vector<char>(9,'.'));
  ifstream data;
  data.open("data.txt");
  for(int i=0;i<9;i++){
   for(int j=0;j<9;j++){
    data>>board[i][j];
    cout<<board[i][j]<<" ";
   }
   cout<<endl;
  }
  Solution test;
  test.solveSudoku(board);
  cout<<endl;
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
  data.close();
  return 1;
}

