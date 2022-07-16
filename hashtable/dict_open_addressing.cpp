#include "dict_open_addressing.hpp"
#include <vector>
#include <cassert>
#include <limits>

constexpr int hashsize = 13;
constexpr int hashaux = 11;

using namespace std;

struct Elem {
    int key;
    int info;
};

struct DictOpenAdd::Impl {
    vector<PElem> cells;
    int numKeys{};
    PElem DEL{};
};

int funHash(int val, int i) {
    return (val%hashsize + i*(1+val%hashaux))%hashsize;
}

DictOpenAdd::DictOpenAdd() {
    pimpl = new Impl;
    pimpl->cells.resize(hashsize);
    for (int i = 0; i < hashsize; i++)
        pimpl->cells[i] = nullptr;
    pimpl->numKeys = 0;
    pimpl->DEL = new Elem{numeric_limits<int>::max(), numeric_limits<int>::max()};
}

DictOpenAdd::~DictOpenAdd() {
    for (int i = 0; i < hashsize; i++) {
        if (pimpl->cells[i] && pimpl->cells[i] != pimpl->DEL)
            delete pimpl->cells[i];
    }
    delete pimpl->DEL;
    delete pimpl;
}

void DictOpenAdd::insert(int k, int val) {
    if (search(k)) return;
    int i = 0;
    bool found = false;
    while (!found && i < hashsize) {
        int index = funHash(k, i);
        if (pimpl->cells[index] == nullptr || pimpl->cells[index] == pimpl->DEL) {
            pimpl->cells[index] = new Elem{k, val};
            found = true;
        } else {
            ++i;
        }
    }
    if (found)
        pimpl->numKeys++;
}

void DictOpenAdd::remove(PElem x) {
    int i = 0;
    while (pimpl->cells[i] != x && i < hashsize)
        i++;
    if (i < hashsize) {
        pimpl->cells[i] = pimpl->DEL;
        delete x;
        pimpl->numKeys--;
    }
}

PElem DictOpenAdd::search(int k) const {
    int i = 0;
    bool found = false;
    PElem res = nullptr;
    while (!found && i < hashsize) {
        int index = funHash(k, i);
        if (pimpl->cells[index] && pimpl->cells[index] != pimpl->DEL && pimpl->cells[index]->key == k) {
            found = true;
            res = pimpl->cells[index];
        } else {
            ++i;
        }
    }
    return res;
}

int DictOpenAdd::numKeys() const {
    return pimpl->numKeys;
}

int DictOpenAdd::numCells() {
    return hashsize;
}

int DictOpenAdd::key(PElem x) {
    assert(x);
    return x->key;
}

int DictOpenAdd::info(PElem x) {
    assert(x);
    return x->info;
}

void DictOpenAdd::print() const {
    for (int i = 0; i < hashsize; i++) {
        cout << "Cell " << i << ": ";
        if (!pimpl->cells[i])
            cout << "empty" << endl;
        else if (pimpl->cells[i] == pimpl->DEL)
            cout << "deleted" << endl;
        else
            cout << "key: " << pimpl->cells[i]->key << " info: " << pimpl->cells[i]->info << endl;
    }
}
