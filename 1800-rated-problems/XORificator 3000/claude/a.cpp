#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function to calculate XOR of numbers from 1 to n
int xorUpTo(int n) {
    if (n < 0) return 0;
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0;
}

// Function to calculate XOR of range [l,r]
int rangeXor(int l, int r) {
    return xorUpTo(r) ^ xorUpTo(l - 1);
}

// Main function to solve each query
int solveQuery(int l, int r, int i, int k) {
    if (i == 0) return rangeXor(l, r);
    
    int powerOf2 = (1LL << i);
    int result = 0;
    
    // Adjust l to next block start if needed
    int firstBlock = l / powerOf2 * powerOf2;
    if (l > firstBlock) {
        // Handle remaining numbers in first incomplete block
        for (int x = l; x < min(firstBlock + powerOf2, r + 1); x++) {
            if (x % powerOf2 != k) {
                result ^= x;
            }
        }
        l = firstBlock + powerOf2;
    }
    
    if (l > r) return result;
    
    // Handle complete blocks
    int lastBlock = r / powerOf2 * powerOf2;
    if (lastBlock >= l) {
        int completeBlocks = (lastBlock - l) / powerOf2 + 1;
        
        // For each complete block:
        // XOR all numbers except those ≡ k (mod 2^i)
        for (int x = 0; x < powerOf2; x++) {
            if (x != k) {
                // If odd number of complete blocks, include this position
                if (completeBlocks % 2 == 1) {
                    result ^= x;
                }
            }
        }
        
        // Apply block offset to result
        if (completeBlocks % 2 == 1) {
            result = (result << (int)log2(l)) ^ l;
        }
    }
    
    // Handle remaining numbers in last incomplete block
    for (int x = lastBlock + powerOf2; x <= r; x++) {
        if (x % powerOf2 != k) {
            result ^= x;
        }
    }
    
    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int l, r, i, k;
        cin >> l >> r >> i >> k;
        cout << solveQuery(l, r, i, k) << "\n";
    }
    
    return 0;
}
