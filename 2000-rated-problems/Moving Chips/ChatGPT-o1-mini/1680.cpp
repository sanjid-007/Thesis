#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> chips; // list of column indices
        int m0 =0, m1 =0;
        // To store row information
        vector<pair<int, int>> chip_list; // (row, c)
        for(int c=0; c<n; c++){
            if(s1[c] == '*'){
                chip_list.emplace_back(0, c);
                m0++;
            }
            if(s2[c] == '*'){
                chip_list.emplace_back(1, c);
                m1++;
            }
        }
        int m = chip_list.size();
        if(m ==1){
            cout << "0\n";
            continue;
        }
        // Collect sorted_cols
        vector<int> sorted_cols;
        sorted_cols.reserve(m);
        for(auto &p: chip_list){
            sorted_cols.push_back(p.second);
        }
        sort(sorted_cols.begin(), sorted_cols.end());
        // Compute prefix_sum
        vector<ll> prefix_sum(m+1, 0LL);
        for(int i=0; i<m; i++) prefix_sum[i+1] = prefix_sum[i] + (ll)sorted_cols[i];
        // Sort chip_list by c
        sort(chip_list.begin(), chip_list.end(), [&](const pair<int,int> &a, const pair<int,int> &b) -> bool{
            if(a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });
        // Collect unique c_targets with counts x and y
        vector<tuple<int, int, int>> unique_cs; // (c, x, y)
        int current_c = -1;
        int current_x =0, current_y=0;
        for(auto &p: chip_list){
            int r = p.first;
            int c = p.second;
            if(c != current_c){
                if(current_c != -1){
                    unique_cs.emplace_back(current_c, current_x, current_y);
                }
                current_c = c;
                current_x =0;
                current_y =0;
            }
            if(r ==0) current_x++;
            else current_y++;
        }
        // Add the last c
        if(current_c != -1){
            unique_cs.emplace_back(current_c, current_x, current_y);
        }
        // Now, iterate through unique_cs and compute min_total_sum
        ll min_total_sum = LLONG_MAX;
        for(auto &[c_target, x, y] : unique_cs){
            // Compute sum_c = sum |c_i - c_target|
            // Find lower_bound and upper_bound
            int index = lower_bound(sorted_cols.begin(), sorted_cols.end(), c_target) - sorted_cols.begin();
            ll sum_left = (ll)c_target * index - prefix_sum[index];
            int index_right = upper_bound(sorted_cols.begin(), sorted_cols.end(), c_target) - sorted_cols.begin();
            ll sum_right = prefix_sum[m] - prefix_sum[index_right] - (ll)c_target * (m - index_right);
            ll sum_c = sum_left + sum_right;
            // total_sum_row0 = sum_c + m1
            ll total_sum_row0 = sum_c + (ll)m1;
            // total_sum_row1 = sum_c + m0
            ll total_sum_row1 = sum_c + (ll)m0;
            // total_sum = min(total_sum_row0, total_sum_row1)
            ll total_sum = min(total_sum_row0, total_sum_row1);
            // Update min_total_sum
            if(total_sum < min_total_sum){
                min_total_sum = total_sum;
            }
        }
        cout << min_total_sum << "\n";
    }
}
