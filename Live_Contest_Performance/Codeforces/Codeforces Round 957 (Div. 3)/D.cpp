#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct State {
    int position;
    bool isSwimming;
    int metersSwum;
};

bool canCrossRiver(int n, int m, int k, const string& a) {
    queue<State> q;
    vector<vector<bool>> visited(n + 2, vector<bool>(2, false)); // visited[position][isSwimming]

    // Start from the left bank (position 0, not swimming, 0 meters swum)
    q.push({0, false, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        int pos = curr.position;
        bool isSwim = curr.isSwimming;
        int swum = curr.metersSwum;

        if (pos == n + 1) return true;

        if (!isSwim) {
            // Jump from the surface (log or bank)
            for (int jump = 1; jump <= m; ++jump) {
                int newPos = pos + jump;
                if (newPos > n + 1) break;
                if (newPos == n + 1 || a[newPos - 1] == 'L') {
                    if (!visited[newPos][0]) {
                        visited[newPos][0] = true;
                        q.push({newPos, false, swum});
                    }
                } 
                else if (a[newPos - 1] == 'W' && swum < k) {
                    if (!visited[newPos][1]) {
                        visited[newPos][1] = true;
                        q.push({newPos, true, swum + 1});
                    }
                } else if (a[newPos - 1] == 'C') {
                    //break; // Can't jump to or over a crocodile
                }
            }
        } else {
            // Swim to the next position
            if (pos + 1 <= n + 1 && swum < k) {
                int newPos = pos + 1;
                if (newPos == n + 1 || a[newPos - 1] == 'L') {
                    if (!visited[newPos][0]) {
                        visited[newPos][0] = true;
                        q.push({newPos, false, swum});
                    }
                } else if (a[newPos - 1] == 'W') {
                    if (!visited[newPos][1]) {
                        visited[newPos][1] = true;
                        q.push({newPos, true, swum + 1});
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        string a;
        cin >> n >> m >> k;
        cin >> a;
  k++;
  
        if (canCrossRiver(n, m, k, a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
