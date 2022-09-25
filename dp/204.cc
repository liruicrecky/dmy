#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1, 0), w(n + 1, 0), l(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i] >> w[i] >> l[i];
    }

    std::vector<int> f(std::max(n, m) + 1, 0);
    for (int i = 1; i <= n; i++) {
        int cnt = l[i];
        for (int k = 1; k <= cnt; cnt -= k, k *= 2) {
            for (int j = m; j >= v[i] * k; j--) {
                f[j] = std::max(f[j], f[j - v[i] * k] + w[i] * k);
            }
        }
        for (int j = m; j >= v[i] * cnt; j--) {
            f[j] = std::max(f[j], f[j - v[i] * cnt] + w[i] * cnt);
        }
    }

    std::cout << f[m] << "\n";

    return 0;
}