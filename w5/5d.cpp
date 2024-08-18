#include<bits/stdc++.h>
#define MAX 1e9
#define upperbound upper_bound
#define ll long long
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int diff = MAX;
	for(int i = 0; i < n - k; i++)  {
		int curr = a[i + k - 1] - a[i];
		diff = min(diff, curr);
	}
	cout << diff;
}

