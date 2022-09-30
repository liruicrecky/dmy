#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> edges[n + 1];
    for (int i = 1, u, v; i < n; i++) {
        std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    /*
    f stands for the latgest lenght path of node i;
    f[i][0]: the largest one, f[i][1]: the second largest one
    f[i][0][0]: the largest length, f[i][1][0]: the second largest length
    f[i][0][1] and f[i][1][1]: where this chin from
    */
    std::vector<std::vector<std::vector<int>>> f(
        n + 1, std::vector<std::vector<int>>(2, std::vector<int>(2)));
    std::vector<int> v(n + 1);
    std::vector<bool> b(n + 1, false);

    std::function<void(int)> up = [&](int i) -> void {
        b[i] = true;
        for (const auto &x : edges[i]) {
            if (!b[x]) {
                up(x);
                /*
                If any child plus one greater than father i:
                - first we swap the second large and the i
                - second set i is the largest
                else if this child plus one greater than the second one, swap it
                */
                if (f[x][0][0] + 1 > f[i][0][0]) {
                    f[i][1][0] = f[i][0][0];
                    f[i][1][1] = f[i][0][1];
                    f[i][0][0] = f[x][0][0] + 1;
                    f[i][0][1] = x;
                } else {
                    if (f[x][0][0] + 1 > f[i][1][0]) {
                        f[i][1][0] = f[x][0][0] + 1;
                        f[i][1][1] = x;
                    }
                }
            }
        }
    };

    std::function<void(int)> down = [&](int i) -> void {
        b[i] = true;
        for (const auto &x : edges[i]) {
            if (!b[x]) {
                /*
                Chose the largest one from f[i][0], f[i][1], v[i]
                - if the f[i][0] is x, chose from f[i][1] and v[i]
                - else chose from f[i][0], v[i]
                */
                if (f[i][0][1] == x) {
                    v[x] = std::max(v[i], f[i][1][0]) + 1;
                } else {
                    v[x] = std::max(f[i][0][0], v[i]) + 1;
                }
                down(x);
            }
        }
    };

    up(1);
    std::fill(b.begin(), b.end(), false);
    down(1);

    for (int i = 1; i <= n; i++)
        std::cout << f[i][0][0] + f[i][1][0] + v[i] -
                         std::min({f[i][0][0], f[i][1][0], v[i]})
                  << "\n";

    return 0;
}