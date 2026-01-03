#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) ((int)(a).size())
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef tree<int,
             null_type,
             less<int>,
             rb_tree_tag,
             tree_order_statistics_node_update
            > ordered_set;
const int MAXN=1000009;
int dd[1000005];
int a[MAXN],n,k,s=0,choose[MAXN],sum[MAXN];
bool kt=false;
void backtracking(int pos){
    if (pos==n+1){
//        cout<<n<<' '<<k<<endl;
//        for(int i=1;i<=k;i++){
//            cout<<sum[i]<<' ';
//        }
//        cout<<endl;
        for(int i=1;i<=k;i++){
            if (sum[i]!=s) return;
        }

        for(int i=1;i<=n;i++){
            cout<<choose[i]<<' ';
        }
        exit(0);
    }
    for(int i=k;i>=1;i--){
        choose[pos]=i;
        if (sum[i] + a[pos] <= s){
            sum[i]+=a[pos];
            backtracking(pos+1);
            sum[i]-=a[pos];
        }

    }

}
main()
{
    fast;
    // freopen("sweets.inp","r",stdin);
    // freopen("sweets.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    if (s%k!=0){
        cout<<-1<<endl;
    }
    else{
        s=s/k;
        backtracking(1);
        cout<<-1<<endl;
    }


    if (n / 2 % k == 0) {
        int dem = 1 , cnt = 0;
        FOR(i , 1 , n / 2) {
            dd[i] = dd[n - i + 1] = dem;
            cnt += 1;
            if (cnt == n / k / 2) {
                dem += 1;
                cnt = 0;
            }
        }
        FOR(i , 1 , n) cout << dd[i] << ' ';
        return 0;
    }

    if ((n + 1) / 2 % k == 0 && n % 2 == 1) {
        int dem = 1 , cnt = (n + 1) / 2 / k;
        FOR(i , 1 , n / 2) {
            dd[i] = dd[n - i] = dem;
            dem += 1;
        }
        dd[n] = dem;
        FOR(i , 1 , n - 1) {
            dd[i] = dd[i] / cnt + 1;
            cout << dd[i] << ' ';
        }
        cout << 1;
        return 0;
    }
    return cout << -1 , 0;
}