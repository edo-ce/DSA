#ifndef DSA_DICT_CHAINING_HPP
#define DSA_DICT_CHAINING_HPP

#include <iostream>

typedef struct Elem *PElem;

class DictChaining {
public:
    DictChaining();
    ~DictChaining();

    void insert(int k, int val);
    void remove(PElem e);
    PElem search(int k) const;
    int numKeys() const;
    static int numCells();
    static int key(PElem e);
    static int info(PElem e);
    void print() const;
private:
    struct Impl;
    Impl* pimpl;
};

#endif
