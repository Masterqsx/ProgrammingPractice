class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size()<=10) return ans;
        unordered_map<int,bool> record;
        unordered_map<int,bool>::iterator it;
        int begin=1,end=10,num=0;
        for(int i=0;i<10;i++){
            encode(num,s[i]);
        }
        record[num]=true;
        while(end<s.size()){
            encode(num,s[end]);
            if(((it=record.find(num))!=record.end())&&(it->second)){
                ans.push_back(s.substr(begin,10));
                it->second=false;
            }
            else if(it==record.end()) record[num]=true;
            begin++;
            end++;
        }
        return ans;
    }
    void  encode(int& n,char c){
        n=n<<2;
        n=n&0x000FFFFF;
        switch(c){
            case 'A': n|=0x0;
                break;
            case 'C': n|=0x1;
                break;
            case 'G': n|=0x2;
                break;
            default : n|=0x3;
                break;
        }
    }
};