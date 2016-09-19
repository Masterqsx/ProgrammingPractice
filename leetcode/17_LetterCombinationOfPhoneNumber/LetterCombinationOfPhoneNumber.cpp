class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letter;
        if(digits.size()==0) return letter;
        for(int i=0;i<digits.size();i++){
            if((digits[i]=='1')||(digits[i]=='0')) return vector<string>();
            letter.insert(letter.begin(),num_string(digits[i]));
        }
        vector<string> re;
        string cob;
        backtracking(re,cob,letter,letter.size());
        return re;
        
    }
    void backtracking(vector<string>& re,string& cob,vector<string>& letter,int level){
        if(level<=0){
            re.push_back(cob);
            return;
        }
        for(int i=0;i<letter[level-1].size();i++){
            cob.push_back(letter[level-1][i]);
            backtracking(re,cob,letter,level-1);
            cob.pop_back();
        }
    }
    string num_string(char num){
        string re;
        switch(num){
            case '2':
                return re+="abc";
            case '3':
                return re+="def";
            case '4':
                return re+="ghi";
            case '5':
                return re+="jkl";
            case '6':
                return re+="mno";
            case '7':
                return re+="pqrs";
            case '8':
                return re+="tuv";
            case '9':
                return re+="wxyz";
            default:
                return re;
        }
    }
};