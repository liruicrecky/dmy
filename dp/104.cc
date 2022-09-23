#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1, 0), b(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
    }

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) {
                f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }

    std::cout << f[n][m] << "\n";

    return 0;
}