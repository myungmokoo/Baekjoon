
#include <iostream>
#include <vector>
using namespace std;

vector<int> placement[1005];
bool visited[1005];

void dfs(int i) {
    visited[i] = true;
    cout<<i<<" ";

    for (int j : placement[i]) {
        if (!visited[j]) {
            dfs(j);
        }
    }
}

void bfs(int i) {
    queue<int> q;
    q.push(i);
    visited[i] = true;

    while (!q.empty()) {
        int value = q.front();
        q.pop();

        cout << value << " ";

        for (int j : placement[value]) {
            if (!visited[j]) {
                visited[j] = true;
                q.push(j);
            }
        }

    }
}

int main() {
    int computer, n, start;
    cin >> computer >> n >> start;

    for (int i=0; i<n; i++) {
        int a,b;
        cin>> a >> b;

        placement[a].push_back(b);
        placement[b].push_back(a);
    }

    for (int i = 1; i <= computer; i++) {
        sort(placement[i].begin(), placement[i].end());
    }

    dfs(start);
    memset(visited,false,sizeof(visited));
    cout<<endl;
    bfs(start);
}