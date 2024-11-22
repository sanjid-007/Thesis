#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> high_numbers, low_numbers;
    for (int i = n; i >= 1; --i) {
        high_numbers.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        low_numbers.push_back(i);
    }
    int h = 0, l = 0;
    for (int i = 0; i < n; ++i) {
        if ((i+1) % 2 == 0) {
            p[i] = high_numbers[h++];
        } else {
            p[i] = low_numbers[l++];
        }
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if ((i+1) % 2 == 1) {
            k = k & p[i];
        } else {
            k = k | p[i];
        }
    }
    cout << k << endl;
    for (int num : p) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
