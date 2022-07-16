#include "graph.hpp"
#include <queue>

vector<ll> d;
vector<int> p;

struct Comp {
    bool operator()(int a, int b) {
        return d[a] > d[b];
    }
};

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

void print_res(const Graph& g) {
    for (int i = 0; i < g.numV(); ++i) {
        cout << "v: " << i << " dist: ";
        if (d[i] == INF) cout << "INF";
        else cout << d[i];
        cout << " pred: " << p[i] << endl;
    }
}

void dijkstra(const Graph& g, int s) {
    init(g);
    init_ss(g, s);
    priority_queue<int, vector<int>, Comp> q;
    for (auto u : g.V()) {
        q.push(u);
    }
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        for (auto e : g.getAdj(u)) {
            relax(u, e.v, e.w);
        }
    }
    print_res(g);
}

int main() {
    vector<Edge> edges = {
            {0, 1, 10}, {0, 4, 5}, {1, 4, 2}, {1, 2, 1}, {2, 3, 4},
            {3, 2, 6}, {3, 0, 7}, {4, 1, 3}, {4, 2, 9}, {4, 3, 2}
    };
    Graph graph(edges);
    graph.print();

    cout << endl;

    dijkstra(graph, 0);

    return 0;
}
