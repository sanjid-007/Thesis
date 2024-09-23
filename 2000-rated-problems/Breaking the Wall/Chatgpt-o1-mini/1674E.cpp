#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    
    // Option2: Sum of two smallest ceil(a_i /2)
    // Find the two smallest (a_i +1)/2
    ll first_min = LLONG_MAX, second_min = LLONG_MAX;
    for(int i=0;i<n;i++){
        ll val = ( (ll)a[i] +1 ) /2;
        if(val < first_min){
            second_min = first_min;
            first_min = val;
        }
        else if(val < second_min){
            second_min = val;
        }
    }
    ll option2 = first_min + second_min;
    
    // Option1: Breaking two sections by shooting at a single position
    ll min_option1 = LLONG_MAX;
    for(int x=0; x<n; x++){
        ll k_x;
        if(x ==0){
            if(n >=2){
                ll ceil_a0 = ((ll)a[0] +1)/2;
                ll a1 = (ll)a[1];
                k_x = max(ceil_a0, a1);
            }
            else{
                // n ==1, but n>=2 as per constraints
                ll ceil_a0 = ((ll)a[0] +1)/2;
                k_x = ceil_a0;
            }
        }
        else if(x ==n-1){
            if(n >=2){
                ll anm2 = (ll)a[n-2];
                ll ceil_an = ((ll)a[n-1] +1)/2;
                k_x = max(anm2, ceil_an);
            }
            else{
                // n ==1, but n>=2 as per constraints
                ll ceil_an = ((ll)a[n-1] +1)/2;
                k_x = ceil_an;
            }
        }
        else{
            // Middle positions
            // Option a: break x and x-1
            ll ceil_ax = ((ll)a[x] +1)/2;
            ll ceil_axm1 = ((ll)a[x-1] +1)/2;
            ll option_a = max(ceil_ax, ceil_axm1);
            
            // Option b: break x and x+1
            ll ceil_axp1 = ((ll)a[x+1] +1)/2;
            ll option_b = max(ceil_ax, ceil_axp1);
            
            // Option c: break x-1 and x+1
            ll a_xm1 = (ll)a[x-1];
            ll a_xp1 = (ll)a[x+1];
            ll option_c = max(a_xm1, a_xp1);
            
            // Minimum of the three options
            k_x = min( min(option_a, option_b), option_c );
        }
        min_option1 = min(min_option1, k_x);
    }
    
    // Option3: Breaking two adjacent sections together
    ll min_option3 = LLONG_MAX;
    for(int i=0;i<n-1;i++){
        ll a_i = (ll)a[i];
        ll a_j = (ll)a[i+1];
        ll ceil_sum = (a_i + a_j + 2)/3;
        ll ceil_ai = (a_i +1)/2;
        ll ceil_aj = (a_j +1)/2;
        ll k_i = max( ceil_sum, max(ceil_ai, ceil_aj) );
        min_option3 = min(min_option3, k_i);
    }
    
    // Final answer is the minimum among Option1, Option2, Option3
    ll answer = min( min_option1, min(option2, min_option3) );
    cout << answer;
}
