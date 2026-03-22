//#include <bits/stdc++.h>

#include <iostream>
using namespace std;

long long int f,s,g,u,d;
long long int buttons[1000005];
bool visited[1000005];

queue<int> q;

int main() {
    cin >> f >> s >> g >> u >> d;

    long long int method[2] = {u, d * -1};

    q.push(s);
    visited[s] = true;
    buttons[s] = 0;

    while(!q.empty()) {
        int c = q.front();
        q.pop();

        if (c == g) {
            cout<<buttons[c];
            return 0;
        }

        for (int i : method) {
            int new_floor = c + i;
            if (new_floor >= 1 && new_floor <= f) {
                if (!visited[new_floor]) {
                    q.push(new_floor);
                    visited[new_floor] = true;
                    buttons[new_floor] = buttons[c] + 1;
                }
            }
        }
    }

    cout<<"use the stairs";
}