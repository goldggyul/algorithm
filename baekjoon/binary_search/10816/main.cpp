#include <iostream>
#include <algorithm>
using namespace std;

/*
https://www.acmicpc.net/problem/10816
*/
int n;
int card[500'001];
int m;

int lowerBound(int num) {
    int left = 0, right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (num <= card[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int upperBound(int num) {
    int left = 0, right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (card[mid] <= num) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }
    sort(card, card + n);

    cin >> m;
    int num;
    for (int i = 0; i < m; i++) {
        cin >> num;
        cout << upperBound(num) - lowerBound(num) << " ";
    }
    return 0;
}