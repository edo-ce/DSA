#include "bst.hpp"
#include <cassert>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node{
    int key;
    Node* father;
    Node* left;
    Node* right;
    explicit Node(int val) {
        key = val;
        father = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

PNode createNode(int val) {
    return new Node(val);
}

BST::BST() {
    r = nullptr;
}

PNode BST::buildAux(const std::vector<int> &v, int inf, int sup, PNode father) {
    if (inf > sup) {
        return nullptr;
    } else {
        int mid = floor((inf + sup) / 2);
        PNode u = createNode(v[mid]);
        u->father = father;
        u->left = buildAux(v, inf, mid-1, u);
        u->right = buildAux(v, mid+1, sup, u);
        return u;
    }
}

BST::BST(vector<int> v) {
    sort(v.begin(), v.end());
    r = buildAux(v, 0, (int)v.size()-1, nullptr);
}

void freeAux(PNode u) {
    if (u) {
        freeAux(u->left);
        freeAux(u->right);
        delete u;
    }
}

BST::~BST() {
    freeAux(root());
}

bool BST::is_empty() const {
    return root() != nullptr;
}

PNode BST::root() const {
    return r;
}

int BST::info(PNode u) {
    assert(u);
    return u->key;
}

PNode BST::left(PNode u) {
    assert(u);
    return u->left;
}

PNode BST::right(PNode u) {
    assert(u);
    return u->right;
}

PNode BST::father(PNode u) {
    assert(u);
    return u->father;
}

PNode BST::successor(PNode u) {
    if (!u) return nullptr;
    if (u->right) return min(u->right);
    PNode y = u->father;
    while (y && u == y->right) {
        u = y;
        y = y->father;
    }
    return y;
}

PNode BST::predecessor(PNode u) {
    if (!u) return nullptr;
    if (u->left) return max(u->left);
    PNode y = u->father;
    while (y && u == y->left) {
        u = y;
        y = y->father;
    }
    return y;
}

PNode BST::min(PNode u) {
    PNode iter = u;
    while (iter && iter->left) {
        iter = iter->left;
    }
    return iter;
}

PNode BST::max(PNode u) {
    PNode iter = u;
    while (iter && iter->right) {
        iter = iter->right;
    }
    return iter;
}

PNode BST::searchKeyAux(PNode u, int k) const {
    if (!u || u->key == k)
        return u;
    else if (u->key > k)
        return searchKeyAux(u->left, k);
    else
        return searchKeyAux(u->right, k);
}

PNode BST::searchKey(int k) const {
    return searchKeyAux(r, k);
}

bool BST::contains(PNode u) const {
    if (!u) return false;
    PNode iter = r;
    while (iter && iter != u) {
        if (u->key < iter->key)
            iter = iter->left;
        else
            iter = iter->right;
    }
    return iter != nullptr;
}

void BST::insert(PNode z) {
    assert(z && !z->left && !z->right && !z->father);
    PNode y = nullptr;
    PNode iter = r;
    while (iter) {
        y = iter;
        if (z->key < iter->key)
            iter = iter->left;
        else
            iter = iter->right;
    }
    z->father = y;
    if (!y)
        r = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

void BST::transplant(PNode u, PNode v) {
    assert(u);
    if (!u->father)
        r = v;
    else if (u == u->father->left)
        u->father->left = v;
    else
        u->father->right = v;
    if (v)
        v->father = u->father;
}

void BST::remove(PNode z) {
    assert(contains(z));
    if (!z->left) {
        transplant(z, z->right);
    } else if (!z->right) {
        transplant(z, z->left);
    } else {
        PNode y = min(z->right);
        if (y->father != z) {
            transplant(y, y->right);
            y->right = z->right;
            z->right->father = y;
        }
        transplant(z, y);
        y->left = z->left;
        z->left->father = y;
    }
    delete z;
}

void BST::printDFS(PNode u) {
    if (u) {
        cout << u->key << " ";
        printDFS(u->left);
        printDFS(u->right);
    }
}

void BST::printInorder(PNode u) {
    if (u) {
        printInorder(u->left);
        cout << u->key << " ";
        printInorder(u->right);
    }
}

void BST::printPostorder(PNode u) {
    if (u) {
        printPostorder(u->left);
        printPostorder(u->right);
        cout << u->key << " ";
    }
}

void BST::printBFS(PNode u) {
    queue<PNode> q;
    q.push(u);
    while (!q.empty()) {
        PNode supp = q.front();
        q.pop();
        if (supp) {
            cout << supp->key << " ";
            q.push(supp->left);
            q.push(supp->right);
        }
    }
}
