#include <iostream>

using namespace std;
void lovely(int nb){
  if (nb == 0) cout<<0<<endl;
  else {
    int count = 0, t_nb = nb;
    while (t_nb != 0) {
      t_nb = t_nb >> 1;
      count++;
    }
    if (count % 2 != 0) cout<<"Not Lovely"<<endl;
    else {
      int low = (nb >> (count/2));
      if ((low ^ nb) == (low << (count/2))) cout<<low<<endl;
      else cout<<"Not Lovely"<<endl;
    }
  }
}
int main() {
  int v = 0, nb = 0;
  cin >> v;
  for (int i=0;i<v;i++){
    cin >> nb;
    lovely(nb);
  }
  return 0;
}

