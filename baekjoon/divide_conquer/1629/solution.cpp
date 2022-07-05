// https://www.acmicpc.net/problem/1629
#include<iostream>
#define ll long long
using namespace std;

/*
⭐️ 분할 정복을 이용한 거듭제곱
a를 N번 곱한 수를 구한다면? 시간복잡도는 O(N)이다.
이 문제의 경우 N이 21억이므로 1초 내에 구할 수가 없다.
따라서 분할 정복을 이용하여 log(N)만에 구하자.
*/

ll c;

ll mpow(ll a, ll b) {
    if (b == 1) return a % c;
    ll mid = b / 2;
    if (b % 2 == 0) {
        return (mpow(a, mid) * mpow(a, mid))%c;
    } else {
        return ((mpow(a, mid) * mpow(a, mid)%c) * a)%c;
    }
}

int main() {
    ll a, b;
    cin >> a >> b >> c;
    cout << mpow(a,b)<<endl;
    return 0;
}