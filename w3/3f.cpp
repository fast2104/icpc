#include<bits/stdc++.h>
#define MAX 1e9
#define upperbound upper_bound
#define ll long long
using namespace std;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void multiply(ll F[2][2], ll M[2][2], ll mod) {
    ll x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % mod;
    ll y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % mod;
    ll z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % mod;
    ll w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % mod;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
void power(ll F[2][2], ll n, ll mod) {
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2, mod);
    multiply(F, F, mod);

    if (n % 2 != 0)
        multiply(F, M, mod);
}
ll fibonacciMod(ll n, ll mod) {
    if (n == 0) return 0;
    ll F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1, mod);
    return F[0][0];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b, M;
        cin >> a >> b >> M;

        ll g = gcd(a, b);
        ll result = fibonacciMod(g, M);
        cout << result << endl;
    }
    return 0;
}
