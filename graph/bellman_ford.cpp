#include "graph.hpp"

vector<ll> d;
vector<int> p;

void init(const Graph& g) {
    d.resize(g.numV());
    p.resize(g.numV());
}

void init_ss(const Graph& g, int s) {
    for (auto u : g.V()) {
        d[u] = INF;
        p[u] = NIL;
    }
    d[s] = 0;
}

void relax(int u, int v, int w) {
    if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
    }
}

void print_res(const Graph& g, bool ok) {
    if (ok) {
        for (int i = 0; i < g.numV(); ++i) {
            cout << "v: " << i << " dist: ";
            if (d[i] == INF) cout << "INF";
            else cout << d[i];
            cout << " pred: " << p[i] << endl;
        }
    } else {
        cout << "There are negative cycles in the graph";
    }
}

void bellman_ford(const Graph& g, int s) {
    init(g);
    init_ss(g, s);
    for (int i = 0; i < g.numV()-1; ++i) {
        for (auto e : g.E()) {
            relax(e.u, e.v, e.w);
        }
    }
    bool ok = true;
    for (auto e : g.E()) {
        if (d[e.v] > d[e.u] + e.w) {
            ok = false;
            break;
        }
    }
    print_res(g, ok);
}

int main() {
    vector<Edge> edges = {
            {0, 1, 10}, {0, 4, 5}, {1, 4, 2}, {1, 2, 1}, {2, 3, 4},
            {3, 2, 6}, {3, 0, 7}, {4, 1, 3}, {4, 2, 9}, {4, 3, 2}
    };
    Graph graph(edges);
    graph.print();

    cout << endl;

    bellman_ford(graph, 0);

    return 0;
}
