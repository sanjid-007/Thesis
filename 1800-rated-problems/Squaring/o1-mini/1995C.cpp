#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(auto &x: a) cin >> x;

        ll total_operations = 0;
        bool possible = true;
        double prev_val = static_cast<double>(a[0]);

        for(int i = 1; i < n; ++i){
            double current = static_cast<double>(a[i]);

            if(current >= prev_val){
                prev_val = current;
                continue;
            }

            if(current == 1){
                possible = false;
                break;
            }

            ll k = 0;
            // Perform squarings until current >= prev_val or until k reaches 60
            while(current < prev_val && k < 60){
                current = current * current;
                k++;
            }

            if(current >= prev_val){
                total_operations += k;
                prev_val = current;
            }
            else{
                possible = false;
                break;
            }
        }

        if(possible){
            cout << total_operations << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}
