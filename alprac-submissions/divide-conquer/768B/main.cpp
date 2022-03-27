#include <iostream>
using namespace std;

/*
* https://codeforces.com/problemset/problem/768/B
*/

long long n, l, r;

long long solve(long long n, long long l, long long r) {
    if (n == 0) return 0;

    // if 내가 전체
    // 내 전체 길이 먼저 구하기
    long long length = 1;
    long long two = 1;
    while (n >= two) {
        two *= 2;
    }
    length = two - 1;
    long long mid = two / 2;

    /*
    1. 재귀 끝나는 시점: l~~r이 처음부터 끝일때
    2. l r  | n%2 | right
    3. l    |  r  | right
    4. l    | n%2 | r
    5. left | l==r| right
    6. left | l | r
    7. left | n%2 | l r
    */

    // ! 재귀가 끝까지 들어가는 게 아니라 전체 길이와 같을 때의 1의 개수는 구할 수 있어서, 바로 빠져나오므로 시간 초과 없음 중요
    if (l == 1 && r == length) return n;
    if (r < mid) return solve(n / 2, l, r);
    if (l < mid && r == mid) return solve(n / 2, l, mid - 1) + n % 2;
    if (l < mid && r > mid) return solve(n / 2, l, mid - 1) + n % 2 + solve(n / 2, 1, r - mid);
    if (l == mid && r == mid) return n % 2;
    if (l == mid && r > mid) return n % 2 + solve(n / 2, 1, r - mid);
    if (l > mid) return solve(n / 2, l - mid, r - mid);

    return 0;
}

int main() {
    cin >> n >> l >> r;
    cout << solve(n, l, r) << endl;
    return 0;
}