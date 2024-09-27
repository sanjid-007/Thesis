#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int c=0;
        for(auto &x:a){
            cin>>x;
            if(x>0) c++;
        }
        ll total_2x2=0;
        for(int i=0;i<n-1;i++){
            total_2x2 += min(a[i], a[i+1])/2;
        }
        ll operations = total_2x2 + max((ll)c - 2*total_2x2, 0LL);
        cout<<operations<<"\n";
    }
}
