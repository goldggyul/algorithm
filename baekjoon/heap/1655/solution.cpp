// https://www.acmicpc.net/problem/1655
#include <iostream>
#include <queue>
using namespace std;

/*
N이 10만이고, 0.1초에 해결해야 한다.
N^2에 탐색할 수 없다는 걸 알 수 있고,
NlogN에 해결해야 함을 알 수 있다.

그럼 logN을 위해 우선순위 큐 활용 방안을 생각해보자.
유지해야하는 건 중간값이다.
따라서 중간값의 왼쪽 집합, 오른쪽 집합을 유지하면서
왼쪽 집합 개수 == 오른쪽 집합 개수 (+1) 관계를 유지하면서
오른쪽 집합 개수가 최대 1개까지만 되게 하자
    -> 짝수개의 경우 중간 값 두개 중 작은 값을 출력해야하므로
       오른쪽 집합 개수를 더 많게 유지해야 한다.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int mid;
    cin >> N >> mid;
    cout << mid << '\n'; // 맨 처음값은 그냥 출력
    priority_queue<int> A;
    priority_queue<int, vector<int>, greater<int>> B;
    while (--N) {
        int num;
        cin >> num;
        if (num < mid) A.push(num);
        else B.push(num);

        if (A.size() > B.size()) { // 왼쪽에서 꺼내야 하는 경우
            B.push(mid);
            mid = A.top(); A.pop();
        } else if (B.size()> A.size()+1) { // 오른쪽에서 꺼내야 하는 경우
            A.push(mid);
            mid = B.top(); B.pop();
        }
        cout << mid << '\n';
    }
    return 0;
}