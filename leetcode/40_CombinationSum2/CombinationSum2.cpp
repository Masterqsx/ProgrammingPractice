class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cob;
        vector<vector<int> > re;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates, cob, re, target, 0);
        return re;
    }
    void backtrack(vector<int> candidates, vector<int>& cob, vector<vector<int> >& re, int target, int begin){
        if(target==0){
            re.push_back(cob);
            return;
        }
        for(int i=begin;i<candidates.size()&&candidates[i]<=target;i++){
            if((i!=begin)&&(candidates[i]==candidates[i-1])) continue;
            cob.push_back(candidates[i]);
            backtrack(candidates, cob, re, target-candidates[i],i+1);
            cob.pop_back();
        }
    }
    
};