#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& a, int k) {
    int n = a.size();
    int steps = 0;
    for (int i = 0; i < n;) {
        int minValue = *min_element(a.begin() + i, a.begin() + min(i + k, n));
        for (int j = i; j < min(i + k, n); j++) {
            a[j] = minValue;
        }
        steps++;
        i += k - 1;
    }
    return steps;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(N);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int result = solve(a, k);
    cout << result << endl;
    
    return 0;
}

