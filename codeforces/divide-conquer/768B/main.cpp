#include <iostream>
using namespace std;

/*
* https://codeforces.com/problemset/problem/768/B
*/

long long n, l, r;

long long solve(long long n, long long l, long long r) {
    if (n == 0) return 0;

    // if ���� ��ü
    // �� ��ü ���� ���� ���ϱ�
    long long length = 1;
    long long two = 1;
    while (n >= two) {
        two *= 2;
    }
    length = two - 1;
    long long mid = two / 2;

    /*
    1. ��� ������ ����: l~~r�� ó������ ���϶�
    2. l r  | n%2 | right
    3. l    |  r  | right
    4. l    | n%2 | r
    5. left | l==r| right
    6. left | l | r
    7. left | n%2 | l r
    */

    // ! ��Ͱ� ������ ���� �� �ƴ϶� ��ü ���̿� ���� ���� 1�� ������ ���� �� �־, �ٷ� ���������Ƿ� �ð� �ʰ� ���� �߿�
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