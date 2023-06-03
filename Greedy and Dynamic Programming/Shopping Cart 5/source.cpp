#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<climits>



int shoppingcart(const vector<vector<int>>&items, int index, int remainder, vector<vector<int>>&dp) {
    if (remainder < 0) {
        return INT_MAX;
    }
    if (dp[index][remainder] < 0) {
        if (index == items.size()) {
            return remainder;
        }
        vector<int> temp;
        for (int i = 0; i < items[index].size(); i++) {
            int choice = shoppingcart(items, index + 1, remainder - items[index][i], dp);
            temp.push_back(choice);
        }
        dp[index][remainder] = *min_element(temp.begin(), temp.end());
    }
    return dp[index][remainder];
}

int main() {
    int B, T;
    cin >> B >> T;
    vector<vector<int>> items(T);
    int x, y;
    for (int i = 0; i < T; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) {
            cin >> y;
            items[i].push_back(y);
        }
    }
    vector<vector<int>> dp(items.size() + 1,vector<int>(B + 1, -1));
    int rem = shoppingcart(items, 0, B, dp);
    if (rem == INT_MAX) {
        cout << "no solution";
    }
    else {
        cout << B - rem;
    }


    return 0;
}
