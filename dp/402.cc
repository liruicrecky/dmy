#include <bits/stdc++.h>

using i64 = long long;

void solveDFS(int i, std::vector<int> edges[], std::vector<int> &a,
              std::vector<std::array<i64, 2>> &f) {
    f[i][1] = a[i];
    for (const auto &v : edges[i]) {
        solveDFS(v, edges, a, f);
        f[i][0] += std::max(f[v][0], f[v][1]);
        f[i][1] += f[v][0];
    }
}

void solveBFS(int n, std::vector<int> edges[], std::vector<int> &a,
              std::vector<std::array<i64, 2>> &f) {
    // using array instead deque
    int que[100001];
    que[1] = 1;

    // add all node
    for (int k = 1, i = 1; i <= k; i++) {
        int m = que[i];
        for (const auto &v : edges[m]) {
            que[++k] = v;
        }
    }

    for (int i = n; i >= 0; i--) {
        int m = que[i];
        f[m][1] = a[m];
        for (const auto &v : edges[m]) {
            f[m][0] += std::max(f[v][0], f[v][1]);
            f[m][1] += f[v][0];
        }
    }
}

void solveBFSDeque(int n, std::vector<int> edges[], std::vector<int> &a,
                   std::vector<std::array<i64, 2>> &f) {
    std::deque<int> que;
    que.push_back(1);

    for (int k = 0, i = 1; i <= n; i++) {
        int m = que.at(k++);
        for (const auto &v : edges[m]) {
            que.push_back(v);
        }
    }

    while (!que.empty()) {
        int m = que.back();
        que.pop_back();
        f[m][1] = a[m];
        for (const auto &v : edges[m]) {
            f[m][0] += std::max(f[v][0], f[v][1]);
            f[m][1] += f[v][0];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    int x;
    std::vector<int> edges[n + 1], a(n + 1);
    for (int i = 2; i <= n; i++) {
        std::cin >> x;
        edges[x].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        std::cin >> x;
        a[i] = x;
    }

    std::vector<std::array<i64, 2>> f(n + 1);
    solveBFS(n, edges, a, f);

    std::cout << std::max(f[1][0], f[1][1]) << "\n";

    return 0;
}