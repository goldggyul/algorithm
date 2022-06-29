#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<int>> cctv[6]; // 1~5

pair<int, int> dir[4] = { {0,1}, {1, 0}, {0, -1}, {-1, 0} };

int n, m;
int room[10][10];

vector<int> kinds; // cctv 종류
vector<pair<int, int>> coor; // 좌표

int minSize = 100;

void dfs(int num) {
    if (num >= kinds.size()) { // cctv 확인 완료
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (room[i][j] == 0) {
                    ans++;
                }
            }
        }
        minSize = min(minSize, ans);
        return;
    }

    vector<vector<int>>& cur = cctv[kinds[num]];
    for (int i = 0; i < cur.size(); i++) {
        vector<pair<int, int>> currentAdded;
        for (int j = 0; j < cur[i].size(); j++) {
            pair<int, int> check = coor[num];
            while (room[check.first][check.second] != 6) {
                if (room[check.first][check.second] == 0) {
                    room[check.first][check.second] = 7;
                    // `지금 바뀐 것`만 rollback하기 위해 지금 바꾸는 것들 저장해둔다
                    currentAdded.push_back({ check.first, check.second });
                }
                check.first += dir[cur[i][j]].first;
                check.second += dir[cur[i][j]].second;
            }
        }
        dfs(num + 1);
        // 다시 rollback
        for (int j = 0; j < cur[i].size(); j++) {
            while (!currentAdded.empty()) {
                room[currentAdded.back().first][currentAdded.back().second] = 0;
                currentAdded.pop_back();
            }
        }
    }
}

int main() {
    cctv[1].push_back({ 0 });
    cctv[1].push_back({ 1 });
    cctv[1].push_back({ 2 });
    cctv[1].push_back({ 3 });

    cctv[2].push_back({ 0, 2 });
    cctv[2].push_back({ 1, 3 });

    cctv[3].push_back({ 3, 0 });
    cctv[3].push_back({ 0, 1 });
    cctv[3].push_back({ 1, 2 });
    cctv[3].push_back({ 2, 3 });

    cctv[4].push_back({ 0,2,3 });
    cctv[4].push_back({ 0,1,3 });
    cctv[4].push_back({ 0,1,2 });
    cctv[4].push_back({ 1,2,3 });

    cctv[5].push_back({ 0,1,2,3 });

    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
                room[i][j] = 6; // padding 채워주기
            else {
                cin >> room[i][j];
                // CCTV 일 경우
                if (room[i][j] >= 1 && room[i][j] <= 5) {
                    kinds.push_back(room[i][j]);
                    coor.push_back({ i, j });
                }
            }
        }
    }

    dfs(0);

    cout << minSize << endl;

    return 0;
}