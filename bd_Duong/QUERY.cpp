//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define taskname "QUERY"
#define endl "\n"
#define X first
#define Y second
#define Ha dethuong

using namespace std;
typedef pair <int, int> ii;
const long long oo = 1e18 + 3;
const long long mod = 1e9 + 7; // 998244353
const int N = 2e5 + 3;
struct node
{
    long long odd;
    long long sum;
    long long maxx;
};

int n, q;
node tree[4 * N];

node operator + (node x, node y)
{
    node res;
    res.maxx = max(x.maxx, y. maxx);
    res.sum = x.sum + y.sum;
    res.odd = x.odd + y.odd;
    return res;
}

void update(int index, int l, int r, int pos, long long val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        tree[index].sum = val;
        tree[index].odd = val % 2;
        tree[index].maxx = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(index << 1, l, mid, pos, val);
    update(index << 1 | 1, mid + 1, r, pos, val);
    tree[index] = tree[index << 1] + tree[index << 1 | 1];
}

node get(int index, int l, int r, int x, int y)
{
    if (x > r || y < l)
    {
        return {0, 0, 0};
    }
    if (x <= l && y >= r)
    {
        return tree[index];
    }
    int mid = (l + r) >> 1;
    node curr1 = get(index << 1, l, mid, x, y);
    node curr2 = get(index << 1 | 1, mid + 1, r, x, y);
    return curr1 + curr2;
}

int main()
{
   freopen (taskname".inp", "r", stdin);
   freopen (taskname".out", "w", stdout);

//    freopen ("test.inp", "r", stdin);
//    freopen ("test.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    long long x;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> x;
        update(1, 1, n, i, x);
    }
    int state, l, r;
    node curr;
    for (int i = 1; i <= q; ++ i)
    {
        cin >> state >> l >> r;
        if (state == 1)
        {
            update(1, 1, n, l, r);
        }
        else
        {
            curr = get(1, 1, n, l, r);
//            cout << curr.maxx << endl;
            if (curr.maxx % 2 == 1)
            {
                cout << (curr.maxx * (r - l + 1) - (curr.sum - (r - l + 1 - curr.odd))) / 2 << endl;
            }
            else
            {
                cout << (curr.maxx * (r - l + 1) - (curr.sum - curr.odd)) / 2 << endl;
            }
        }
    }

    return 0;
}



//          ¯\ /¯                                                         ▄
//          [O.o]      ▄   ▄                                             ██▌
//         //)..)   ▄▄ █▀█▀█        ♥♥            █   █              ▄▄███▀
//  ╔♫═╗╔╗  -"--"- █ █▌█▄█▄█      █♥▄▄♥█      ▄█▄ █▀█▀█ ▄█▄         █████ ▄█
//  ╚╗╔╝║║♫═╦╦╦╔╗  █    ███   ██╗ ██████╗ ██╗▀▀████▄█▄████▀▀      ▄██▄█████▀
//  ╔╝╚╗♫╚╣║║║║╔╣  █   ████╗ ██╔╝██╔═══██╗██║   ██▀█▀█▀         ▄█████████
//  ╚═♫╝╚═╩═╩♫╩═╝   ▀▀▀███████╔╝ ██║▌ ▌██║██║   ██║              ▄███████▌
//      ▄▄ ▄▄▀▀▄▀▀▄    ▀  ███╔╝  ██║ ═ ██║██║   ██║            ▄█████████
//     ███████   ▄▀        ██║   ╚██████╔╝╚██████╔╝         ▄███████████▌
//     ▀█████▀▀▄▀          ╚═╝    ╚═════╝  ╚═════╝    ▄▄▄▄██████████████▌
//       ▀█▀  █                █                  ▄▄███████████████████▌
//           ▐██   ▄███████▄  ██▌               ▄██████████████████████▌
//           ████████████████████              ████████████████████████
//          █▐ ▀▀████████████▀▀        █     ▐██████████▌ ▀▀███████████
//          ▌▐  ██▄▀██████▀▄██        ▐██   ▄██████████▌         ▀██▐█▌
//         ▐┼▐  █▄═o═▄██▄═O═▄█         ██████ █████████           ▐█▐█▌
//         ▐┼▐  ██████████████          ▀▀▀▀   ██████▀            ▐█▐█▌
//         ▐▄▐████ ▀▐▐▀█ █ ▌▐██▄                █████▌            ▐█▐█▌
//           █████          ▐███▌               ███▀██             █ █▌
//           █▀▀██▄█ ▄   ▐ ▄███▀               ▐██   ██        ▄▄████████▄
//           █  ███████▄██████                 ██▌    █▄      ▄███████████████████
//              ██████████████                 ▐██     ██▄▄███████████████████████
//              █████████▐▌██▌                  ▐██  ▄████████████████████████████
//              ▐▀▐ ▌▀█▀ ▐ █               ▄▄█████████████████████████████████████
//                    ▐    ▌        ▄▄████████████████████████████████████████████
