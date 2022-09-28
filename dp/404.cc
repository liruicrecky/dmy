#include <bits/stdc++.h>

void solveDFS(int i, int m, std::vector<int> edges[], std::vector<int> &a,
              std::vector<std::vector<std::array<int, 2>>> &f) {
    for (const auto &v : edges[i]) {
        solveDFS(v, m, edges, a, f);
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k <= j; k++) {
                f[i][j][0] =
                    std::max(f[i][j][0],
                             f[i][j - k][0] + std::max(f[v][k][0], f[v][k][1]));
                f[i][j][1] = std::max(f[i][j][1], f[i][j - k][1] + f[v][k][0]);
            }
        }
    }
    for (int j = m; j >= 0; --j)
        f[i][j][1] = f[i][j - 1][1] + a[i];
    f[i][0][1] = 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

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

    std::vector<std::vector<std::array<int, 2>>> f(
        n + 1, std::vector<std::array<int, 2>>(m + 1));
    solveDFS(1, m, edges, a, f);

    std::cout << std::max(f[1][m][0], f[1][m][1]) << "\n";

    return 0;
}