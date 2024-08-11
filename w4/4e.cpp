#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << (long long)n * n << endl;
        return 0;
    }

    long long count = 0;
    for (int b = k + 1; b <= n; ++b) {
        int t = (n - k) / b;
        int r = b - k;
        count += (r * (t + 1));
    }

    cout << count << endl;

    return 0;
}


