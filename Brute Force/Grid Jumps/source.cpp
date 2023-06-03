#include<iostream>
using namespace std;
#include <vector>
#include<climits>







void findPath(int** mat, bool** used, int n, int i, int j, int& maxcost, vector<int>& minpath, int currcost, vector<int>& currpath) {
    used[i][j] = true;
    currcost = currcost + mat[i][j];
    currpath.push_back(mat[i][j]);
    if (i == n-1 && j == 0) {
        if (currcost > maxcost) {
            maxcost = currcost;
            minpath = currpath;
        }
    }
    else {
        if (i - 1 >= 0 && used[i-1][j] == false) {
            findPath(mat, used, n, i-1, j, maxcost, minpath, currcost, currpath);
        }
        if (i + 1 < n && used[i+1][j] == false) {
            findPath(mat, used, n, i+1, j, maxcost, minpath, currcost, currpath);
        }
        if (i - 1 >= 0 && j - 1 >= 0 && used[i - 1][j - 1] == false) {
            findPath(mat, used, n, i - 1, j - 1, maxcost, minpath, currcost, currpath);
        }
        if (i + 1 < n && j + 1 < n && used[i + 1][j + 1] == false) {
            findPath(mat, used, n, i + 1, j + 1, maxcost, minpath, currcost, currpath);
        }
        if (j - 1 >= 0 && i + 1 < n && used[i + 1][j - 1] == false) {
            findPath(mat, used, n, i + 1, j - 1, maxcost, minpath, currcost, currpath);
        }
        if (j + 1 < n && i - 1 >= 0 && used[i - 1][j + 1] == false) {
            findPath(mat, used, n, i - 1, j + 1, maxcost, minpath, currcost, currpath);
        }

    }
    used[i][j] = false;
    currpath.pop_back();
}


int main() {
    int** mat;
    mat = new int* [3];
    for (int i = 0; i < 3; i++) {
        mat[i] = new int[3];
    }
    bool** used;
    used = new bool* [3];
    for (int i = 0; i < 3; i++) {
        used[i] = new bool[3];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];
        }
    }


    used[0][0] = false;
    used[0][1] = false;
    used[0][2] = false;
    used[1][0] = false;
    used[1][1] = false;
    used[1][2] = false;
    used[2][0] = false;
    used[2][1] = false;
    used[2][2] = false;

    int maxcost, currcost;
    currcost = INT_MIN;
    maxcost = INT_MIN;
    vector<int> minpath;
    vector<int> currpath;
    int sum = 0;
    findPath(mat, used, 3, 0, 0, maxcost, minpath, 0, currpath);
    for (int i = 0; i < minpath.size(); i++) {
        sum = sum + minpath[i];
    }
    cout << sum;

    return 0;
}
