#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;

        int x = 0, y = 0;
        int step = 0;
        bool found = false;
        set<tuple<int, int, int>> visited;
        visited.insert({x, y, 0});

        while (true) {
            // Check if Alice has met the Red Queen
            if (x == a && y == b) {
                cout << "YES" << endl;
                found = true;
                break;
            }

            // Determine the move
            char move = s[step % n];
            if (move == 'N') {
                y += 1;
            } else if (move == 'S') {
                y -= 1;
            } else if (move == 'E') {
                x += 1;
            } else if (move == 'W') {
                x -= 1;
            }

            step++;

            // Check if this state has been visited
            int idx = step % n;
            if (visited.count({x, y, idx})) {
                cout << "NO" << endl;
                break;
            } else {
                visited.insert({x, y, idx});
            }
        }
    }
    return 0;
}
