// https://www.acmicpc.net/problem/1927
#include <iostream>
using namespace std;

int tree[100'005];
int back = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        if (x == 0) { // pop
            if (back == 0) cout << 0 << '\n';
            else {
                cout << tree[1] << '\n';
                // 루트를 삭제 후 마지막을 넣는다
                tree[1] = tree[back--];
                // 만족할 때까지 내린다
                int cur = 1;
                int left = cur * 2;
                int right = cur * 2 + 1;
                // 왜 left <= back..? 그때는 right를 비교해버리면 안되지 않나?
                while (left <= back && (tree[cur] > tree[left] || tree[cur] > tree[right])) {
                    if (tree[left] <= tree[right]) {
                        int temp = tree[cur];
                        tree[cur] = tree[left];
                        tree[left] = temp;
                        cur = left;
                    } else {
                        int temp = tree[cur];
                        tree[cur] = tree[right];
                        tree[right] = temp;
                        cur = right;
                    }
                    left = cur * 2;
                    right = cur * 2 + 1;
                }
            }
        } else { // insert
            // 마지막에 삽입한다
            tree[++back] = x;
            int cur = back;
            int parent = back / 2;
            while (cur != 1 && tree[cur] < tree[parent]) {
                int temp = tree[cur];
                tree[cur] = tree[parent];
                tree[parent] = temp;
                cur = parent;
                parent = cur / 2;
            }
        }
    }

    return 0;
}