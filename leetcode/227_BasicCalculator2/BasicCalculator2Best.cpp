class Solution {
public:
    long calculate(string s) {
        if(s.empty()) return 0;
        s+="$";
        //avoid start check
        stack<char> opStack;
        stack<long> numStack;
        long cur=0,n2,n1;
        //infix notation calculate
        char opera;
        for(auto&& c:s){
            if(c=='$') numStack.push(cur);
            else if(c==' ') continue;
            else if(isdigit(c)) cur=cur*10+c-'0';
            else{
                numStack.push(cur);
                cur=0;
                while(!opStack.empty()&&comp(opStack.top(),c)){
                    n2=numStack.top();
                    numStack.pop();
                    n1=numStack.top();
                    numStack.pop();
                    opera=opStack.top();
                    opStack.pop();
                    numStack.push(count(n1,n2,opera));
                }
                opStack.push(c);
            }
        }
        while(!opStack.empty()){
            n2=numStack.top();
            numStack.pop();
            n1=numStack.top();
            numStack.pop();
            opera=opStack.top();
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
        if(c1=='*'||c1=='/') p1=1;
        if(c2=='*'||c2=='/') p2=1;
        return (p2<=p1);
    }
};