#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;
    while(t--) {
        int n; // Number of lights
        cin >> n;
        vector<int> S(2*n); // States of switches
        int N0 = 0; // Count of switches that are off
        int N1 = 0; // Count of switches that are on
        for(int i = 0; i < 2*n; ++i) {
            cin >> S[i];
            if(S[i] == 0) N0++;
            else N1++;
        }

        int min_lights_on;
        if(N0 % 2 == 1 && N1 % 2 == 1) {
            min_lights_on = 1;
        } else {
            min_lights_on = 0;
        }
        int max_lights_on = min(N0, N1);

        cout << min_lights_on << " " << max_lights_on << endl;
    }
    return 0;
}
