#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n + 1), s(n + 1);
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, 1 << 30));
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            for (int k = j; k < j + i; k++) {
                f[j][j + i] = std::min(f[j][j + i], f[j][k] + f[k + 1][j + i] +
                                                        s[j + i] - s[j - 1]);
            }
        }
    }

    std::cout << f[1][n] << "\n";

    return 0;
}