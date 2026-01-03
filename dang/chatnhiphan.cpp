#include<iostream>
#include<algorithm>
using namespace std;
int main() {
#define boost;
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k, l, r, mi; cin >> n >> k; int a[n + 1];
    for (int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1); l = 1, r = n; mi = (r - l + 1) / 2;
    while (l < r) {
        if (k > a[mi]) {l = mi + 1; mi = l + (r - l + 1) / 2;}
        if (k < a[mi]) {r = mi - 1; mi = l + (r - l + 1) / 2;}
        if (k == a[mi]) {cout << mi; return 0;}
    }
    cout << "NO,Man";
    return 0;
}
