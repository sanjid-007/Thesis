#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int X, Y, K;
        cin >> X >> Y >> K;
        double L = sqrt(1LL * X * X + 1LL * Y * Y);
        if (L >= K) {
            cout << "0 0 " << X << " " << Y << "\n";
            cout << "0 " << X << " " << Y << " 0\n";
        } else {
            // According to the problem statement, the answer exists.
            // So, this case should not occur.
            // If it does, we can handle it accordingly.
            // For now, we can output any valid segments.
            // However, based on the constraints, L >= K should always be true.
            cout << "0 0 " << X << " 0\n";
            cout << "0 0 0 " << Y << "\n";
        }
    }
    return 0;
}
