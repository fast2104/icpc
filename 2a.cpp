#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct Rectangle {
    int xA, yA, xB, yB;
};

struct Event {
    int x, y1, y2, type;
    bool operator<(const Event &e) const {
        return x < e.x || (x == e.x && type < e.type);
    }
};

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<Rectangle> rectangles(N);
        set<int> xSet, ySet;

        for (int i = 0; i < N; ++i) {
            cin >> rectangles[i].xA >> rectangles[i].yA >> rectangles[i].xB >> rectangles[i].yB;
            xSet.insert(rectangles[i].xA);
            xSet.insert(rectangles[i].xB);
            ySet.insert(rectangles[i].yA);
            ySet.insert(rectangles[i].yB);
        }

        map<int, int> xMap, yMap;
        int idx = 0;
        for (int x : xSet)
            xMap[x] = idx++;
        idx = 0;
        for (int y : ySet)
            yMap[y] = idx++;

        vector<Event> events;
        for (const auto &rect : rectangles) {
            int xA = xMap[rect.xA], yA = yMap[rect.yA];
            int xB = xMap[rect.xB], yB = yMap[rect.yB];
            events.push_back({xA, yA, yB, 1});
            events.push_back({xB, yA, yB, -1});
        }

        sort(events.begin(), events.end());

        UnionFind uf(yMap.size() * 2);
        set<pair<int, int>> activeSegments;

        for (const auto &event : events) {
            int x = event.x, y1 = event.y1, y2 = event.y2, type = event.type;

            if (type == 1) {
                for (auto it = activeSegments.lower_bound({y1, 0}); it != activeSegments.end() && it->first <= y2; ++it) {
                    uf.unite(it->second, y1);
                }
                activeSegments.insert({y1, y1});
                activeSegments.insert({y2, y2});
            } else {
                activeSegments.erase({y1, y1});
                activeSegments.erase({y2, y2});
            }
        }

        set<int> uniqueRegions;
        for (int i = 0; i < yMap.size(); ++i) {
            if (activeSegments.find({i, i}) != activeSegments.end())
                uniqueRegions.insert(uf.find(i));
        }

        cout << uniqueRegions.size() << endl;
    }

    return 0;
}

