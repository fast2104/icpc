#include <bits/stdc++.h>
using namespace std;

vector<long long> len;

void sinh() {
    len.push_back(3);
    for(int i = 1; i <= 28; i++)
        len.push_back(2 * len[i - 1] + (i + 3));
}

char find_char(long long n, int k) {
    if(k == 0) {
        return (n == 1) ? 'a' : 'c';
    }
    long long len_prev = len[k - 1];
    if(n <= len_prev)
        return find_char(n, k - 1);
    else if(n > len_prev + (k + 3))
        return find_char(n - len_prev - (k + 3), k - 1);
    else {
        return (n == len_prev + 1) ? 'a' : 'c';
    }
}

void solve() {
    long long idx;
    cin >> idx;
    sinh();
    int k = 0;
    while(len[k] < idx) k++;
    cout << find_char(idx, k) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

