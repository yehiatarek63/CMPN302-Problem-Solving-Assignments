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
    node* left;
    node* right;
};




int treeheight(node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 0;
    }
    int maxheight;
    int h1 = treeheight(root->left);
    int h2 = treeheight(root->right);
    if (h1 > h2) {
        return h1 + 1;
    }
    else {
        return h2 + 1;
    }
}

void calculatek(node* root, const int &L, vector<int> &level, int current) {
    if (root==nullptr) {
        return;
    }
    if (current == L) {
        level.push_back(root->data);
    }
    calculatek(root->left, L, level, current + 1);
    calculatek(root->right, L, level, current + 1);
}




void PINcode(node* root, const int&k, vector<pair<int,int>> & pairs, int current) {
    if (root == nullptr) {
        return;
    }
    if (current % k == 0) {
        pairs.push_back(make_pair(root->data, current));
    }
    PINcode(root->left, k, pairs, current + 1);
    PINcode(root->right, k, pairs, current + 1);
}

int main() {
    vector<int> v;
    vector<node*> vn;
    int n, x, E, y, z;
    char side;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < v.size(); i++) {
        node* T = new node();
        T->data = v[i];
        vn.push_back(T);
    }
    cin >> E;
    for (int i = 0; i < E; i++) {
        cin >> side >> y >> z;
        if (side == 'L') {
            vn[y]->left = vn[z];
        }
        else {
            vn[y]->right = vn[z];
        }
    }
    int height = treeheight(vn[0]);
    int actualheight = height + 1;
    int L = vn[0]->data % actualheight;
    vector<int>level;
    calculatek(vn[0], L, level, 0);
    auto it = min_element(level.begin(), level.end());
    int k = *it % actualheight;
    if (k == 0) {
        k = 1;
    }
    vector<string> sum;
    vector<pair<int, int>> pairs;
    PINcode(vn[0], k, pairs, 0);
    vector<bool> used(pairs.size(), false);
    sum.push_back(to_string(vn[0]->data));
    int sumt = 0;





    for (int i = 1; i < pairs.size(); i++) {
        sumt = 0;
        if (used[i] == false) {
            sumt = sumt + pairs[i].first;
        }
        else {
            continue;
        }
        for (int j = i + 1; j < pairs.size(); j++) {
            if ((pairs[i].second == pairs[j].second) && used[j] == false) {
                sumt = sumt + pairs[j].first;
                used[i] = true;
                used[j] = true;
            }
        }
        if (sumt != 0) {
            sum.push_back(to_string(sumt));
        }
    }




    for(int i = 0;i < sum.size(); i++){
        cout << sum[i];
    }
    return 0;
}
