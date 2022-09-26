#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n + 1, 0), v(n + 1, 0), w(n + 1, 0);
    std::vector<int> c[n + 1];
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> v[i] >> w[i];
        c[a[i]].push_back(i);
    }

    std::vector<int> f(std::max(n, m) + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (const auto &k : c[i]) {
                if (v[k] <= j) {
                    f[j] = std::max(f[j], f[j - v[k]] + w[k]);
                }
            }
        }
    }

    std::cout << f[m] << "\n";

    return 0;
}