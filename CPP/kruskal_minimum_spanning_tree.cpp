#include <bits/stdc++.h>
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

vector<vector<int>> kruskal_minimum_spanning_tree(vector<pair<pair<int, int>, int>> edges, int n) {
    sort(edges.begin(), edges.end(), compare);

    int ufds[n];
    fill(ufds, ufds + n, -1);

    vector<vector<int>> tree(n, vector<int>());

    for (int i = 0; i < edges.size(); i++) {
        int u, v;
        u = edges[i].first.first;
        v = edges[i].first.second;

        int x = u, y = v;

        while (ufds[x] >= 0) x = ufds[x];
        while (ufds[y] >= 0) y = ufds[y];

        if (x != y) {
            if (x < y)
                swap(x, y);

            ufds[x] += ufds[y];
            ufds[y] = x;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }

    return tree;
}

signed main() {
    int n = 5;
    vector<pair<pair<int, int>, int>> edges = {
        make_pair(make_pair(0, 1), 4),
        make_pair(make_pair(0, 2), 10),
        make_pair(make_pair(0, 3), 3),
        make_pair(make_pair(1, 3), 6),
        make_pair(make_pair(3, 2), 7),
        make_pair(make_pair(2, 4), 10)
    };

    vector<vector<int>> answer = kruskal_minimum_spanning_tree(edges, n);

    for (auto i : answer) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

/*

Minimum Spanning Tree using Kruskal's algorithm in C++
Input: Vector of pairs, number of nodes
Output: Minimum Spanning Tree of the provided graph
----------------------------------------
Time Complexity:
Worst case = O(E log V)
Space Complexity: O(V + E)

*/
