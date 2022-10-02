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
    std::vector<std::vector<std::vector<std::array<i64, 2>>>> f(
        21, std::vector<std::vector<std::array<i64, 2>>>(
                10, std::vector<std::array<i64, 2>>(2)));

    f[0][0][0][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if (f[i - 1][j][k][l] != 0) {
                        for (int x = 0; x < 10; x++) {
                            if (l != 0 && x > c[i])
                                continue;
                            if (l != 0) {
                                if (x < c[i]) {
                                    if (k == 0) {
                                        if (x == 0) {
                                            f[i][0][0][0] += f[i - 1][j][k][l];
                                        } else {
                                            f[i][x][1][0] += f[i - 1][j][k][l];
                                        }
                                    } else {
                                        if (std::abs(j - x) <= 2) {
                                            f[i][x][1][0] += f[i - 1][j][k][l];
                                        }
                                    }
                                } else {
                                    if (k == 0) {
                                        f[i][x][1][1] += f[i - 1][j][k][l];
                                    } else {
                                        if (std::abs(j - x) <= 2) {
                                            f[i][x][1][1] += f[i - 1][j][k][l];
                                        }
                                    }
                                }
                            } else {
                                if (k == 0) {
                                    if (x == 0) {
                                        f[i][0][0][0] += f[i - 1][j][k][l];
                                    } else {
                                        f[i][x][1][0] += f[i - 1][j][k][l];
                                    }
                                } else {
                                    if (std::abs(j - x) <= 2) {
                                        f[i][x][1][0] += f[i - 1][j][k][l];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 10; i++)
        res += f[m][i][1][0] + f[m][i][1][1];

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