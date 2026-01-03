#include<bits/stdc++.h>

using namespace std;
int n,m,s;
bool dinh[1005];
int u,v;
vector<int>a[10005];


void DFS(int s){
    dinh[s]=true;
    cout<<s<<endl;
    for(int i=0;i<a[s].size();i+=1){
        if(dinh[a[s][i]]==false)DFS(a[s][i]);
    }
}


int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    memset(dinh,false,sizeof(dinh));
    cin>>n>>m>>s;
    for(int i=1;i<=m;i+=1){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(s);
    return 0;
}
