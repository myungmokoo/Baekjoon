// #include <bits/stdc++.h>

#include <iostream>
using namespace std;

int n, m;
int maze[105][105];
int dist[105][105];

queue<pair<int, int>> q;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void bfs() {
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;

        if (r == m-1 && c == n-1) {
            cout << dist[r][c] << endl;
            return;
        }

        q.pop();

        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (dist[nr][nc] == -1 && maze[r][c] == 1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.emplace(nr, nc);
                }
            }
        }
    }
}

int main() {

    memset(dist, -1, sizeof(dist));

    cin >> n >> m;

    for (int c = 0; c < n; c++) {
        string s;
        cin >> s;
        for (int r = 0; r < m; r++) {
            maze[r][c] = s[r] - '0';
        }
    }

    dist[0][0] = 1;
    q.emplace(0,0);

    bfs();
}