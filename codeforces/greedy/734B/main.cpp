#include <iostream>
using namespace std;

/* Greedy!
* https://codeforces.com/problemset/problem/734/B
* 56 모으기, 3모으기
* 그리고 256을 가능한 많이 만들고 남은 걸로 32를 만들어주자
*/

int main() {
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;

    int k56 = min(k5, k6);
    int k256 = min(k56, k2);
    k2 -= k256;
    int k32 = min(k2, k3);

    long long result = 0;
    result += 256 * k256;
    result += 32 * k32;
    cout << result << endl;

    return 0;
}