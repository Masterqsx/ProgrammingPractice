#include "indexpq.h"
#include <iostream>
using namespace std;

int main(){
  IndexPQ<int> a;
  a.insert(0, 10);
  a.insert(1, 9);
  a.insert(2, 11);
  a.insert(3, 5);
  //a.modify(1, 5);
  a.erase(3);
  cout<<a.minPQ().first<<endl;
  cout<<a[2]<<endl;
  cout<<a.count(2)<<endl;
  cout<<a.count(3)<<endl;
  return 0;
}
