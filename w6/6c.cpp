#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    int P[N];
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    int min_val = INT_MAX;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        if (P[i] <= min_val) {
            min_val = P[i];
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}

