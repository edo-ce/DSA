#include "dict_chaining.hpp"
#include <vector>
#include <cassert>

constexpr int hashsize = 13;

using namespace std;

struct Elem {
    int key;
    int info;
    Elem* next;
    Elem* prev;
};

struct DictChaining::Impl {
    vector<PElem> cells;
    int numKeys{};
};

int funHash(int val){
    return val%hashsize;
}

DictChaining::DictChaining() {
    pimpl = new Impl;
    pimpl->cells.resize(hashsize);
    for (int i = 0; i < hashsize; i++)
        pimpl->cells[i] = nullptr;
    pimpl->numKeys = 0;
}

void deleteAux(PElem elem) {
    if (elem) {
        deleteAux(elem->next);
        delete elem;
    }
}

DictChaining::~DictChaining() {
    for (int i = 0; i < hashsize; i++) {
        deleteAux(pimpl->cells[i]);
    }
    delete pimpl;
}

void DictChaining::insert(int k, int val) {
    auto newElem = new Elem{k, val, pimpl->cells[funHash(k)], nullptr};
    if (pimpl->cells[funHash(k)])
        pimpl->cells[funHash(k)]->prev = newElem;
    pimpl->cells[funHash(k)] = newElem;
    pimpl->numKeys++;
}

void DictChaining::remove(PElem x) {
    pimpl->numKeys--;
    if (x->next)
        x->next->prev = x->prev;
    if (x->prev)
        x->prev->next = x->next;
    if (pimpl->cells[funHash(x->key)] == x)
        pimpl->cells[funHash(x->key)] = x->next;
    delete x;
}

PElem DictChaining::search(int k) const {
    PElem iter = pimpl->cells[funHash(k)];
    while (iter && iter->key != k)
        iter = iter->next;
    return iter;
}

int DictChaining::numKeys() const {
    return pimpl->numKeys;
}

int DictChaining::numCells() {
    return hashsize;
}

int DictChaining::key(PElem x) {
    assert(x);
    return x->key;
}

int DictChaining::info(PElem x) {
    assert(x);
    return x->info;
}

void DictChaining::print() const {
    for (int i = 0; i < hashsize; i++) {
        cout << "Position " << i << ": ";
        PElem iter = pimpl->cells[i];
        while (iter) {
            cout << "{key: " << iter->key << ", info: " << iter->info << "} ";
            iter = iter->next;
        }
        cout << endl;
    }
}
