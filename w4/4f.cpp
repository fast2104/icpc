#include<bits/stdc++.h>
#define MAX 1e9
#define upperbound upper_bound
#define ll long long
#define MAX 1000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<string> ids;
    vector<int> count1(MAX, 0); 
    vector<int> count2(MAX, 0); 
    vector<int> count3(MAX, 0); 
    for (int i = 0; i < n1 + n2 + n3; ++i) {
        string id;
        int count;
        cin >> id >> count;
       auto it = find(ids.begin(), ids.end(), id);
        if (it == ids.end()) {
            ids.push_back(id);
            count1.push_back(0);
            count2.push_back(0);
            count3.push_back(0);

            it = ids.end() - 1; 
        }
        int index = it - ids.begin(); 
        if (i < n1) {
            count1[index] += count;
        } else if (i < n1 + n2) {
            count2[index] += count;
        } else {
            count3[index] += count;
        }
    }
    vector<string> result;
    for (size_t i = 0; i < ids.size(); ++i) {
        if (count1[i] >= 20 && count2[i] >= 20 && count3[i] >= 20) {
            result.push_back(ids[i]);
        }
    }
    cout << result.size() << " ";
    for (const string& id : result) {
        cout << id << " ";
    }

    return 0;
}
