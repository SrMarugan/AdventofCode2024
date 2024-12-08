#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int findXMAS(vector<string> &matriz, int row, int col, const string &word) {
    int cont = 0;
    int n = matriz.size();
    int m = matriz[0].size();
    int len = word.length();

    int dRow[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dCol[] = {1, -1, 0, 0, 1, -1, 1, -1};

    for (int dir = 0; dir < 8; ++dir) {
        int r = row, c = col, i = 0;

        while (i < len && r >= 0 && r < n && c >= 0 && c < m && matriz[r][c] == word[i]) {
            r += dRow[dir];
            c += dCol[dir];
            ++i;
        }

        if (i == len) ++cont;
    }

    return cont;
}

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Can not open file." << endl;
        return 1;
    }

    vector<string> matriz;
    string line;

    while (getline(file, line)) {
        matriz.push_back(line);
    }
    file.close();

    const string word = "XMAS";
    int result = 0;

    for (int i = 0; i < matriz.size(); ++i) {
        for (int j = 0; j < matriz[i].size(); ++j) {
            if (matriz[i][j] == word[0]) {
                result += findXMAS(matriz, i, j, word);
            }
        }
    }

    cout << "Result: " << result << endl;

    return 0;
}
