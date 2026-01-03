#include<bits/stdc++.h>
    using namespace std;
    long t, n, a[1001];
void inp(){
    vector<int> adj[1000001];
    cin >> n;
    for(long i = 1; i <= n; i++){
    cin >> a[i];
                                }
    adj[a[1]].push_back(a[1]);
    for(long i = 1; i <= n; i++){
        if(adj[a[i]].size()){
            for(long j = 0; j < adj[a[i]].size(); j++){ 
                if(adj[a[i]][j] != adj[a[i]][j-1]){
                if(adj[a[i]][j] - 1 != 0)
                adj[a[i] + adj[a[i]][j] - 1].push_back(adj[a[i]][j] - 1);
                adj[a[i] + adj[a[i]][j]].push_back(adj[a[i]][j]);
                adj[a[i] + adj[a[i]][j] + 1].push_back(adj[a[i]][j] + 1);
                }
            }   
        }
    }
    if(adj[a[n]].size())
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
}
    int main(){
        //freopen("Reader.inp","r",stdin);
        //freopen("Reader.out","w",stdout);
        cin >> t;
        while(t--){
            inp();
        }
    }