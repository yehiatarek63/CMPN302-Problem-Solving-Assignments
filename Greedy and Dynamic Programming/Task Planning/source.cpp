#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool Compare(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) {
        return true;
    }
    else {
        return false;
    }
}



int main() {
    int N, x;
    long long y;
    cin >> N;
    vector<int>di;
    vector<long long> pi;
    vector<pair<int, long long>> timetable;
    for (int i = 0; i < N; i++) {
        cin >> x;
        di.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        cin >> y;
        pi.push_back(y);
    }
    for (int i = 0; i < N; i++) {
        timetable.push_back(make_pair(di[i], pi[i]));
    }
    sort(timetable.begin(), timetable.end(), Compare);
    vector<long long> answer(N + 1, -1);
    for (int i = 0; i < N; i++) {
        for (int j = timetable[i].first - 1; j >= 0; j--) {
            if (answer[j] == -1) {
                answer[j] = timetable[i].second;
                break;
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] != -1) {
            sum = sum + answer[i];
        }
    }
    long long totalsum = 0;
    for (int i = 0; i < timetable.size(); i++) {
        totalsum = totalsum + timetable[i].second;
    }
    long long out = totalsum - sum;
    cout << out;

    return 0;
}
