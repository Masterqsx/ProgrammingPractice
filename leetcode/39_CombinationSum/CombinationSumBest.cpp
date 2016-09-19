class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > re;
        vector<int> cob;
        backtrack(candidates,target,0,cob,re);
        return re;
    }
    
    void backtrack(vector<int> candidates, int target, int start, vector<int> &cob, vector<vector<int> > &re){
        if(target<=0){
            re.push_back(cob);
            return;
        }
        for(int i=start;i<candidates.size()&&candidates[i]<=target;i++){
            cob.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i,cob,re);
            cob.pop_back();
        }
    }
};