#include<bits/stdc++.h>
using namespace std;

const long N=1e5+10;
long n,q,A[N],pos1,pos2,p1,p2,x,y;
vector<long> D[N*4];
void build(long id,long l,long r){ 
    if(l==r){
        D[id].push_back(A[l]);
        return;
    }
    long mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    l=0;
    for(long i=0; i<D[id*2].size(); i++){
        while(D[id*2+1][l]<=D[id*2][i] && l<D[id*2+1].size()){ D[id].push_back(D[id*2+1][l]); l++;}
        D[id].push_back(D[id*2][i]);
        }
    for(long i=l; i<D[id*2+1].size(); i++) D[id].push_back(D[id*2+1][i]);
    for(long i=0; i<D[id].size(); i++) cout<<D[id][i]<<' ';
    cout<<'\n';
}
void find(long id,long l,long r,long u,long v,long val){
    if(r<u || l>v) return;
    if(u<=l && r<=v){
        p1=lower_bound(D[id].begin(),D[id].end(),val)-D[id].begin();
        p2=upper_bound(D[id].begin(),D[id].end(),val)-D[id].begin();
        if(p1!=0) {pos1+=p1;}
        if(p2!=0) {pos2+=p2;}
        return;
    }
    long mid=(l+r)>>1;
    find(id*2,l,mid,u,v,val);
    find(id*2+1,mid+1,r,u,v,val);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(long i=1; i<=n; i++){
        cin>>A[i];
    }
    build(1,1,n);
    while(q--){
        cin>>x>>y;
        long l=1;
        long r=1000;
        while(l<=r){
            long mid=(l+r)>>1;
            pos1=0;
            pos2=0;
            find(1,1,n,x,y,mid);
            if(mid==4) cout<<pos1<<' '<<pos2<<'\n';
            if(pos1<=(y-x+2)/2 && (y-x+2)/2<=pos2){
                cout<<mid<<'\n';
                break;
            }
            else if(pos1>(y-x+2)/2) r=mid-1;
            else l=mid+1;
        }
    }




    return 0;
}