#include <bits/stdc++.h>

using i64 = long long;

inline void up(int i, std::vector<int> edges[], std::vector<int> &size,
               std::vector<i64> &f, std::vector<bool> &b) {
    size[i] = 1;
    b[i] = true;
    for (const auto &x : edges[i]) {
        if (!b[x]) {
            up(x, edges, size, f, b);
            size[i] += size[x];
            f[i] += f[x];
        }
    }
    // f[i] = f[1..j] + size[1..j], size[1..j] = size[i] - 1
    f[i] += size[i] - 1;
}

inline void down(int i, int n, std::vector<int> edges[], std::vector<int> &size,
                 std::vector<i64> &f, std::vector<i64> &v,
                 std::vector<bool> &b) {
    b[i] = true;
    for (const auto &x : edges[i]) {
        if (!b[x]) {
            /*
                i
                 |
                  |
                   x
            v[i] + f[i] is the total length for node i(v stands for parents nodes, 
                f stands for children nods)
            we need to compute the v[x]:
                first subtract the total length start from x, which is f[x] + size[x]
                second add the rest length from x to i, which is n - size[x]
            */
            v[x] = v[i] + f[i] - f[x] - size[x] + n - size[x];
            down(x, n, edges, size, f, v, b);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> edges[n + 1];
    for (int i = 1, u, v; i < n; i++) {
        std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    std::vector<int> size(n + 1);
    std::vector<i64> f(n + 1), v(n + 1);
    std::vector<bool> b(n + 1, false);

    up(1, edges, size, f, b);
    std::fill(b.begin(), b.end(), false);
    down(1, n, edges, size, f, v, b);

    for (int i = 1; i <= n; i++)
        std::cout << f[i] + v[i] << "\n";

    return 0;
}