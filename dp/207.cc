#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n + 1), b(n);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i];
    }

    std::deque<std::array<int, 2>> que;
    for (int i = 1; i <= n; i++) {
        while (!que.empty() && que.back()[0] <= b[i]) {
            que.pop_back();
        }
        que.push_back({b[i], a[i]});
        std::cout << que.front()[0] << "\n";
        while (!que.empty() && que.front()[1] == i) {
            que.pop_front();
        }
    }

    return 0;
}