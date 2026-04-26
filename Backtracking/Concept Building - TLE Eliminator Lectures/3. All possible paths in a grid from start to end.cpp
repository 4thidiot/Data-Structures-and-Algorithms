#include <bits/stdc++.h>
using namespace std;

// Count number of ways to reach bottom-right
// from (i, j) by moving only right or down
int countPaths(int i, int j, int n, int m, vector<vector<int>> &arr) {
    // Out of bounds OR blocked cell
    if (i >= n || j >= m || arr[i][j] == 1) {
        return 0;
    }

    // Reached destination
    if (i == n - 1 && j == m - 1) {
        return 1;
    }

    // Move right
    int right = countPaths(i, j + 1, n, m, arr);

    // Move down
    int down = countPaths(i + 1, j, n, m, arr);

    return right + down;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << countPaths(0, 0, n, m, arr) << endl;
}

int main() {
    solve();
    return 0;
}
