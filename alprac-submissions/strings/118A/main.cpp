#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        char w = word[i];
        if (w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u' || w == 'y');
        else if (w == 'A' || w == 'E' || w == 'I' || w == 'O' || w == 'U' || w == 'Y');
        else {
            cout << ".";
            if (w >= 'A' && w <= 'Z') {
                cout << char(w + ('a' - 'A'));
            } else {
                cout << w;
            }
        }
    }
    cout << endl;

    return 0;
}