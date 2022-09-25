#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1, 0), w(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i] >> w[i];
    }

    std::vector<int> f(std::max(n, m) + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);
        }
    }

    std::cout << f[m] << "\n";

    return 0;
}