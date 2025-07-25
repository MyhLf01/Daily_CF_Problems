#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> ans;

    while (t --) {
        string s;
        cin >> s;

        if (s[0] == 'i') {
            int x;
            cin >> x;
            pq.push(x);
            ans.emplace_back(0, x);
        }
        else if (s[0] == 'g') {
            int x;
            cin >> x;

            while (!pq.empty() && pq.top() < x) {
                pq.pop();
                ans.emplace_back(2, 0);
            }

            if (pq.empty() || pq.top() != x) {
                pq.push(x);
                ans.emplace_back(0, x);
            }

            ans.emplace_back(1, x);
        }
        else {
            if (pq.empty()) {
                pq.push(1);
                ans.emplace_back(0, 1);
            }

            pq.pop();
            ans.emplace_back(2, 0);
        }
    }

    cout << ans.size() << '\n';
    for (auto &[x, y]: ans) {
        if (x == 0) cout << "insert " << y << '\n';
        else if (x == 1) cout << "getMin " << y << '\n';
        else cout << "removeMin\n";
    }

    return 0;
}