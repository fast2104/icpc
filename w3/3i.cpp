#include<bits/stdc++.h>
#define MAX 1e9
#define upperbound upper_bound
#define ll long long
using namespace std;
bool prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int a = 2; a <= n / 2; ++a) {
        int b = n - a;
        if (prime(a) && prime(b) && a <= b) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
