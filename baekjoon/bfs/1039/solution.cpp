/*
분류가 BFS로 되어있지만 DFS로도 풀린다(고 한다)

당연히 쌩으로 BFS를 돌리면 메모리 초과가 난다
그래서 각 숫자 별로 경로를 저장하는 건가? 생각했는데 그러면 탐색 중인 숫자에 도착할 수도 있고.. 그 경로중에
뭘 선택할 지 알 수 없으니까 이건 아닌 거 같았다

그럼 솔루션은 뭐냐면
해당 카운트에서 이미 방문 예정인(그러니까 이미 큐에 넣은) 수를
또 탐색을 안하는 것으로 가지치기를 하는 것이다.
    - 탐색하지 않아도 될 경우
    - 이미 탐색이 끝난 경우
    - 이미 탐색한 곳을 다시 탐색할 때 (중복탐색)
따라서 이 문제 경우엔 이미 탐색한 곳을 다시 탐색할 때 <-- 얘를 계속 탐색해서 메모리 초과가 났던 것
따라서 카운트 별로 set을 만들어서 이미 탐색한 것인지 체크했다.

비록 수가 같아도 count가 다르다면 다른 수니까 모두 그게 노드의 정보가 되니까..
같은 노드는 탐색하지 말자!
*/

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

string num;
int K;

struct node {
    int cnt;
    string n;
};
queue<node> q;
set<string> pushed[12];

int main() {
    cin >> num;
    cin >> K;
    q.push({ 0, num });
    int mx = 0;
    int mxCnt = 0;
    while (!q.empty()) {
        node cur = q.front(); q.pop();
        mxCnt = max(mxCnt, cur.cnt);
        if (pushed[cur.cnt].find(cur.n) != pushed[cur.cnt].end()) {
            continue;
        }
        pushed[cur.cnt].insert(cur.n);
        
        if (cur.cnt == K) {
            mx = max(mx, stoi(cur.n));
            continue;
        }
        for (int i = 0; i < cur.n.size(); i++) {
            for (int j = i + 1; j < cur.n.size(); j++) {
                if (i == 0 && cur.n[j] == '0') continue;
                string swapped = cur.n;
                char temp = swapped[i];
                swapped[i] = swapped[j];
                swapped[j] = temp;
                q.push({ cur.cnt + 1, swapped });
            }
        }
    }
    if (mxCnt < K)
        cout << -1 << endl;
    else
        cout << mx << endl;
}