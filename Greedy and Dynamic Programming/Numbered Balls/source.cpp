#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<climits>
int V, B;






int MinBalls(const vector<int>& balls, int V, vector<int>& dp) {
    if (V < 0) {
        return INT_MAX;
    }
    if (dp[V] < 0) {
        if (V == 0) {
            return dp[V] = 0;
        }
        int count = 0;
        vector<int> ways;
        for (int i = 0; i < balls.size(); i++) {
            count = MinBalls(balls, V - balls[i], dp);
            if (count != INT_MAX) {
                count = count + 1;
            }
            ways.push_back(count);
        }
        sort(ways.begin(), ways.end());
        dp[V] = ways[0];
    }
    return dp[V];
}






int main() {
    int x;
    cin >> V >> B;
    vector<int> balls;
    for (int i = 0; i < B; i++) {
        cin >> x;
        balls.push_back(x);
    }
    vector<int> dp(V + 1, -1);
    int ans = MinBalls(balls, V, dp);
    if (ans == INT_MAX) {
        cout << "no solution";
    }
    else {
        cout << ans;
    }



    return 0;
}
