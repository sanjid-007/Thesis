#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;
    while(t--) {
        int n; // Number of pillars
        cin >> n;
        vector<int> h(n); // Heights of the pillars
        for(int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        int operations = 0;
        // Count the number of times the non-decreasing order is violated
        for(int i = 0; i < n - 1; ++i) {
            if(h[i] > h[i+1]) {
                operations++;
            }
        }
        cout << operations << endl;
    }
    return 0;
}
