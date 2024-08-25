#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solve(int N, vector<string>& S) {
    unordered_map<string, int> countMap;
    int result = 0;

    for (int i = 0; i < N; i++) {
        string sortedStr = S[i];
        sort(sortedStr.begin(), sortedStr.end());
        countMap[sortedStr]++;
    }

    for (auto& pair : countMap) {
        int k = pair.second;
        result += k * (k - 1) / 2;
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    cout << solve(N, S) << endl;

    return 0;
}

