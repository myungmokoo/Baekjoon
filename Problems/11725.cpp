#include <bits/stdc++.h>

using namespace std;

int n, target;
int parent[1000005];
bool visited[1000005];
vector<int> nodes;

void dfs(int node) {
    visited[node] = true;
    for (int next: nodes[node]) {
        if (!visited[next]) {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    nodes.resize(n + 5);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    visited[1] = true;
    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << endl;
    }
}
