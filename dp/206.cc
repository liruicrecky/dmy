#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> v(n + 1, 0), w(n + 1, 0), t(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i] >> w[i] >> t[i];
    }

    std::vector<std::vector<int>> f(std::max(n, m) + 1,
                                    std::vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            for (int z = k; z >= t[i]; z--) {
                f[j][z] = std::max(f[j][z], f[j - v[i]][z - t[i]] + w[i]);
            }
        }
    }

    std::cout << f[m][k] << "\n";

    return 0;
}