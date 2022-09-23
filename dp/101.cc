#include <bits/stdc++.h>

using ll = long long;

void slove(int n) {
    if (n == 1) {
        std::cout << 1 << "\n";
    } else if (n == 2) {
        std::cout << 2 << "\n";
    } else {
        ll a = 1, b = 2, ans = 0;
        for (int i = 2; i < n; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }

        std::cout << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    slove(n);

    return 0;
}