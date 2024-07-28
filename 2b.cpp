#include <bits/stdc++.h>
using namespace std;

void solve(long long current, int digit1, int digit2, long long n, int &count) {
    if (current > n) {
        return;
    }
    if (current != 0) {
        count++;
    }
    for (int i = 0; i <= 9; ++i) {
        if (digit1 == -1 || digit1 == i || digit2 == -1 || digit2 == i) {
            if (digit1 == -1) {
                solve(current * 10 + i, i, digit2, n, count);
            } else if (digit2 == -1 && i != digit1) {
                solve(current * 10 + i, digit1, i, n, count);
            } else {
                solve(current * 10 + i, digit1, digit2, n, count);
            }
        }
    }
}
int main() {
    long long n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= 9; ++i) {
        solve(i, i, -1, n, count);
    }
    cout << count << endl;
    return 0;
}

