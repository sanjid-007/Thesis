#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(const string &s) {
    for (char c : s) {
        if (c != '3' && c != '6') return false;
    }
    return true;
}

string smallestNumber(int n) {
    if (n == 1) return "-1";
    if (n == 2) return "66";

    // Base solution with sufficient 3s and 6s to ensure divisibility
    string base = string(n, '3');
    base[n - 1] = '6';  // Ensure divisibility by both 33 and 66
    base[n - 2] = '6';  // Add another 6 for safety

    if (isValid(base)) return base;

    return "-1";
}

int main() {
    int t;
    cin >> t;
    vector<int> cases(t);
    for (int i = 0; i < t; ++i) {
        cin >> cases[i];
    }
    for (int n : cases) {
        cout << smallestNumber(n) << endl;
    }
    return 0;
}
