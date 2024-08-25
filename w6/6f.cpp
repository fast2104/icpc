#include <iostream>
using namespace std;

int findPisanoPeriod(int B) {
    int prev = 0, curr = 1;
    for (int i = 0; i < B * B; i++) {
        int temp = (prev + curr) % B;
        prev = curr;
        curr = temp;
        if (prev == 0 && curr == 1) {
            return i + 1;
        }
    }
    return 25165824; 
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int B;
        cin >> B;
        cout << findPisanoPeriod(B) << endl;
    }
    
    return 0;
}

