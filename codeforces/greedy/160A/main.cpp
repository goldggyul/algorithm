#include <iostream>
#include <algorithm>
using namespace std;

/*
* Greedy!
* https://codeforces.com/problemset/problem/160/A
*/
int main() {
    int n;
    int arr[100];
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n, greater<int>()); // 내림차순으로 정렬

    int result = 0;
    int myValue = 0;
    for (int i = 0; i < n; i++) {
        if (myValue > sum) break;
        myValue += arr[i];
        sum -= arr[i];
        result++;
    }
    cout << result << endl;

    return 0;
}