//https://codeforces.com/problemset/problem/217/A
#include <iostream>
using namespace std;

int n; // 10^2
int x[105];
int y[105];
bool visited[105];

void search(int now) {
    visited[now] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (x[now] == x[i] || y[now] == y[i]))
            search(i);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int connectedCnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            search(i);
            connectedCnt++;
        }
    }
    cout<< connectedCnt - 1<<endl;
    return 0;
}