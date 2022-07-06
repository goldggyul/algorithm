// https://www.acmicpc.net/problem/10828
#include <iostream>
#include <string>
using namespace std;

int arr[10'005];
int top = -1;

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
            cin >> num;
            arr[++top] = num;
        } else if (op == "pop") {
            if (top == -1) {
                cout << top << endl;
            } else {
                int topNum = arr[top--];
                cout << topNum << endl;
            }
        } else if (op == "size") {
            cout << top + 1 << endl;
        } else if (op == "empty") {
            if (top == -1) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (op == "top") {
            if (top == -1) {
                cout << top << endl;
            } else {
                cout << arr[top] << endl;
            }
        }
    }
    return 0;
}