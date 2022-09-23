#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const int N = 1001;
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> f(N, 1);
    int ans = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                f[i] = std::max(f[i], f[j] + 1);
                ans = std::max(ans, f[i]);
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}