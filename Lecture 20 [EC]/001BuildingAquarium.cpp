#include<iostream>
#include<vector>

using namespace std;

bool f(int n, int x, vector<int>& a, int m) { // linear

    // can you make a tank of height 'm' such that water consumption is <= x units ?

    long long sum = 0; // to track water consumption

    for (int i = 0; i < n; i++) {
        sum += max(0, m - a[i]);
    }

    return sum <= x;

}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int s = 1;
        int e = 2e9;

        int ans;

        while (s <= e) { // time : O(log(e-s).n)

            int m = s + (e - s) / 2;

            // can I build a tank of height 'm' such that
            // water consumption is <= x

            if (f(n, x, a, m)) {

                // you can build a tank of height 'm'

                ans = m;
                s = m + 1;

            } else {

                // you cannot build a tank of height 'm'

                e = m - 1;

            }

        }

        cout << ans << endl;

    }

    return 0;
}