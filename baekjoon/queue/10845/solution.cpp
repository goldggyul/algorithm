// https://www.acmicpc.net/problem/10845
#include <iostream>
#include <string>
#define MAX 10'005
using namespace std;

int arr[10'005];
int front = 0;
int back = -1;
int cnt = 0;

int getNext(int index) {
    if (index + 1 == MAX) return 0;
    return index + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while (N--) {
        string op;
        cin >> op;
        if (op == "push") {
            int num;
            cin>>num;
            back = getNext(back);
            arr[back] = num;
            cnt++;
        } else if (op == "pop") {
            if (cnt == 0) cout << -1 << endl;
            else {
                int num = arr[front];
                front = getNext(front);
                cout << num << endl;
                cnt--;
            }
        } else if (op == "size") {
            cout << cnt << endl;
        } else if (op == "empty") {
            if (cnt == 0) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (op == "front") {
            if (cnt == 0) cout << -1 << endl;
            else cout << arr[front] << endl;
        } else if (op == "back") {
            if (cnt == 0) cout << -1 << endl;
            else cout << arr[back] << endl;
        }
    }
    return 0;
}