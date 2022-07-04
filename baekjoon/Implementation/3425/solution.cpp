// https://www.acmicpc.net/problem/3425
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

/*
그냥 구현인데.. 문제를 잘 읽자.
오버플로우때문에 long long을 써준다.
다음 명령어 전에 엔터가 나온다! 그래서 cin.ignore필요
    - 또한 getline전에 엔터가 있으면 엔터가 들어가므로 cin.ignore()필요
    - cin마다 해주고... 마지막 엔터 다음에도 해줘야 함..
*/

bool checkStackSize(string op, stack<long long>& s) {
    if (op == "NUM") {
        return true;

    } else if (op == "POP" || op == "INV" || op == "DUP") {
        return s.size() >= 1;
    } else {
        return s.size() >= 2;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        vector<string> operators;
        vector<long long> operands;
        string oper = "";
        while (oper != "QUIT" && oper != "END") {
            getline(cin, oper);
            operators.push_back(oper);
        }
        if (oper == "QUIT") {
            break;
        }
        int n;
        cin >> n;
        while (n--) {
            long long num;
            cin >> num;
            cin.ignore();
            operands.push_back(num);
        }
        cin.ignore();

        for (long long operand : operands) {
            stack<long long> s;
            s.push(operand);
            bool isError = false;
            for (string oper : operators) {
                if (oper == "END") break;
                stringstream ss(oper);
                string op;
                ss >> op;
                if (!checkStackSize(op, s)) {
                    isError = true;
                    break;
                }
                if (op == "NUM") {
                    long long o;
                    ss >> o;
                    s.push(o);
                } else if (op == "POP") {
                    s.pop();
                } else if (op == "INV") {
                    long long t = s.top(); s.pop();
                    s.push(-t);
                } else if (op == "DUP") {
                    long long t = s.top();
                    s.push(t);
                } else if (op == "SWP") {
                    long long first = s.top(); s.pop();
                    long long second = s.top(); s.pop();
                    s.push(first);
                    s.push(second);
                } else {
                    long long first = s.top(); s.pop();
                    long long second = s.top(); s.pop();
                    bool isNegative = false;
                    long long result = 0;
                    if (op == "ADD") {
                        result = first + second;
                    } else if (op == "SUB") {
                        result = second - first;
                    } else if (op == "MUL") {
                        result = first * second;
                    } else {
                        if (first == 0) {
                            isError = true;
                            break;
                        }
                        if (op == "DIV") {
                            if ((first < 0 && second >= 0) || (first >= 0 && second < 0)) {
                                isNegative = true;
                            }
                            first = abs(first);
                            second = abs(second);
                            result = second / first;
                        } else if (op == "MOD") {
                            if (second < 0) isNegative = true;
                            first = abs(first);
                            second = abs(second);
                            result = second % first;
                        }
                    }
                    if (result > 1'000'000'000 || result < -1'000'000'000) {
                        isError = true;
                        break;
                    }
                    if (isNegative)
                        result *= -1;
                    s.push(result);
                }
            }
            if (isError || s.size() != 1) {
                cout << "ERROR" << '\n';
            } else {
                cout << s.top() << '\n';
            }
        }
        cout << '\n';
    }

}