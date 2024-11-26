#include <iostream>
#include <string>
#include <set>
using namespace std;

bool willMeet(int n, int a, int b, string s) {
    int x = 0, y = 0;
    set<pair<int, int>> visited; // Track unique positions visited
    visited.insert({x, y});

    // Simulate one full cycle of the moves
    for (char move : s) {
        if (move == 'N') y++;
        else if (move == 'E') x++;
        else if (move == 'S') y--;
        else if (move == 'W') x--;
        visited.insert({x, y});
    }

    // Check if Red Queen's position is visited
    if (visited.count({a, b})) return true;

    // Check infinite pattern by tracking net displacement
    int dx = 0, dy = 0;
    for (char move : s) {
        if (move == 'N') dy++;
        else if (move == 'E') dx++;
        else if (move == 'S') dy--;
        else if (move == 'W') dx--;
    }

    // If there is no net displacement and target not reached, return false
    if (dx == 0 && dy == 0) return false;

    // Check if (a, b) is reachable with net displacement considered
    for (int i = 0; i < 100; i++) { // Arbitrary limit to simulate long movement
        x += dx;
        y += dy;
        if (x == a && y == b) return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        cout << (willMeet(n, a, b, s) ? "YES" : "NO") << endl;
    }
    return 0;
}
