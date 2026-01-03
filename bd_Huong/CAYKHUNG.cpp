#include<iostream>
#include<algorithm>

using namespace std;

struct canh {int u, v, val;};
int cha[10005];
int n , m;
canh a[10005];
int cnt[100005];

bool cmp(canh x, canh y) {
    return x.val < y.val;
}

int tim(int u) {
    if(u == cha[u])return u;
    cha[u] = tim(cha[u]);
    return cha[u];
}

bool ghep(int u , int v){
    u = tim(u);
    v = tim(v);
    if(u == v)return false;
    if(cnt[u] < cnt[v]) swap(u , v);
    cha[v] = u;
    cnt[u] += cnt[v];
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("CAYKHUNG.inp","r",stdin);
    //freopen("CAYKHUNG.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i += 1)cin >> a[i].u >> a[i].v >> a[i].val;
    for (int i = 1; i <= n; i += 1)cha[i] = i;
    sort(a + 1, a + m + 1, cmp);
    int kq = 0;
    for (int i = 1; i <= m; i += 1) {
        if (ghep(a[i].u, a[i].v) == true)kq += a[i].val;
    }
    cout << kq;
    return 0;
}
