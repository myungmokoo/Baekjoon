//#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

string vocab;
queue<string> q;

int n;

bool isMut(string s) {
    int f = 0, b = 0;
    int capitalized_front = 'A';
    int capitalized_back = 'Z';

    set<char> vocabs;

    for (char c : s) {
        if (c < capitalized_front || c > capitalized_back) {
            return false;
        }
        vocabs.insert(c);
    }

    if (vocabs.size() != s.size()) return false;

    for (int i=0; i<s.size()-1; i++) {
        char front = s[i];
        char back  = s[i+1];

        if (front > back) f++;
        else if (front < back) b++;
    }

    return abs(f - b) <= 1;
}

int main() {
    cin>>n>>vocab;
    if (isMut(vocab)) cout<<n<<"\n"<<vocab;
    else {
        q.push(vocab);

        while (!q.empty()) {
            bool visited[26] = { false };
            string current = q.front();
            q.pop();

            if (isMut(current)) {
                cout<<current.size()<<"\n"<<current;
                return 0;
            }

            for (char c : current) {
                visited[c - 'A'] = true;
            }

            for (int i = 0; i < 26; i++) {
                if (!visited[i]) {
                    char next = 'A' + i;
                    q.push(current + next);
                }
            }
        }
    }
}