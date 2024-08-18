#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    
    vector<int> D(N);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }
    
    if (k == 1) {
        sort(D.begin(), D.end());
        int median = D[N / 2];
        double total_cost = 0;
        for (int i = 0; i < N; ++i) {
            total_cost += abs(D[i] - median);
        }
        cout << fixed << setprecision(2) << total_cost << endl;
    } else if (k == 2) {
        double sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += D[i];
        }
        double mean = sum / N;
        double total_cost = 0;
        for (int i = 0; i < N; ++i) {
            total_cost += (D[i] - mean) * (D[i] - mean);
        }
        cout << fixed << setprecision(2) << total_cost << endl;
    }
    
    return 0;
}

