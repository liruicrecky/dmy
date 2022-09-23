#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<bool>> f(n + 1, std::vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        f[i][i] = true;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            // j...i
            if (a[j] == a[i]) {
                if (j + 1 == i || f[j + 1][i - 1]) {
                    f[j][i] = true;
                    ans = std::max(ans, i - j + 1);
                }
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}