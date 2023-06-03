#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>


void zerosumcells(int**digits, vector<int> &seq, int i, int j, int n, int m, vector<int>&maxseq) {
    if (i==n && j==m-1) {
        if (seq.size() > maxseq.size())
        {
            if (accumulate(seq.begin(), seq.end(), 0) == 0) {
                set<int>mySet(seq.begin(), seq.end());
                if (mySet.size() == seq.size()) {
                    maxseq = seq;
                }
            }
        }
    }
    else {
        if (i + 1 > n) {
            j++;
            i = 0;
        }
        zerosumcells(digits, seq, i + 1, j, n, m, maxseq);
        seq.push_back(digits[i][j]);
        if (i + 1 > n) {
            j++;
            i = 0;
        }
        zerosumcells(digits, seq, i + 1, j, n, m, maxseq);
        seq.pop_back();
    }
}


int main() {
    int x, y;
    cin >> x >> y;
    vector<int> seq;
    vector<int>maxseq;
    int i = 0;
    int j = 0;
    int** mat = new int*[x];
    for (int i = 0; i < x; i++) {
        mat[i] = new int[y];
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> mat[i][j];
        }
    }
    zerosumcells(mat, seq, i, j, x, y, maxseq);
    cout << maxseq.size();


    return 0;
}
