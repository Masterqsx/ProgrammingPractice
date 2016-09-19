class Solution {
public:
    string simplifyPath(string path) {
        string re;
        stack<string> q_path;
        string q_word;
        path+='/';//Make sure the last characteristic is a '/'
        for(int i=0;i<path.size();i++){
            if((path[i]=='/')&&(q_word.size()!=0)){
                if(q_word.compare(string("."))==0){ ;}
                else if(q_word.compare(string(".."))==0){
                    if(!q_path.empty()){
                        q_path.pop();
                        q_path.pop();
                    }
                }
                else{
                    q_path.push(string("/"));
                    q_path.push(q_word);
                }
                q_word.clear();
            }
            else if(path[i]!='/') q_word.push_back(path[i]);//make sure when q_word is empty, we will not push duplicated '/'
        }
        while(!q_path.empty()){
            string temp;
            temp=q_path.top();
            temp+=re;
            re=temp;
            q_path.pop();
        }
        if(re.empty()) re.push_back('/');
        return re;
        
    }
};