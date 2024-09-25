#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN]; // adjacency list for the tree
int color[MAXN]; // color array to store the bipartite coloring

// DFS function to color the tree in two colors (bipartite coloring)
void dfs(int node, int parent, int c) {
    color[node] = c;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, 1 - c);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    // Reading the tree edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Start DFS from vertex 1, and color it with 0
    dfs(1, -1, 0);
    
    // Output
    int goodVertices = 0;
    long long totalWeight = 0;
    vector<int> weights(n + 1, 1); // initially, all weights are set to 1

    // Count good vertices (all vertices are good in this case)
    goodVertices = n;
    totalWeight = n; // all weights are 1, so total weight is just n
    
    // Output the number of good vertices and total sum of weights
    cout << goodVertices << " " << totalWeight << endl;
    
    // Output the weights of the vertices
    for (int i = 1; i <= n; i++) {
        cout << weights[i] << " ";
    }
    cout << endl;
    
    return 0;
}
