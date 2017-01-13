#include <iostream>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <regex>
#include <string>
#include <cassert>
#include <list>
#include <climits>
#include <algorithm>
#include <cmath>

#define ll long long
using namespace std;

long long mcf(long long n1, long long n2){
    if (n1 < n2) swap(n1, n2);
    if (n1 % n2 == 0) return n2;
    return mcf(n2, n1 % n2);
}

ll exgcd(ll n1, ll n2, ll& x, ll& y){
    bool flag = false;
    if (n1 < n2) {
        swap(n1, n2);
        flag = true;
    }
    if (n2 == 0){
        x = 1;
        y = 0;
        return n1;
    }
    ll r = exgcd(n2, n1%n2, x, y), t = x;
    x = y;
    y = t - (n1/n2)*y;
    if (flag) swap(x, y);
    return r;
}

inline long long cal(long long x, long long y, long long m, long long n, long long lcp){
    ll res = lcp, tx = 0, ty = 0, gcd = exgcd(m, n, tx, ty);
    if ((x-y) % gcd != 0) return res;
    ty = ty * (x-y)/gcd;
    if (ty < 0) ty += (abs(ty*gcd/m)+1) * m / gcd;
    res = n * ty + y;
    return res % (m*n/gcd);
}

int main()
{
    long long n = 0, m = 0, k = 0;
    cin >> m >> n >> k;
    long long lcp = m * n;
    lcp /= (long long)mcf(m, n);
    
    for (long long i=0;i<k;i++){
        long long l = 0, r = 0;
        cin >> l >> r;
        long long res = lcp;
        long long r1 = cal(l, r, m, n, lcp), r2 = cal(m-l, r, m, n, lcp), r3 = cal(l, n-r, m, n, lcp), r4 = cal(m-l, n-r, m, n, lcp);
        if (r1 > 0 && r1 < lcp && r1 / m % 2 == 0 && r1 / n % 2 == 0) res = min(res, r1);
        if (r2 > 0 && r2 < lcp && r2 / m % 2 == 1 && r2 / n % 2 == 0) res = min(res, r2);
        if (r3 > 0 && r3 < lcp && r3 / m % 2 == 0 && r3 / n % 2 == 1) res = min(res, r3);
        if (r4 > 0 && r4 < lcp && r4 / m % 2 == 1 && r4 / n % 2 == 1) res = min(res, r4);
        if (res == lcp) cout<<-1<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
