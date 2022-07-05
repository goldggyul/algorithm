// https://www.acmicpc.net/problem/2749
#include <iostream>
#define mod 1000000
#define ll long long
using namespace std;

long long n;

/*
|Fn+1| = |1 1| * | Fn |
| Fn |   |1 0|   |Fn-1|
따라서
|Fn+1 Fn | = |1 1|^n
| Fn Fn-1|   |1 0|   

다만 그대로 n번 곱하면 시간초과가 나므로
분할정복을 이용해서 n번 곱해주자
*/

struct mat {
    ll arr[2][2]= {{0,0}, {0,0}};

    // 행렬곱
    mat operator* (const mat& other) {
        mat res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) { // 왼쪽에 곱해지는 행렬의 열 수
                    res.arr[i][j] = (res.arr[i][j] + arr[i][k] * other.arr[k][j]) % mod;
                }
            }
        }
        return res;
    }
};

int main() {
    cin >> n;

    // 1 1
    // 1 0
    mat s;
    s.arr[0][0] = 1; s.arr[0][1] = 1; s.arr[1][0] = 1; // 

    // 초기 res = 1 즉 단위행렬
    // 1 0
    // 0 1
    mat res;
    res.arr[0][0] = 1; res.arr[1][0] = 1;
    // 분할 정복을 이용한 거듭제곱 - 재귀 대신 반복문 이용 
    while (n) {
        if (n % 2 == 1) // 홀수일 때 나머지 하나를 더 곱해준다
            res = res * s;
        s = s * s;
        n /= 2;
    }
    cout << res.arr[0][1] << endl;
    return 0;
}