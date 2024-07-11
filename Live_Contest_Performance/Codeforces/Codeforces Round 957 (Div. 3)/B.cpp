#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int ones = 0, operations = 0;
        int p = 0;
        for (int i = 0; i < k-1; i++) {
            if (a[i] == 1) {
                ones++;
            } else {
                operations += (a[i] - 1);
                ones+=a[i];
            }
            
        }

        cout << operations+ones << endl;
    }
    return 0;
}
