#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> switches(2 * n);
        int count1 = 0;

        for (int i = 0; i < 2 * n; i++) {
            cin >> switches[i];
            if (switches[i] == 1) count1++;
        }

        int totalSwitches = 2 * n;
        int count0 = totalSwitches - count1;

        // Maximum lights on
        int maxLightsOn = min(count1, count0);

        // Minimum lights on
        int minLightsOn = abs(count1 - count0) / 2;

        cout << minLightsOn << " " << maxLightsOn << endl;
    }
}

int main() {
    solve();
    return 0;
}
