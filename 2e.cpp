#include <bits/stdc++.h>
using namespace std;
int solve(int x) {
    int count = 0;
    while (x % 2 == 0) {
        x /= 2;
        count++;
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int steps = 0;
    for (int i = 0; i < N; ++i) {
        steps += solve(a[i]);
    }
    cout << steps << endl;
    return 0;
}

