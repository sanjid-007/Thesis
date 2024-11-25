#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Element {
    ll value;
    int index;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<Element> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].value;
            a[i].index = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sort the array a
        sort(a.begin(), a.end(), [](const Element &e1, const Element &e2) {
            return e1.value < e2.value;
        });

        ll m = (n + 1) / 2;
        ll m_prime = n / 2;

        vector<ll> median_c(n);
        vector<int> pos_in_sorted(n);
        for (int i = 0; i < n; ++i) {
            pos_in_sorted[a[i].index] = i;
        }

        // Compute median(c_i) for each index
        for (int i = 0; i < n; ++i) {
            int pos_i = pos_in_sorted[i];
            if (pos_i <= m_prime - 1) {
                median_c[i] = a[m_prime].value;
            } else {
                median_c[i] = a[m_prime - 1].value;
            }
        }

        ll max_score = 0;
        for (int i = 0; i < n; ++i) {
            ll current_score;
            if (b[i] == 1) {
                current_score = a[pos_in_sorted[i]].value + k + median_c[i];
            } else {
                current_score = a[pos_in_sorted[i]].value + median_c[i];
            }
            max_score = max(max_score, current_score);
        }

        cout << max_score << endl;
    }
    return 0;
}
