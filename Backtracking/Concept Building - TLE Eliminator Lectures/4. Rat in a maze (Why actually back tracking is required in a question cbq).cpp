#include <bits/stdc++.h>
using namespace std;

/*
Problem: Rat in a Maze

You are given an n x m maze where:
- 0 means the cell is free
- 1 means the cell is blocked

A rat starts from the top-left cell (0,0)
and wants to reach the bottom-right cell (n-1,m-1).

The rat can move in 4 directions:
- Right
- Down
- Left
- Up

Task:
Count total number of possible paths from start to destination.
A path is valid only if:
- It stays inside the maze
- It does not go through blocked cells
- It does not visit the same cell again in the same path
*/

/*
Why Backtracking is Required

Since the rat can move in 4 directions, it may revisit
the same cell again and again, causing infinite loops.

Example:
A -> B -> C
     <-    

So while exploring one path, we mark the current cell
as visited so the rat does not come back to it.

After exploring that path, we unmark it (backtrack)
so that the same cell can be used in some other valid path.

This is called backtracking:
- Mark while going forward
- Unmark while returning back
*/

int countPaths(int i, int j, int n, int m, vector<vector<int>> &arr) {
    // Invalid cell: out of bounds or blocked/visited
    if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == 1) {
        return 0;
    }

    // Destination reached
    if (i == n - 1 && j == m - 1) {
        return 1;
    }

    // Mark current cell as visited
    arr[i][j] = 1;

    // Explore all 4 directions
    int right = countPaths(i, j + 1, n, m, arr);
    int down  = countPaths(i + 1, j, n, m, arr);
    int left  = countPaths(i, j - 1, n, m, arr);
    int up    = countPaths(i - 1, j, n, m, arr);

    // Backtrack: unmark current cell
    arr[i][j] = 0;

    return right + down + left + up;
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
