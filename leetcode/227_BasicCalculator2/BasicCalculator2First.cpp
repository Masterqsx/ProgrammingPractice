class Solution {
public:
    long calculate(string s) {
        long re=0,temp=0,cur=0,n1=0,n2=0;
        if(s.empty()) return re;
        string s_new;
        //delete whitespace
        for(auto c:s){
            if(c!=' ') s_new+=c;
        }
        //avoid start check
        s_new="^"+s_new;
        stringstream ss(s_new);
        char op;
        stack<char> opStack;
        vector<string> postfix;
        //infix notation to postfix notation
        while(ss>>op){
            while(!opStack.empty()&&comp(opStack.top(),op)){
                string t;
                t.push_back(opStack.top());
                postfix.push_back(t);
                opStack.pop();
            }
            opStack.push(op);
            ss>>cur;
            postfix.push_back(to_string(cur));
        }
        while(!opStack.empty()){
            string t;
            t.push_back(opStack.top());
            postfix.push_back(t);
            opStack.pop();
        }
        postfix.pop_back();
        //postfix notation calculate
        stack<long> postfix_count;
        ss.str("");
        ss.clear();
        for(auto&& str:postfix){
            if(!isop(str)){
                ss<<str;
                ss>>cur;
                postfix_count.push(cur);
                ss.str("");
                ss.clear();
            }
            else{
                n2=postfix_count.top();
                postfix_count.pop();
                n1=postfix_count.top();
                postfix_count.pop();
                postfix_count.push(count(n1,n2,str[0]));
            }
        }
        return postfix_count.top();
    }
    //used for postfix notation calculate, distinguish between num and op
    bool isop(string s){
        return (s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/');
    }
    //used for calculate value
    long count(long n1,long n2,char op){
        switch(op){
            case '+': return n1+n2;
            case '-': return n1-n2;
            case '*': return n1*n2;
            case '/': return n1/n2;
            default: return 0;
        }
    }
    //check op precedence
    bool comp(char c1,char c2){
        int p1=0,p2=0;
        if(c1=='^') p1=-1;
        if(c2=='^') p2=-1;
        if(c1=='*'||c1=='/') p1=1;
        if(c2=='*'||c2=='/') p2=1;
        return (p2<=p1);
    }
};