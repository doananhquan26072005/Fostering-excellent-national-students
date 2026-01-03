
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("planet1.inp","r",stdin);
    freopen("planet1.out","w",stdout);
    string a[505];
    int r,c;
    cin >> r >> c;
    for (int i=0;i<r;i++) cin >> a[i];
    int x,y;
    cin >> x >> y;
    x--; 
    y--;
    int dx[4]{-1,0,1,0};
    int dy[4]{0,1,0,-1};    
    int res=-1;
    for (int i=0;i<4;i++) 
    {
        int cur=0,u=x,v=y,dir=i;
        while (u>=0&&u<r&&v>=0&&v<c) 
        {
            if (cur>4*r*c) return cout << "Voyager",0;
            if (a[u][v]=='C') break;
            if (a[u][v]=='\\') dir^=3;
            else if (a[u][v]=='/') dir^=1;
            else assert(a[u][v]=='.');
            cur++;
            u+=dx[dir];
            v+=dy[dir];
        }
        res=max(res,cur);
    }
    cout << res;
}