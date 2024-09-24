#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &x:a) cin>>x;
        // Groups: value -> positions
        // Since 1 <= a[i] <=n
        vector<vector<int>> groups(n+1, vector<int>());
        for(int i=0;i<n;i++) groups[a[i]].push_back(i);
        // Collect non-empty groups
        vector<pair<int, vector<int>>> sorted_groups;
        for(int val=1; val<=n; val++) {
            if(!groups[val].empty()){
                sorted_groups.emplace_back(make_pair(val, groups[val]));
            }
        }
        // Sort groups by size descending
        sort(sorted_groups.begin(), sorted_groups.end(), [&](const pair<int, vector<int>> &a, const pair<int, vector<int>> &b) -> bool{
            if(a.second.size() != b.second.size()) return a.second.size() > b.second.size();
            return a.first < b.first;
        });
        int k = sorted_groups.size();
        // If k ==1, assign b[i]=a[i]
        vector<int> b(n, 0);
        if(k ==1){
            // Only one group, b[i]=a[i]
            for(auto pos: sorted_groups[0].second){
                b[pos] = sorted_groups[0].first;
            }
        }
        else{
            // Create shifted_values
            vector<int> shifted_values(k);
            for(int i=0;i<k;i++) shifted_values[i] = sorted_groups[(i+1)%k].first;
            // Assign shifted_values to groups
            for(int i=0;i<k;i++){
                for(auto pos: sorted_groups[i].second){
                    b[pos] = shifted_values[i];
                }
            }
        }
        // Output b
        for(int i=0;i<n;i++) cout<<b[i]<<(i<n-1?" ":"\n");
    }
}
