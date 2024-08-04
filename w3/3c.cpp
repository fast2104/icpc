#include<bits/stdc++.h>
#define MAX 1e9
#define upperbound upper_bound
#define ll long long
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if((n - 4) % 7 == 0 || (n - 7) % 4 ==0 || n % 4 == 0 || n % 7 == 0) {
		cout << "Yes";
	} else cout << "No";
}

