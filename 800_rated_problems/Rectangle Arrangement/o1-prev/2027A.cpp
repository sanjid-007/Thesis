#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int max_w = 0, max_h = 0;
        for (int i = 0; i < n; ++i) {
            int w, h;
            cin >> w >> h;
            // Ensure w is width and h is height
            max_w = max(max_w, w);
            max_h = max(max_h, h);
        }
        int perimeter = 2 * (max_w + max_h);
        cout << perimeter << endl;
    }
    return 0;
}
