#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

bool check(vector<vector<char>> &matrix, char *word, int a, int b);

int main(int argc, char *argv[]) {
    int x, y,a,b;
    char c;
    char str[100];

    // cin >> str;
    // cin >> a;
    // cin >> b;
    cin >> x;
    cin >> y;

    a = stoi (argv[2]);
    b = stoi(argv[3]);

    vector<vector<char>> vect(x, vector<char>(y)); 

   
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> c;
            vect[i][j] = c;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    if (check(vect, argv[1], a, b)) {
        cout << "Word found!" << endl;
    } else {
        cout << "Word not found!" << endl;
    }

    return 0;
}

bool check(vector<vector<char>> &matrix, char *word, int a, int b) {
    int wordLength = strlen(word);

    // Check if the word fits horizontally starting from (x, y)
    if (b + wordLength <= matrix[0].size()) {
        bool match = true;
        for (int i = 0; i < wordLength; i++) {
            if (matrix[a][b + i] != word[i]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }

    // Check if the word fits vertically starting from (x, y)
    if (a + wordLength <= matrix.size()) {
        bool match = true;
        for (int i = 0; i < wordLength; i++) {
            if (matrix[a + i][b] != word[i]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }

    return false;
}

