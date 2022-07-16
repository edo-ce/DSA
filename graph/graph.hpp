#ifndef DSA_GRAPH_HPP
#define DSA_GRAPH_HPP

#include <iostream>
#include <vector>
#include <limits>

#define INF numeric_limits<int>::max()
#define NIL (-1)

using namespace std;

typedef pair<int, int> Pair;
typedef long long int ll;

struct Edge {
    int u; // source
    int v; // destination
    int w; // weight

    Edge(int _u, int _v, int _w) : u{_u}, v{_v}, w{_w} {};
};

class Graph {
public:
    explicit Graph(bool is_oriented = true);
    explicit Graph(const vector<Edge>& v, bool is_oriented = true);
    ~Graph();

    void print() const;
    vector<int> V() const;
    vector<Edge> E() const;
    size_t numV() const;
    size_t numE() const;
    bool is_oriented() const;
    vector<Edge> getAdj(int src) const;
    vector<vector<ll>> toMatrix() const;
private:
    vector<vector<Pair>> adj;
    bool oriented;
};

#endif
