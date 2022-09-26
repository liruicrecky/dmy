#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> f(m + 1);
    int c[10001][2];
    int v, w, l;

    for (int i = 1; i <= n; i++) {
        std::cin >> v >> w >> l;
        // for every remainder
        for (int j = 0; j < v; j++) {
            int k = 0, ll = 1;
            for (int p = j, x = 1; p <= m; p += v, ++x) {
                int e = f[p] - x * w, r = x + l;
                for (; k >= ll && c[k][0] <= e; --k)
                    ;
                c[++k][0] = e;
                c[k][1] = r;
                f[p] = c[ll][0] + x * w;
                for (; k >= ll && c[ll][1] == x; ++ll)
                    ;
            }
        }
    }

    std::cout << f[m] << "\n";

    return 0;
}