#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Function to calculate the MEX of an array
long long calculateMEX(vector<long long>& arr) {
    unordered_set<long long> elements(arr.begin(), arr.end());
    long long mex = 0;
    while (elements.count(mex)) {
        ++mex;
    }
    return mex;
}

// Function to determine the number of operations to transform the array into a permutation
long long getMinOperations(long long n, long long b, long long c) {
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        a[i] = b * i + c;
    }

    // Check if it's already a permutation
    vector<bool> isPresent(n, false);
    bool alreadyPermutation = true;
    for (long long i = 0; i < n; ++i) {
        if (a[i] < n) {
            isPresent[a[i]] = true;
        } else {
            alreadyPermutation = false;
        }
    }
    if (alreadyPermutation && all_of(isPresent.begin(), isPresent.end(), [](bool v) { return v; })) {
        return 0;
    }

    // Check if permutation is possible
    unordered_set<long long> uniqueElements(a.begin(), a.end());
    if (uniqueElements.size() < n) {
        return -1; // Cannot form a permutation due to duplicate values
    }

    long long operations = 0;
    while (true) {
        long long mex = calculateMEX(a);
        if (mex == n) {
            break;
        }
        auto it = max_element(a.begin(), a.end());
        *it = mex;
        ++operations;
        if (operations > n) {
            return -1; // Avoid infinite loops
        }
    }
    return operations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, b, c;
        cin >> n >> b >> c;
        cout << getMinOperations(n, b, c) << endl;
    }
    return 0;
}
