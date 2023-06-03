#include<iostream>
using namespace std;
#include<vector>
#include<stack>


int N;



void dfsvisit(vector<vector<int>>& adjacencylist, int currentnode, int &step, vector<int>& processed, vector<pair<int, int>>& startfinish, vector<int>&topologicalsort) {
    step++;
    startfinish[currentnode].first = step;
    processed[currentnode] = 0;
    for (int i = 0; i < adjacencylist[currentnode].size(); i++) {
        if (processed[adjacencylist[currentnode][i]] == -1) {
            dfsvisit(adjacencylist, adjacencylist[currentnode][i], step, processed, startfinish, topologicalsort);
        }
    }
    processed[currentnode] = 1;
    step++;
    startfinish[currentnode].second = step;
    topologicalsort.push_back(currentnode);
}

void dfs(vector<vector<int>> &adjacencylist, int &step, vector<int>&processed, vector<pair<int,int>> &startfinish, vector<int>&topologicalsort) {
    for (int i = 0; i < adjacencylist.size(); i++) {
        if (processed[i] == -1) {
            dfsvisit(adjacencylist, i, step, processed, startfinish, topologicalsort);
        }
    }
}







int main() {
    cin >> N;
    int x, y;
    vector<vector<int>> adjacencylist(N);
    vector<int>processed(N, -1);
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (x != -1) {
            adjacencylist[x].push_back(i);
        }
        if (y != -1) {
            adjacencylist[y].push_back(i);
        }
    }
    vector<pair<int, int>> startfinish(N);
    int step = 0;
    vector<int> topologicalsort;
    dfs(adjacencylist, step, processed, startfinish, topologicalsort);
    for (int i = topologicalsort.size() - 1; i >= 0; i--) {
        cout << topologicalsort[i] << " ";
    }

    return 0;
}
