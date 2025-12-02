#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int low = 0, high = a[n - 1] - a[0];
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 1, last = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] - last >= mid) {
                    count++;
                    last = a[i];
                }
            }
            if (count < c) high = mid;
            else low = mid + 1;
        }
        cout << low << endl;
    }
    return 0;
}