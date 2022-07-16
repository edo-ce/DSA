#include "graph.hpp"
#include <algorithm>

vector<int> disjointSets;

void print_res(const vector<Pair>& A) {
    for (auto a : A) {
        cout << "( " << a.first << ", " << a.second << " )" << endl;
    }
}

vector<Pair> kruskal(const Graph& g) {
    vector<Pair> A;
    disjointSets.resize(g.numV());
    for (int i = 0; i < g.numV(); ++i)
        disjointSets[i] = i;
    vector<Edge> edges = g.E();
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {return a.w < b.w;});
    for (const auto& e : edges) {
        if (disjointSets[e.u] != disjointSets[e.v]) {
            disjointSets[e.v] = disjointSets[e.u];
            A.emplace_back(e.u, e.v);
        }
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

    vector<Pair> A = kruskal(graph);

    print_res(A);

    return 0;
}
