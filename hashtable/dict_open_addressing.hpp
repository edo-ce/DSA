#ifndef DSA_DICT_OPEN_ADDRESSING_HPP
#define DSA_DICT_OPEN_ADDRESSING_HPP

#include <iostream>

typedef struct Elem *PElem;

class DictOpenAdd {
public:
    DictOpenAdd();
    ~DictOpenAdd();

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
