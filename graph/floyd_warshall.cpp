#include "graph.hpp"

void printMatrix(const vector<vector<ll>>& m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            if (m[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<ll>> floyd_warshall(const vector<vector<ll>>& W) {
    size_t n = W.size();
    vector<vector<ll>> D = W;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
    return D;
}

int main() {
    vector<Edge> edges = {
            {0, 2, -2}, {1, 0, 4}, {1, 2, 3}, {2, 3, 2}, {3, 1, -1}
    };
    Graph graph(edges);
    vector<vector<ll>> W = graph.toMatrix();

    printMatrix(W);
    cout << endl;

    vector<vector<ll>> D = floyd_warshall(W);

    printMatrix(D);

    return 0;
}
