#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include<utility>

int BookShelves(const vector<int> V, int D, int M) {
    unordered_map<int, int> umap;
    int count = 0;
    int index;
    int count2 = 0;
    unordered_map<int, pair<int, vector<int>>>umap2;
    if (M == 3) {
        for (int i = 0; i < V.size(); i++) {
            umap2[V[i]].first = umap2[V[i]].first + 1;
            umap2[V[i]].second.push_back(i);
        }
        for (int i = 0; i < V.size(); i++) {
            int value3 = V[i] + D;
            auto it3 = umap2.find(V[i]);
            auto it4 = umap2.find(value3);
            if (it4 != umap2.end()) {
                auto it5 = umap2.find(it4->first + D);
                if (it5 != umap2.end()) {
                    for (int k = 0; k < umap2[it4->first].first; k++) {
                        for (int j = 0; j < umap2[it5->first].first; j++) {
                            if (umap2[it5->first].second[j] > umap2[it4->first].second[k]) {
                                count++;
                            }
                        }
                    }
                }
            }
            it3->second.first = it3->second.first - 1;
            it3->second.second.erase(it3->second.second.begin());
            if (it3->second.first == 0) {
                umap2.erase(it3);
            }

        }
        
    }

    if (M == 2) {
        for (int i = 0; i < V.size(); i++) {
            umap[V[i]] = umap[V[i]] + 1;
        }
        for (int i = 0; i < V.size(); i++) {
            int value = V[i] + D;
            auto it2 = umap.find(V[i]);
            auto it = umap.find(value);
            if (it != umap.end()) {
                count = count + it->second;
            }
            it2->second = it2->second - 1;
            if (it2->second == 0) {
                umap.erase(it2);
            }
        }
    }

    return count;
}





int main() {
    vector<int> V;
    int n, D, M, x;
    cin >> n >> D >> M;
    for (int i = 0; i < n; i++) {
        cin >> x;
        V.push_back(x);
    }
    int count = BookShelves(V, D, M);
    cout << count;



    return 0;
}
