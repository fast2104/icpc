#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    unordered_map<int, int> count;
    for (int i = 1; i <= M; ++i) {
        count[i] = 0;
    }
    for (int vote : a) {
        count[vote]++;
    }
    vector<pair<int, int>> countvt;
    for (const auto& entry : count) {
        countvt.push_back(entry);
    }
    sort(countvt.begin(), countvt.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    });
    int first = countvt[0].second;
    int second = -1;
    int secondCandidate = -1;
    for (int i = 1; i < countvt.size(); ++i) {
        if (countvt[i].second < first) {
            second = countvt[i].second;
            secondCandidate = countvt[i].first;
            break;
        }
    }
    if (second == -1 || second == 0) {
        cout << "NONE" << endl;
    } else {
        cout << secondCandidate << endl;
    }

    return 0;
}

