#include<bits/stdc++.h>
using namespace std;
#define int long long int
struct td {int x, y;};
td a, b;
struct ii {int A, B, C;};

double khoangcach(td q, td p) {
    return (double)sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
}

ii heso(td q, td p) {
    ii kq;
    kq.A = q.y - p.y;
    kq.B = p.x - q.x;;
    kq.C = -1 * (kq.A * q.x) - kq.B * q.y;
    return kq;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
//freopen(".int","r",stdin);
//freopen(".out","w",stdout);
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << khoangcach(a, b) << endl;
    cout << heso(a, b).A << " " << heso(a, b).B << " " << heso(a, b).C;
    return 0;
}
