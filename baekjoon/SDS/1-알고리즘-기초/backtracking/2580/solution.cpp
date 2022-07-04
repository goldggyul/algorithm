// https://www.acmicpc.net/problem/2580
#include <iostream>
using namespace std;

int sudoku[12][12];
bool row[10][10];
bool col[10][10];
bool square[10][10];

int emptyCnt = 0;
int ex[90];
int ey[90];

bool searchDone = false;

void dfs(int emptyNum) {
    if (searchDone) {
        return;
    }
    if (emptyNum == emptyCnt) {
        searchDone = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    int curRow = ex[emptyNum];
    int curCol = ey[emptyNum];
    for (int i = 1; i <= 9; i++) {
        if (!row[curRow][i] && !col[curCol][i] && !square[(curRow / 3) * 3 + curCol / 3][i]) {
            row[curRow][i] = true;
            col[curCol][i] = true;
            square[(curRow / 3) * 3 + curCol / 3][i] = true;
            sudoku[curRow][curCol] = i;
            dfs(emptyNum + 1);
            row[curRow][i] = false;
            col[curCol][i] = false;
            square[(curRow / 3) * 3 + curCol / 3][i] = false;
            sudoku[curRow][curCol] = 0;
        }
    }
}

int main() {
    int num;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> num;
            if (num == 0) {
                ex[emptyCnt] = i;
                ey[emptyCnt] = j;
                emptyCnt++;
            } else {
                row[i][num] = true;
                col[j][num] = true;
                square[(i/3)*3 + j/3][num] = true;
            }
            sudoku[i][j] = num;
        }
    }

    dfs(0);

    return 0;
}