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
        stack<long> numStack;
        //infix notation calculation
        while(ss>>op){
            while(opStack.size()>1&&comp(opStack.top(),op)){
                long n2=numStack.top();
                numStack.pop();
                long n1=numStack.top();
                numStack.pop();
                char opera=opStack.top();
                opStack.pop();
                numStack.push(count(n1,n2,opera));
            }
            opStack.push(op);
            ss>>cur;
            numStack.push(cur);
        }
        while(opStack.size()>1){
            long n2=numStack.top();
            numStack.pop();
            long n1=numStack.top();
            numStack.pop();
            char opera=opStack.top();
            opStack.pop();
            numStack.push(count(n1,n2,opera));
        }
        return numStack.top();
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