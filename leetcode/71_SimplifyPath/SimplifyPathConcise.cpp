class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path+"/");//even the geline could stop at /0 and still output the true, we still need to print a / at last
        string word;
        vector<string> sta;
        while(getline(ss,word,'/')){
            if((word.compare(".")==0)||(word.compare("")==0)) continue;//we need to prevent there is no element between two '/'.
            else if(word.compare("..")==0){
                if(!sta.empty()) sta.pop_back();
            }
            else sta.push_back("/"+word);
            word.clear();
        }
        for(auto str:sta) word+=str;
        if(sta.empty()) word+="/";
        return word;
        
    }
};