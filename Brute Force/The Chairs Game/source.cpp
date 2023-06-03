#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>



void chairGames(const vector<string>& Names, int& sum, vector<string> &combinations, int index, vector<bool> &isused) {
    if (index == Names.size()) {
        bool flag = true;
        for (int j = 0; j < combinations.size()-1; j++) {
            if (combinations[j].back() == combinations[j + 1].front()) {
                flag = false;
            }
        }
        if (flag == true) {
            sum++;
        }
    }
    else {
        for (int i = 0; i < Names.size(); i++) {
            if (!isused[i]) {
                combinations.push_back(Names[i]);
                isused[i] = true;
                chairGames(Names, sum, combinations, index + 1, isused);
                combinations.pop_back();
                isused[i] = false;
            }

        }
    }
}


int main() {
    int x;
    int sum = 0;
    int index = 0;
    cin >> x;
    string y;
    vector<string> Names;
    vector<string> combinations;
    for (int i = 0; i < x; i++) {
        cin >> y;
        Names.push_back(y);
    }
    vector<bool> isused(Names.size(), false);
    chairGames(Names, sum, combinations, index, isused);
    cout << sum;


    return 0;
}
