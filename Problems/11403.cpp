// #include <bits/stdc++.h>

#include <iostream>
using namespace std;

int t, current;

int n[305];
int fr[305], fc[305], gr[305], gc[305];
int chessboard[305][305];
int dist[305][305];

int dr[8] = {2,2,-2,-2,1,-1,1,-1};
int dc[8] = {1,-1,1,-1,2,2,-2,-2};

queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        if (r == gr[current] && c == gc[current]) {
            cout << dist[r][c]<< endl;
            return;
        }

        for (int i=0; i<8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n[current] && nc < n[current]) {
                if (dist[nr][nc] == -1) {
                    q.emplace(nr, nc);
                    dist[nr][nc] = dist[r][c] + 1;
                }
            }

        }
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n[i] >> fr[i] >> fc[i] >> gr[i] >> gc[i];
    }

    for (int i = 0; i < t; i++) {
        current = i;

        while (!q.empty()) {q.pop();}
        memset(chessboard, 0, sizeof(chessboard));
        memset(dist, -1, sizeof(dist));
        dist[fr[current]][fc[current]] = 0;
        q.emplace(fr[current],fc[current]);
        bfs();
    }
}