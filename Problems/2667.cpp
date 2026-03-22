#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int total = 0;

int apartment[105][105];
vector <int> department;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool visited[105][105];

void dfs(int r, int c, int t) {
    department[t]++;
    visited[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
            if (visited[nr][nc] == false && apartment[nr][nc] == 1) {
                dfs(nr,nc,t);
            }
        }
    }

}

int main() {
    cin>>n;

    for (int r=0; r<n; r++) {
        string row;
        cin >> row;
        for (int c = 0; c<n; c++) {
            apartment[r][c] = row[c] - '0';
        }
    }

    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            if (visited[r][c] == false && apartment[r][c] == 1) {
                department.push_back(0);
                dfs(r,c,total);
                total++;
            }
        }
    }

    sort(department.begin(), department.end());

    cout << total << endl;
    for (int i : department) {
        cout << i << "\n";
    }

}