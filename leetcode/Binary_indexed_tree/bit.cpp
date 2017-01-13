//
//  main.cpp
//  code practice
//
//  Created by 钱圣欣 on 16/9/26.
//  Copyright © 2016年 qsx. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
class Bit{
public:
    vector<int> tree;
    int sz;
    Bit(vector<int>& array){
        sz = (int)array.size()+1;
        tree = vector<int>(sz, 0);
        construct(array);
    }
    void construct(vector<int>& array){
        for (int i=1;i<sz;i++){
            int index = i;
            while (index < sz){
                tree[index] += array[i-1];
                index = index + (index & (-index));
            }
        }
    }
    int getSum_single(int end){
        int index = end + 1, res = 0;
        while (index > 0 && index < sz){
            res += tree[index];
            index = index & (index-1);
        }
        return res;
    }
    int getSum(int lo, int hi){//the range is inclusive
        return getSum_single(hi) - (lo>0?getSum_single(lo-1):0);
    }
    void setValue(int index, int change){
        while (index < sz){
            tree[index] += change;
            index = index + (index & (-index));
        }
    }
};
int main() {
    vector<int> array({3,2,-1,6,5,4,-3,3,7,2,3});
    Bit t(array);
    cout<<t.getSum(1,3)<<endl;
    t.setValue(3, 10);
    return 0;
}
