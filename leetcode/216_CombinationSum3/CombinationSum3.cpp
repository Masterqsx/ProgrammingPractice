class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > re;
        if(k==0) return re;
        vector<int> cob;
        backtrack(cob,re,k,n,1);
        return re;
    }
    void backtrack(vector<int>& cob,vector<vector<int> >& re,int k,int n,int start){
        if(k==0){
            if(n==0){
                re.push_back(cob);
            }
            else{
                return;
            }
        }
        for(int i=start;i<10&&i<=n;i++){
            cob.push_back(i);
            backtrack(cob,re,k-1,n-i,i+1);
            cob.pop_back();
        }
    }
};