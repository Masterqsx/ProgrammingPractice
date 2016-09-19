class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size()==0){
            return result;
        }
        stringstream ss;
        int temp=nums[0];
        int start=nums[0];
        ss<<nums[0];
        vector<int>::iterator it=nums.begin()+1;
        while(it!=nums.end()){
            if(*it!=*(it-1)+1){
                if(temp!=start){
                    ss<<"->"<<temp;
                }
                result.push_back(ss.str());
                ss.str("");
                ss.clear();
                ss<<*it;
                temp=*it;
                start=*it;
            }
            else{
                temp+=1;
            }
            it++;
        }
        if(temp!=start){
            ss<<"->"<<temp;
        }
        result.push_back(ss.str());
        
        return result;
    }
};