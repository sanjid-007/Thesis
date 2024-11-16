#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll xor1toN(ll n){
    if(n <0){
        return 0;
    }
    ll rem = n %4;
    if(rem ==0) return n;
    if(rem ==1) return 1;
    if(rem ==2) return n+1;
    return 0;
}


ll get_B(ll n, ll m, ll k, int i){
    if(n <k){
        return 0;
    }
    ll y_max = (n -k)/m;
    ll C = y_max +1;
    ll xor_y = xor1toN(y_max);
    ll x = xor_y << i;
    if(C &1){
        x ^=k;
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll l, r, i, k;
        cin >> l >> r >> i >> k;
        ll m = 1ULL << i;
        ll A = xor1toN(r) ^ xor1toN(l-1);
        ll B_r = get_B(r, m, k, i);
        ll B_l1 = get_B(l-1, m, k, i);
        ll B = B_r ^ B_l1;
        ll ans = A ^ B;
        cout << ans << "\n";
    }
}
