#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include <climits>

long long N;
vector<long long> health;
vector<long long>firepower;

bool Compare(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    if (a.first != b.first) {
        return (a.first < b.first);
    }
    else {
        return (a.second < b.second);
    }
}

pair<long long, long long> BattleShips2(long long health, vector<pair<long long, long long>> &dp) {
    if (health < 0) {
        return make_pair(LLONG_MAX, LLONG_MAX);
    }
    if (dp[health].first == -1 && dp[health].first == -1) {
        if (health == 0) {
            return dp[health] = make_pair(0, 0);
        }
        if (health < *min_element(firepower.begin(), firepower.end())) {
            return dp[health] = make_pair(health, 0);
        }
        pair<long long, long long> temp;
        vector<pair<long long, long long>> comparisons;
        for (int i = 0; i < firepower.size(); i++) {
            if (firepower[i] == 0) {
                continue;
            }
            temp = BattleShips2(health - firepower[i], dp);
            comparisons.push_back(temp);
        }
        sort(comparisons.begin(), comparisons.end(), Compare);
        comparisons[0].second = comparisons[0].second + 1;
        dp[health] = comparisons[0];
    }
    return dp[health];
}



int main() {
    cin >> N;
    long long x, M;
    for (int i = 0; i < N; i++) {
        cin >> x;
        health.push_back(x);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x;
        if (x != 0) {
            firepower.push_back(x);
        }
    }
    if (!firepower.empty()) {
        vector<pair<long long, long long>> dp(*max_element(health.begin(), health.end()) + 1, { -1, -1 });
        pair<long long, long long> out;
        for (int i = 0; i < N; i++) {
            out = BattleShips2(health[i], dp);
            cout << out.first << " " << out.second << endl;
        }
    }
    else {
        for (int i = 0; i < health.size(); i++) {
            cout << health[i] << " " << 0 << endl;
        }
    }

    return 0;
}
