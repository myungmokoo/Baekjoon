#include <bits/stdc++.h>
using namespace std;

int n, m, c, maximum = 0;
bool visited[100005];
vector<int> total(100005);
vector<vector<int>> computers(100005);

void dfs(int computer) {
    visited[computer] = true;
    c++;
    for (int i : computers[computer]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin>>n>>m;

    for (int i = 0; i < m; i++) {
        int a,b;
        cin>>a>>b;
        computers[b].push_back(a);
    }


    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        c = 0;
        dfs(i);
        total[i] = c;
        maximum = maximum > c ? maximum : c;
    }

    for (int i = 1; i <= n; i++) {
        if (total[i] == maximum) {
            cout<<i<<" ";
        }
    }
}