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
    vector<int> a(n);
    vector<int> max_left(n);
    vector<int> min_right(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    max_left[0] = a[0];
    for(int i = 1; i < n; ++i) {
        max_left[i] = max(max_left[i-1], a[i]);
    }
    min_right[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i) {
        min_right[i] = min(min_right[i+1], a[i]);
    }
    vector<int> pivots;
    for(int i = 0; i < n; ++i) {
        int left_max = (i > 0) ? max_left[i-1] : INT_MIN;
        int right_min = (i < n-1) ? min_right[i+1] : INT_MAX;
        
        if(left_max <= a[i] && a[i] <= right_min) {
            pivots.push_back(a[i]);
        }
    }
    int m = pivots.size();
    cout << m;
    if (m > 100) m = 100;
    for(int i = 0; i < m; ++i) {
        cout << " " << pivots[i];
    }
    cout << endl;

    return 0;
}
