#include <bits/stdc++.h>

using namespace std;

int n;
int a,b;
int m;
vector<int> relationship[100005];
queue<int> q;
int parent[100005];
int chon[100005];

int main() {

    memset(chon, -1, sizeof(chon));

    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        relationship[x].push_back(y);
        relationship[y].push_back(x);
    }

    chon[a] = 0;
    q.push(a);


    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (b == current) {
            cout << chon[b];
            return 0;
        }

        for (int next : relationship[current]) {
            if (chon[next] == -1) {
                chon[next] = chon[current] + 1;
                q.push(next);
            }
        }
    }

    cout<<-1;
}