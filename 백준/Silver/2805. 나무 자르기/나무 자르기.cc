#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long m;
    cin >> n >> m;

    vector<int> trees(n);
    long long max_h = 0;

    for (int i = 0; i < n; i++) {
        cin >> trees[i];

        if (trees[i] > max_h) {
            max_h = trees[i];
        }
    }

    long long low = 0;
    long long ans = 0;
    long long high = max_h;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long total_wood = 0;

        for (int i = 0; i < n; i++) {
            if (trees[i] > mid) {
                total_wood += (trees[i] - mid);
            }
        }

        if (total_wood >= m) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}