// #include <bits/stdc++.h>

#include <iostream>
#include <set>
using namespace std;

int n, h, safe = 0;
int max_height = 0, max_safe = 0;

int rainism[105][105] = {};
bool visited[105][105] = {};

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

set<int> range;

void dfs(int r, int c) {
    visited[r][c] = true;

    for (int i=0; i<n; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
            if (visited[nr][nc] == false && rainism[nr][nc] >= h) {
                dfs(nr, nc);
            }
        }
    }
}

int main() {
    cin>>n;

    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            cin>>rainism[r][c];
            range.insert(rainism[r][c]);
            max_height = max(max_height, rainism[r][c]);
        }
    }

    for (int i : range) {

        h = i;
        safe = 0;
        memset(visited, false, sizeof(visited));

        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                if (visited[r][c] == false && rainism[r][c] >= h) {
                    visited[r][c] = true;
                    safe++;
                    dfs(r,c);
                }
            }
        }

        max_safe = max(max_safe, safe);
    }

    cout << max_safe << endl;

    return 0;
}