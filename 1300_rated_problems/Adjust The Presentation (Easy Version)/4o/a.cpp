#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// Function to check if the slideshow is good
bool isGoodSlideshow(const vector<int>& a, const vector<int>& b) {
    unordered_map<int, int> memberPos;
    for (int i = 0; i < a.size(); ++i) {
        memberPos[a[i]] = i;
    }

    int currentPosition = -1;
    for (int member : b) {
        if (memberPos[member] <= currentPosition) {
            return false;
        }
        currentPosition = memberPos[member];
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        // Check the initial state
        

        // Process updates
        for (int i = 0; i < q; ++i) {
            int s, t;
            cin >> s >> t;
            b[s - 1] = t;

            if (isGoodSlideshow(a, b)) {
                cout << "YA" << endl;
            } else {
                cout << "TIDAK" << endl;
            }
        }
    }

    return 0;
}
