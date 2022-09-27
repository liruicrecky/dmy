#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if ((s[j - 1] == '(' && s[j + i - 1] == ')') ||
                (s[j - 1] == '[' && s[j + i - 1] == ']'))
                f[j][j + i] = f[j + 1][j + i - 1] + 2;
            for (int k = j; k < i + j; k++)
                f[j][j + i] = std::max(f[j][j + i], f[j][k] + f[k + 1][j + i]);
        }
    }

    std::cout << f[1][n] << "\n";

    return 0;
}