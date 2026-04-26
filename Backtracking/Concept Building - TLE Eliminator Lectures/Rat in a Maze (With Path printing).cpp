#include <bits/stdc++.h>
using namespace std;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
string dir = "RDLU";

bool isValid(int i, int j, int n, int m, vector<vector<int>> &arr) {
    return (i >= 0 && j >= 0 && i < n && j < m && arr[i][j] == 0);
}

void generate(int i, int j, int n, int m, vector<vector<int>> &arr, string &path) {
    if (i == n - 1 && j == m - 1) {
        cout << path << endl;
        return;
    }

    arr[i][j] = 1;

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if (isValid(ni, nj, n, m, arr)) {
            path.push_back(dir[k]);
            generate(ni, nj, n, m, arr, path);
            path.pop_back();
        }
    }

    arr[i][j] = 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    string path = "";
    generate(0, 0, n, m, arr, path);

    return 0;
}
