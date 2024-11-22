#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    const int MAX_N = 1e6 + 5;
    vector<int> p(MAX_N);
    vector<bool> visited(MAX_N);

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            visited[i] = false;
        }

        int swaps_needed = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                int current = i;
                int cycle_length = 0;

                // Traverse the cycle
                do {
                    visited[current] = true;
                    current = p[current];
                    cycle_length++;
                } while (!visited[current]);

                if (cycle_length >= 3) {
                    swaps_needed += (cycle_length - 1) / 2;
                }
            }
        }

        cout << swaps_needed << '\n';
    }

    return 0;
}
