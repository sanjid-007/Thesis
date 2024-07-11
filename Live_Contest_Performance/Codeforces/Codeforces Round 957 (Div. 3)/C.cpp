#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int m, int k) {
    vector<int> permutation;
    // Adding elements from k to n
    for (int i = n; i >=k; i--) {
        permutation.push_back(i);
    }
    for (int i = m + 1; i < k; ++i) {
        permutation.push_back(i);
    }
    // Adding elements from 1 to m
    for (int i = 1; i <= m; ++i) {
        permutation.push_back(i);
    }
    // Adding elements from m+1 to k-1
    

    // Output the permutation
    for (int i = 0; i < n; ++i) {
        cout << permutation[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        solve(n, m, k);
    }
    return 0;
}
