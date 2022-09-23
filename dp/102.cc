#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const int M = 1003;
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> G(M, std::vector<int>(M, 1 << 30));

    for (int i = 0; i < m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        G[x][y] = std::min(G[x][y], z);
    }

    std::vector<int> f(M, 1 << 30);
    f[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (f[j] < 1 << 30 && G[j][i] < 1 << 30) {
                f[i] = std::min(f[i], f[j] + G[j][i]);
            }
        }
    }

    std::cout << f[n] << "\n";

    return 0;
}