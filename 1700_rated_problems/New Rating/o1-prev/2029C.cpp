#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int sign(int x) {
    if (x > 0) return +1;
    else if (x == 0) return 0;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i =1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int> delta(n+1), w(n+1);
        int x = 0;
        vector<int> x_arr(n+1);
        x_arr[0] = 0;
        for (int i =1; i <= n; ++i) {
            delta[i] = sign(a[i] - x);
            x += delta[i];
            x_arr[i] = x;
            w[i] = -delta[i];
        }
        int total_delta = x;
        int max_so_far = w[1], max_ending_here = w[1];
        int s = 1, start = 1, end =1;
        for (int i =2; i <= n; ++i) {
            if (max_ending_here + w[i] >= w[i]) {
                max_ending_here += w[i];
            } else {
                max_ending_here = w[i];
                s = i;
            }
            if (max_ending_here > max_so_far) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
        }
        int S = max_so_far;
        int final_x = total_delta + S;
        cout << final_x << "\n";
    }
    return 0;
}
