#include "graph.hpp"
#include <algorithm>

Graph::Graph(bool is_oriented) : oriented(is_oriented) {}

Graph::Graph(const vector<Edge>& v, bool is_oriented) : oriented(is_oriented) {
    auto maxV = *max_element(v.begin(), v.end(), [](const Edge& a, const Edge& b) {return max(a.u, a.v) < max(b.u, b.v);});
    adj.resize(max(maxV.u, maxV.v) + 1);
    for (auto& e : v) {
        adj[e.u].push_back(make_pair(e.v, e.w));
        if (!oriented)
            adj[e.v].push_back(make_pair(e.u, e.w));
    }
}

Graph::~Graph() = default;

void Graph::print() const {
    for (int i = 0; i < adj.size(); ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << i << " -" << adj[i][j].second << "-> " << adj[i][j].first << endl;
        }
    }
}

vector<int> Graph::V() const {
    vector<int> v;
    for (int i = 0; i < adj.size(); ++i)
        v.push_back(i);
    return v;
}

vector<Edge> Graph::E() const {
    vector<Edge> e;
    for (int i = 0; i < adj.size(); ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            e.emplace_back(i, adj[i][j].first, adj[i][j].second);
        }
    }
    return e;
}

size_t Graph::numV() const {
    return adj.size();
}

size_t Graph::numE() const {
    return E().size();
}

bool Graph::is_oriented() const {
    return oriented;
}

vector<Edge> Graph::getAdj(int src) const {
    vector<Edge> e;
    for (int i = 0; i < adj[src].size(); ++i) {
        e.emplace_back(src, adj[src][i].first, adj[src][i].second);
    }
    return e;
}

vector<vector<ll>> Graph::toMatrix() const {
    vector<vector<ll>> m(numV(), vector<ll>(numV(), INF));
    for (int i = 0; i < numV(); ++i) {
        m[i][i] = 0;
    }
    for (auto e : E()) {
        m[e.u][e.v] = e.w;
    }
    return m;
}
