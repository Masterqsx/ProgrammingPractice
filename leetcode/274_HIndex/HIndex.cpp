class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int num=0,s=citations.size();
        for(int i=s-1;i>=0;i--){
            if(s-i>citations[i]) break;
            num=max(min(citations[i],s-i),num);
        }
        return num;
    }
};