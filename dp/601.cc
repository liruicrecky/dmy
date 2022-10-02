#include <bits/stdc++.h>

using i64 = long long;

void calc(i64 n, int xs, std::vector<i64> &f, std::vector<int> &c,
          std::vector<i64> &ans) {

    // get every digit of n
    int m = 0;
    while (n != 0) {
        c[++m] = n % 10;
        n /= 10;
    }

    for (int i = 1, j = m; i < j; i++, j--) {
        std::swap(c[i], c[j]);
    }

    // for every category
    /*
        12345
        - 1 ~ 9999
        - 10000 ~ 11999
        - 12000 ~ 12299
        - 12300 ~ 12339
        - 12340 ~ 12344
    */
    for (int i = 1; i <= m; i++) {

        // 1...j...i, < i
        for (int j = 1; j < i; j++) {
            ans[c[j]] += xs * c[i] * f[m - i];
        }

        // ...j..., = i
        for (int j = 1; j < c[i]; j++) {
            ans[j] += xs * f[m - i];
        }

        // not category 1 and current digit can put 0
        if (i != 1 && c[i] != 0) {
            ans[0] += xs * f[m - i];
        }

        // 1...i...j, > i
        if (m != i) {
            for (int j = 1; j < 10; j++) {
                ans[j] += xs * f[m - i - 1] * (m - i) * c[i];
            }

            if (i != 1) {
                ans[0] += xs * f[m - i - 1] * (m - i) * c[i];
            }
        }

        // category 1 cal number of 0
        if (i == 1) {
            // first digit is not 0
            if (m >= 2) {
                ans[0] += xs * (c[1] - 1) * (m - 1) * f[m - 2];
            }

            // the rest of digit is not zero
            for (int j = 2; j < m; j++) {
                ans[0] += xs * 9 * (m - j) * f[m - j - 1];
            }
        }
    }

    // the n itself
    for (int i = 1; i <= m; i++) {
        ans[c[i]] += xs;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i64 l, r;
    std::cin >> l >> r;

    std::vector<int> c(21);
    std::vector<i64> f(17), ans(10);

    // store power of 10
    f[0] = 1;
    for (int i = 1; i <= 16; i++) {
        f[i] = f[i - 1] * 10;
    }

    // xs = 1 means add, xs = -1 means minus
    calc(r, 1, f, c, ans);
    calc(l - 1, -1, f, c, ans);

    for (int i = 0; i < 10; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";

    return 0;
}