#include <iostream>
#include<math.h>
using namespace std;
bool check(int n){
    int s=0;
    for(int i=1;i<=sqrt(n);i+=1) {
		if(n%i==0){
            if(i==n/i)s+=i;
            else s=s+i+(n/i);
		}
	}
	s=s-n;
	if(s>n)return true;
	return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("RICHNUM.INP ","r",stdin);
    freopen("RICHNUM.OUT ","w",stdout);
    int l,r;cin>>l>>r;int kq=0;
    for(int i=l;i<=r;i+=1){
        if(check(i)==1)kq+=1;
    }
    cout<<kq;
    return 0;
}

