#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<string>
#include<algorithm>

void LIS(const vector<int>& arr, vector<int>& seq, int index,
    vector<int>& maxSeq, int M, int &sum)
{
    if (index == arr.size())
    {
        if ((accumulate(seq.begin(),seq.end(),0)<=M))
        {
            if (accumulate(seq.begin(), seq.end(), 0) > accumulate(maxSeq.begin(), maxSeq.end(), 0)) {
                maxSeq = seq;
            }
        }
    }
    else
    {
        LIS(arr, seq, index + 1, maxSeq, M, sum); 
        seq.push_back(arr[index]); 
        LIS(arr, seq, index + 1, maxSeq, M, sum);
        seq.pop_back();
    }
}




int main() {

    int T, n, x;
    cin >> T;
    cin >> n;
    int sum;
    vector<int> seq;
    vector<int>maxSeq;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        cin >> x;
        V.push_back(x);
    }
    LIS(V, seq, 0, maxSeq, T, sum);
    cout << accumulate(maxSeq.begin(), maxSeq.end(), 0);

    return 0;
}
