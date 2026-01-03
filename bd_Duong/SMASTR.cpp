#include<bits/stdc++.h>
    using namespace std;
    long n, k, t, a[1000001];
    string s;
void inp(){
    cin >> n >> k;
    cin >> s;   s = '!' + s;
    for(long i = 1; i <= n; i++)
    a[i] = int(s[i]) - 96;
    
    for(long i = 1; i <= n; i++){
        if(k >= 27 - a[i] && a[i] != 1){
            k = k -  (27 - a[i]);
            a[i] = 1;
        }
    }
    if(a[n] + k % 26 <= 26) a[n] = a[n] + k % 26;
    else                    a[n] = (a[n] + k % 26) % 26;
    for(long i = 1; i <= n; i++)
    cout << char(a[i] + 96);
    cout << endl;
}
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        freopen("SMASTR.inp","r",stdin);
        freopen("SMASTR.out","w",stdout);
        cin >> t;
        while(t--)  inp();
    }