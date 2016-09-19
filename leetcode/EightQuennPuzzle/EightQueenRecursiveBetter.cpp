#include<iostream>
using namespace std;

int g_re=0;
void eight_queen(unsigned char rw,unsigned char dd,unsigned char ud,int level){
  if(level>=8) g_re++;
  dd=dd>>1;
  ud=ud<<1;
  unsigned char pos=~(rw|dd|ud);
  for(unsigned char mask=128;mask>0;mask=mask>>1){
    if((pos&mask)>0) eight_queen(rw|(pos&mask),dd|(pos&mask),ud|(pos&mask),level+1);
  }
}

int main(){
  eight_queen(0,0,0,0);
  cout<<g_re<<endl;
  return 0;
}
