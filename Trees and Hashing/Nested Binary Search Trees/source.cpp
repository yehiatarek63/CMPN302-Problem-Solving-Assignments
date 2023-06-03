#include <iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<utility>
#include<string>

struct node {
    int data;
    int count;
    node* left;
    node* right;
    node* id;
};

void insert(node* root, node* newnode) {
    if (root->data == newnode->data) {
        insert(root->id, newnode->id);
    }
    if (newnode->data < root->data && root->left == nullptr) {
        root->left = newnode;
    }
    else if(newnode->data < root->data && root->left != nullptr) {
        insert(root->left, newnode);
    }
    if (newnode->data > root->data && root->right == nullptr) {
        root->right = newnode;
    }
    else if(newnode->data > root->data && root->right != nullptr) {
        insert(root->right, newnode);
    }
}

void searchsub(node* root, int dep, int id, int &count, int& found) {
    if (root == nullptr) {
        return;
    }
    if (root->data == id) {
        count++;
        found = 1;
    }
    else if (root->data > id) {
        count++;
        searchsub(root->left, dep, id, count, found);
    }
    else if (root->data < id) {
        count++;
        searchsub(root->right, dep, id, count, found);
    }
}
void search(node* root, int dep, int id, int &count, int &found) {
    if (root == nullptr) {
        return;
    }
    if (root->data == dep) {
        count++;
        searchsub(root->id, dep, id, count, found);
    }
    else if (root->data > dep) {
        count++;
        search(root->left, dep, id, count, found);
    }
    else if (root->data < dep) {
        count++;
        search(root->right, dep, id, count, found);
    }
}

int main() {
    int N, Q, x, y;
    cin >> N >> Q;
    vector<node*> v;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        node* T = new node();
        node* R = new node();
        R->data = y;
        T->data = x;
        T->id = R;
        v.push_back(T);
    }
    for (int i = 1; i < v.size(); i++) {
        insert(v[0], v[i]);
    }
    int count = 0;
    int found = 0;
    vector<pair<int, int>> result;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        count = 0;
        found = 0;
        search(v[0], x, y, count, found);
        result.push_back(make_pair(count, found));
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;

}
