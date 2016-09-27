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
class segTree{
    public :
    class node{
    public:
        int lo;
        int hi;
        int val;
        node(int _lo, int _hi):lo(_lo), hi(_hi), val(0){}
    };
    vector<node> tree;
    int sz;
    segTree(vector<int>& array){
        sz = (int)ceil(log(array.size())/log(2));
        sz = 2*pow(2,sz)-1;
        tree = vector<node>(sz, node(0,0));
        construct((int)array.size());
        construct_r(array, 0);
    }
    int setValue_r(int lo, int hi, int index, int change){
        if (tree[index].lo > hi || tree[index].hi < lo) return tree[index].val;//**important
        if (tree[index].lo == tree[index].hi) return tree[index].val+=change;
        int l = setValue_r(lo, hi, 2*index+1, change);
        int r = setValue_r(lo, hi, 2*index+2, change);
        tree[index].val = min(l, r);
        return tree[index].val;
    }
    void setValue(int lo, int hi, int change){
        setValue_r(lo, hi, 0, change);
    }
    void construct(int len){
        unsigned int lo = 0, hi = len-1, n = 0;
        tree[0].lo = lo;
        tree[0].hi = hi;
        while (n < sz){
            if (2*n+1 < sz){
                tree[2*n+1].lo = tree[n].lo;
                tree[2*n+1].hi = (tree[n].hi+tree[n].lo)/2;
                tree[2*n+2].lo = (tree[n].hi+tree[n].lo)/2+1;
                tree[2*n+2].hi = tree[n].hi;
            }
            n++;
        }
    }
    int construct_r(vector<int>& array, int index){
        if (tree[index].lo == tree[index].hi) {
            tree[index].val = array[tree[index].lo];
            return array[tree[index].lo];
        }
        int l = construct_r(array, 2*index+1);
        int r = construct_r(array, 2*index+2);
        tree[index].val = min(l, r);//tree[index].val = l+r;the comment is for sum calculation
        return tree[index].val;
    }
    int getSum(int lo, int hi){
        return getSum_r(lo, hi, 0);
    }
    int getSum_r(int lo, int hi, int index){
        if (tree[index].lo >= lo && tree[index].hi <= hi) return tree[index].val;
        if (tree[index].lo > hi || tree[index].hi < lo) return INT_MAX;//return 0;the comment is for sum calculation
        int l = getSum_r(lo, hi, 2*index+1);
        int r = getSum_r(lo, hi, 2*index+2);
        return min(l,r);//l+r;
    }
};
int main() {
    vector<int> array({1,3,5,7,9,11});
    segTree t(array);
    t.setValue(2, 4, 3);
    cout<<t.getSum(2,4)<<endl;
    return 0;
}
