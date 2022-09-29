#include <bits/stdc++.h>

using i64 = long long;

struct Edges {
    std::vector<int> edges, c;
};

void up(int i, std::vector<Edges> &e, std::vector<i64> &f,
        std::vector<bool> &b) {
    b[i] = true;
    bool ok = true;
    auto edges = e[i].edges;
    auto c = e[i].c;
    for (int j = 0; j < edges.size(); j++) {
        int x = edges[j];
        if (!b[x]) {
            up(x, e, f, b);
            /*
            a node's max flow is determined by two things:
            - flow for each pipe connected to his child
            - child as root flow
            we get the the minimum of the two and add all the child together
            */
            f[i] += std::min(f[x], 1LL * c[j]);
            ok = false;
        }
    }
    if (ok)
        f[i] = 1 << 30;
}

void down(int i, std::vector<Edges> &e, std::vector<i64> &f,
          std::vector<i64> &v, std::vector<bool> &b) {
    b[i] = true;
    auto edges = e[i].edges;
    auto c = e[i].c;
    for (int j = 0; j < edges.size(); j++) {
        int x = edges[j];
        if (!b[x]) {
            /*
            v stands the father of the node's flow:
            - f[i] + v[i] means the total flow of a node i
            - min(c[j], f[x]) means the minimum flow the child connected the
            node i
            - f[i] + v[i] - min(c[j], f[x]) stands the total flow except node j
            - then we consider j node as father, j flows to i
            we get the the minimum of the totol child i and the pipe limit
            */
            i64 flowX = f[i] + v[i] - std::min(1LL * c[j], f[x]);
            if (flowX > 0)
                v[x] = std::min(flowX, 1LL * c[j]);
            else
                v[x] = c[j];
            down(x, e, f, v, b);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    // Edges stores every chind and it's max flow
    std::vector<Edges> e(n + 1);
    std::vector<i64> f(n + 1), v(n + 1);
    std::vector<bool> b(n + 1, false);

    for (int i = 1, x, y, z; i < n; i++) {
        std::cin >> x >> y >> z;
        e[x].edges.push_back(y);
        e[y].edges.push_back(x);

        e[x].c.push_back(z);
        e[y].c.push_back(z);
    }

    up(1, e, f, b);
    std::fill(b.begin(), b.end(), false);
    down(1, e, f, v, b);

    for (int i = 1; i <= n; i++) {
        if (f[i] != 1 << 30)
            std::cout << f[i] + v[i] << "\n";
        else
            std::cout << v[i] << "\n";
    }

    return 0;
}