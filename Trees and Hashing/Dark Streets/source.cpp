#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>


struct node {
    int data;
    vector<node*> connected;
    int dark;
    bool visited;
};

void darkstreets(node*root, int &count, int &N, int countdark) {
    int count1 = 0;
    for (int i = 0; i < root->connected.size(); i++) {
        bool flag = false;
        if (root->connected[i]->visited == true) {
            count1++;
        }
    }
    if (count1 == root->connected.size()) {
        if (root->dark == 1) {
            countdark = countdark + 1;
            root->visited = true;
        }
        if (countdark <= N) {
            count++;
        }
        root->visited = false;
        return;
    }
    if (root->dark == 1) {
        countdark = countdark + 1;
        root->visited = true;
    }
    else {
        root->visited = true;
        countdark = 0;
    }
    for (int i = 0; i < root->connected.size(); i++) {
        if (root->connected[i]->visited == false) {
            darkstreets(root->connected[i], count, N, countdark);
            
        }
    }
}


int main() {
    int N, M;
    cin >> N >> M;
    int d;
    int x, y;
    vector<int>dar;
    vector<node*>nodes;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < N; i++) {
        cin >> d;
        dar.push_back(d);
    }
    for (int i = 0; i < N-1; i++) {
        cin >> x >> y;
        if (y == 1) {
            int temp = x;
            x = y;
            y = temp;
        }
        pairs.push_back(make_pair(x,y));
    }
    for (int i = 1; i <= N; i++) {
        node* temp = new node;
        temp->data = i;
        temp->visited = false;
        nodes.push_back(temp);
    }
    for (int i = 0; i < pairs.size(); i++) {
        nodes[(pairs[i].first)-1]->connected.push_back(nodes[(pairs[i].second-1)]);
        nodes[(pairs[i].second) - 1]->connected.push_back(nodes[(pairs[i].first - 1)]);
    }
    for (int i = 0; i < dar.size(); i++) {
        nodes[i]->dark = dar[i];
    }
    vector<bool>visited(N + 1, false);
    int count = 0;
    bool valid = true;
    darkstreets(nodes[0], count, M, 0);
    cout << count;




    return 0;
}
