#include <bits/stdc++.h>

using i64 = long long;

i64 solve(i64 n) {
    if (n == 0)
        return 0;

    int m = 0;
    std::vector<int> c(21);
    while (n != 0) {
        c[++m] = n % 10;
        n /= 10;
    }

    for (int i = 1, j = m; i < j; i++, j--) {
        std::swap(c[i], c[j]);
    }

    i64 res = 0;
    bool ok = true;
    std::vector<std::vector<std::array<i64, 2>>> f(
        21, std::vector<std::array<i64, 2>>(10));

    for (int i = 1; i <= m && ok; i++) {
        for (int j = 0; j < c[i]; j++) {
            // 1...ji && |j - i| > 2
            if (i != 1 && std::abs(j - c[i - 1]) > 2)
                continue;

            // empty array f
            for (auto &v : f)
                for (auto &vv : v) {
                    std::fill(vv.begin(), vv.end(), 0);
                }

            // check whether all digit in front of i is 0 or not
            if (i == 1 && j == 0) {
                f[i][j][0] = 1;
            } else {
                f[i][j][1] = 1;
            }

            for (int k = i + 1; k <= m; k++) {
                for (int l = 0; l < 10; l++) {
                    for (int r = 0; r < 2; r++) {
                        if (f[k - 1][l][r] != 0) {
                            for (int x = 0; x < 10; x++) {
                                if (r && std::abs(l - x) <= 2) {
                                    f[k][x][r] += f[k - 1][l][r];
                                }

                                if (!r) {
                                    if (!x) {
                                        f[k][0][0] += f[k - 1][0][0];
                                    } else {
                                        f[k][x][1] += f[k - 1][0][0];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            for (int j = 0; j < 10; j++) {
                res += f[m][j][1];
            }
        }

        if (i != 1 && std::abs(c[i] - c[i - 1]) > 2) {
            ok = false;
        }
    }

    if (ok)
        ++res;

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i64 l, r;
    std::cin >> l >> r;

    std::cout << solve(r) - solve(l - 1) << "\n";

    return 0;
}