#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1 > y1) swap(x1, y1);
    if (x2 > y2) swap(x2, y2);
    if (x3 > y3) swap(x3, y3);
    long long max_side = max({x1, y1, x2, y2, x3, y3});
    long long total_perimeter = x1 + y1 + x2 + y2 + x3 + y3;
    long long result = 0;
    //if (total_perimeter == 4 * max_side) {
        if ((y1 == y2 && y2 == y3 && x1 + x2 + x3 == y1) 
			||y3 == x3 + y1 && y1 == x2 && y2 + x1 == y3 
			|| y3 == x1 + x3 && y2 == x1 && y1 + x2 == y3 
			|| y3 == x3 + y1 && y1 == y2 && x1 + x2 == y3 
			|| y3 == x1 + x3 && x2 == x1 && y1 + y2 == y3 
			|| y2 == x2 + y3 && x1 == y3 && y1 + x3 == y2 
			|| y2 == y1 + y3 && x1 == x3 && x1 + x2 == y2 
			|| y2 == y1 + x2 && y3 == y1 && x1 + x3 == y2 
			|| y2 == x2 + y1 && x3 == y1 && x1 + y3 == y2 
			|| y1 == x1 + x2 && x2 == y3 && x3 + y2 == y1 
			|| y1 == y2 + x1 && y2 == x3 && y3 + x2 == y1 
			|| y1 == x1 + y2 && y3 == y2 && x2 + x3 == y1 
			|| y1 == x1 + x2 && x2 == x3 && y2 + y3 == y1) {
            result = max_side;
        }
    
    cout << result << endl;

    return 0;
}

