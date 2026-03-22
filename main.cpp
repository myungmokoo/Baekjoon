//#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int n, m, days = 0;

int farm[1005][1005];
queue<pair<int, int>> q;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main() {
    cin>>n>>m;
    for (int r=0; r<m; r++) {
        for (int c=0; c<n; c++) {
            cin>>farm[r][c];
            if (farm[r][c]  == 1) {
                q.emplace(r, c);
            }
        }
    }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (farm[nr][nc] == 0) {
                    farm[nr][nc] = farm[r][c] + 1;
                    q.emplace(nr, nc);
                }
            }
        }
    }

    for (int r=0; r<m; r++) {
        for (int c=0; c<n; c++) {
            if (farm[r][c]  == 0) {
                cout << -1;
                return 0;
            }
            days = max(days, farm[r][c]);
        }
    }

    cout<<days - 1<<endl;
}