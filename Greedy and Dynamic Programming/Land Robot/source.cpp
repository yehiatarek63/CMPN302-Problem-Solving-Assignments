#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<climits>

long long LandRobot(vector<vector<long long>>& grid, long long x, long long y, long long m, long long n, vector<vector<long long>>& dp) {
    if (x == m && y == n) {
        return grid[x][y];
    }

    if (x >= m + 1 || y >= n + 1) {
        return LLONG_MIN;
    }
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    return dp[x][y] = grid[x][y] + max(LandRobot(grid, x + 1, y, m, n, dp), max(LandRobot(grid, x, y + 1, m, n, dp), LandRobot(grid, x + 1, y + 1, m, n, dp)));

}






int main() {

    long long x, y;
    long long z;
    cin >> x >> y;
    vector<vector<long long>> grid(x, vector<long long>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> z;
            grid[i][j] = z;
        }
    }
    vector<vector<long long>> dp(x + 1, vector<long long>(y + 1, -1));
    cout << LandRobot(grid, 0, 0, x - 1, y - 1, dp);



    return 0;
}
