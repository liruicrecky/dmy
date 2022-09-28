#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> w(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> w[i][j];

    std::vector<int> f(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k <= j; k++) {
                f[j] = std::max(f[j], f[j - k] + w[i][k]);
            }
        }
    }

    std::cout << f[m] << "\n";

    return 0;
}