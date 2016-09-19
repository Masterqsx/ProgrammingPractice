class Solution {
  public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res, bool* used, vector<int>& current) {
      if (i == j) { //key part different from swap method j in this method
        res.push_back(current);
        return;
      }
      //int last=1000;
      for (int k = 0; k < j; k++) { //key part different from swap method "0" in this method 
        if(!used[k]){
        //  if(last==num[k])
          //  continue;
          //else
           // last=num[k];
          used[k]=true;
          current[i]=num[k];
          recursion(num, i+1, j, res, used, current);
          used[k]=false;

        }
      }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
      sort(num.begin(), num.end());//key part for duplicated number
      vector<vector<int> >res;
      bool* used=new bool[num.size()];
      vector<int> current=num;
      for(int i=0;i<num.size();i++){
        used[i]=false;
      }
      recursion(num, 0, num.size(), res, used, current);
      return res;
    }
};
