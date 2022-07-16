#include "graph.hpp"
#include <queue>
#include <unordered_set>

vector<ll> key;
vector<int> p;

struct Comp {
    bool operator()(int a, int b) {
        return key[a] > key[b];
    }
};

void init(const Graph& g) {
    key.resize(g.numV());
    p.resize(g.numV());
}

void init_ss(const Graph& g, int r) {
    for (auto u : g.V()) {
        key[u] = INF;
        p[u] = NIL;
    }
    key[r] = 0;
}

void print_res(const vector<Pair>& A) {
    for (auto a : A) {
        cout << "v: " << a.first << " pred: " << a.second << endl;
    }
}

vector<Pair> prim(const Graph& g, int r) {
    init(g);
    init_ss(g, r);
    priority_queue<int, vector<int>, Comp> q;
    unordered_set<int> extracted;
    for (auto u : g.V()) {
        q.push(u);
    }
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        extracted.insert(u);
        for (auto e : g.getAdj(u)) {
            if (extracted.find(e.v) == extracted.end() && e.w < key[e.v]) {
                key[e.v] = e.w;
                p[e.v] = u;
            }
        }
    }
    vector<Pair> A;
    for (auto u : g.V()) {
        if (p[u] != NIL)
            A.emplace_back(u, p[u]);
    }
    return A;
}

int main() {
    vector<Edge> edges = {
            {0, 1, 2}, {0, 2, 1}, {1, 2, 2}, {2, 3, 3}
    };
    Graph graph(edges, false);
    graph.print();

    cout << endl;

    vector<Pair> A = prim(graph, 0);

    print_res(A);

    return 0;
}
