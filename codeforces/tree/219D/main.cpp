#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://codeforces.com/problemset/problem/219/D
*/

int n;
struct Node {
    int pt;
    int inverseSum; // inverse �ž��ϴ� road�� ���� �� (inverseCnt�� ��)
    vector<int> adj;
    vector<int> inverseCnt;
    vector<bool> isInverted;
};
Node tree[200'001];

int dfs(int s, int pt) {
    Node& cur = tree[s];
    cur.pt = pt;
    for (int i = 0; i < cur.adj.size(); i++) {
        if (cur.adj[i] != cur.pt) {
            cur.inverseCnt[i] = dfs(cur.adj[i], s) + cur.isInverted[i];
            cur.inverseSum += cur.inverseCnt[i];
        }
    }
    return cur.inverseSum;
}

void reverseDfs(int s) {
    Node& cur = tree[s];
    // �θ𿡼����� �ٸ� ��������� �Ÿ� �� �߰� ����
    for (int i = 0; i < cur.adj.size(); i++) {
        if (cur.adj[i] == cur.pt && cur.inverseCnt[i] == -1) {
            cur.inverseCnt[i] = (tree[cur.pt].inverseSum - cur.inverseSum - (1 - cur.isInverted[i])) + cur.isInverted[i];
            cur.inverseSum += cur.inverseCnt[i];
        }
    }
    // �ڽ� ���� Ž��
    for (int i = 0; i < cur.adj.size(); i++) {
        if (cur.adj[i] != cur.pt) {
            reverseDfs(cur.adj[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int s, t;
        cin >> s >> t;
        tree[s].adj.push_back(t);
        tree[s].isInverted.push_back(false);
        tree[s].inverseCnt.push_back(-1);

        tree[t].adj.push_back(s);
        tree[t].isInverted.push_back(true);
        tree[t].inverseCnt.push_back(-1);
    }

    // 1�� ��� ��Ʈ�� ���� && �Ʒ��� �������鼭 ����
    dfs(1, 0);
    // ���� �ö󰡸鼭 ����
    reverseDfs(1);

    // �ּڰ� ã��
    int m = tree[1].inverseSum;
    for (int i = 1; i <= n; i++) {
        m = min(m, tree[i].inverseSum);
    }
    cout << m << endl;
    // �ּڰ��� ��ġ�ϴ� �͵� ���
    for (int i = 1; i <= n; i++) {
        if (m == tree[i].inverseSum) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}