//#include <bits/stdc++.h>
#include <iostream>
#include <deque>
using namespace std;

int n,k;
int seconds[100005] = {};
deque<int> q;

void bfs() {
    while(!q.empty()) {
        int current = q.front();
        int walk_options[2] = {current + 1, current - 1};
        int teleportation = current * 2;

        q.pop_front();

        if (current == k) {
            cout << seconds[current] << " ";
            return;
        }

        if (teleportation >= 0 && teleportation <= 100000) {
            if (seconds[teleportation] == -1 || seconds[teleportation] > seconds[current]) {
                seconds[teleportation] = seconds[current];
                q.push_front(teleportation);
            }
        }

        for (int move : walk_options) {
            if (move >= 0 && move <= 100000) {
                if (seconds[move] == -1 || seconds[move] > seconds[current] + 1) {
                    seconds[move] = seconds[current] + 1;
                    q.push_back(move);
                }
            }
        }
    }
}


int main() {
    cin>>n>>k;

    memset(seconds,-1,sizeof(seconds));
    q.push_front(n);
    seconds[n] = 0;

    bfs();
}