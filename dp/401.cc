#include <bits/stdc++.h>

// use linkedlist to store a tree
struct node {
    node *next;
    int where;
} * first[100001], a[100001];

int l = 0, f[100001], c[100001];

inline void makelist(int x, int y) {
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

inline void solveLinkedListDFS(int i) {
    f[i] = 1;
    for (auto *x = first[i]; x != nullptr; x = x->next) {
        solveLinkedListDFS(x->where);
        f[i] += f[x->where];
    }
}

// use vector to stroe a tree
inline void addedge(int x, int y, std::vector<int> edges[]) {
    edges[x].push_back(y);
}

inline void sloveVectorDFS(int i, std::vector<int> edges[],
                           std::vector<int> &f) {
    f[i] = 1;
    for (const auto &node : edges[i]) {
        sloveVectorDFS(node, edges, f);
        f[i] += f[node];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> edges[n + 1];
    std::vector<int> ff(n + 1, 0);

    // For vector
    for (int i = 2; i <= n; i++) {
        int x;
        std::cin >> x;
        addedge(x, i, edges);
    }

    // For LinkedList
    /*
    std::memset(first, 0, sizeof(first));
    for (int i = 2; i <= n; i++) {
        int x;
        std::cin >> x;
        makelist(x, i);
    }
    */

    // vector DFS
    // sloveVectorDFS(1, edges, ff);

    // vector BFS
    std::deque<int> que;
    que.push_back(1);
    for (int k = 0, i = 1; i <= n; i++) {
        int m = que.at(k++);
        for (const auto &val : edges[m]) {
            que.push_back(val);
        }
    }

    while (!que.empty()) {
        int m = que.back();
        que.pop_back();
        ff[m] = 1;
        for (const auto &node : edges[m])
            ff[m] += ff[node];
    }

    // LinkedList BFS
    /*
    c[1] = 1;
    for (int k = 1, l = 1; l <= k; l++) {
        int m = c[l];
        for (auto *x = first[m]; x != nullptr; x = x->next) {
            c[++k] = x->where;
        }
    }

    for (int i = n; i >= 0; --i) {
        int m = c[i];
        f[m] = 1;
        for (auto *x = first[m]; x != nullptr; x = x->next) {
            f[m] += f[x->where];
        }
    }
    */

    // LinkedList DFS
    // solveLinkedListDFS(1);

    // for linkedList
    for (int i = 1; i <= n; i++)
        std::cout << f[i] << " ";

    // for vector
    for (int i = 1; i <= n; i++)
        std::cout << ff[i] << " ";

    return 0;
}