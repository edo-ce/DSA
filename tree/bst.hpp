#ifndef DSA_BST_HPP
#define DSA_BST_HPP

#include <iostream>
#include <vector>

typedef struct Node* PNode;

class BST {
public:
    BST();
    explicit BST(std::vector<int> v);
    ~BST();
    bool is_empty() const;
    PNode root() const;
    static int info(PNode u);
    static PNode left(PNode u);
    static PNode right(PNode u);
    static PNode father(PNode u);
    static PNode successor(PNode u);
    static PNode predecessor(PNode u);
    static PNode min(PNode u);
    static PNode max(PNode u);
    PNode searchKey(int k) const;
    bool contains(PNode u) const;
    void insert(PNode z);
    void remove(PNode z);
    static void printDFS(PNode u);
    static void printInorder(PNode u);
    static void printPostorder(PNode u);
    static void printBFS(PNode u);
private:
    PNode r;
    void transplant(PNode u, PNode v);
    PNode searchKeyAux(PNode u, int k) const;
    PNode buildAux(const std::vector<int>& v, int inf, int sup, PNode father);
};

PNode createNode(int val);

#endif
