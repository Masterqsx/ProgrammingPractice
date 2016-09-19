class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)  return string("0");
        if(denominator==0) return string();
        bool symbol=false;
        long long nu=numerator,de=denominator;
        //determine the answer is positive or not
        if(nu<0&&de<0||nu>0&&de>0) symbol=true;
        if(nu<0) nu*=(-1);
        if(de<0) de*=(-1);
        string ans;
        if(!symbol) ans+="-";
        //make the fraction a proper fraction
        if(nu>=de){
            ans+=to_string(nu/de);
            nu%=de;
        }
        else ans+="0";
        if(nu!=0){
            ans+=".";
            unordered_map<long long,long long> remain;//use hashmap to prevent the sparse situation when use array.
            unordered_map<long long,long long>::iterator it;
            remain[nu]=1;
            long long r=0,count=2;
            nu*=10;
            string temp;
            while((r=nu%de)!=0){
                if((it=remain.find(r))!=remain.end()){
                    temp.insert(it->second-1,"(");
                    temp+=to_string(nu/de);
                    temp+=")";
                    break;
                }
                else{
                    temp+=to_string(nu/de);
                    remain[r]=count;
                }
                count++;
                nu=r*10;
            }
            if(r==0) temp+=to_string(nu/de);//The while loop check statement may make us miss the last element.
            ans+=temp;
        }
        return ans;
    }
};