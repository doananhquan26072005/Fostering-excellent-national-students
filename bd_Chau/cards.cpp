#include <bits/stdc++.h>
using namespace std;

int A[100001],n,m,k,test;
signed main()
{	
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("cards.inp","r",stdin);
	freopen("cards.out","w",stdout);
	cin >> test;
	while (test--)
	{
		cin >> m >> n >> k;
		priority_queue <int> pq;
		map <int,int> cnt;
		int current=1,cap=0,ans=0,resv=k-1;
		for (int i=1;i<=m;i++)
		{
			cin >> A[i];
			if (cnt[A[i]]>0) continue;
			cnt[A[i]]+=1;
			bool played=0;
			while (cnt[current]>0)
			{
				played=1;
				cnt[current]--;
				ans++;current++;
			}
			if (!played)
			{
				while (cap>=k-1&&pq.size())
				{
					cap--;
					cnt[pq.top()]--;
					pq.pop();
				}
				cap++;
				pq.emplace(A[i]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
╔══╗                ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄
╚╗╔╝                ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀
╔╝(¯’v´¯)          ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
╚══’.¸.Kien An     ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄
╔♫═╗╔╗ ♥          ▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
╚╗╔╝║║♫═╦╦╦╔╗     ▀▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐   ▄▄
╔╝╚╗♫╚╣║║║║╔╣     ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█
╚═♫╝╚═╩═╩♫╩═╝     ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀
┊　　┊　　┊　　┊   ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀
┊　　┊　　┊　　┊   ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
┊　　┊　　┊　　★   ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐
┊　　┊　　☆        ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
┊　　★              ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐
☆                   ▐▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▌
                      ▀▄▄▀▀▀▀▀▄▄▀▀▀▀▀▀▀▄▄▀▀▀▀▀▄▄▀
*/

int A[100001],n,m,k,test;
int main()
{	
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("cards.inp","r",stdin);
	freopen("cards.out","w",stdout);
	cin >> test;
	while (test--)
	{
		cin >> m >> n >> k;
		priority_queue <int> pq;
		map <int,int> cnt;
		int current=1,cap=0,ans=0,resv=k-1;
		for (int i=1;i<=m;i++)
		{
			cin >> A[i];
			if (cnt[A[i]]>0) continue;
			cnt[A[i]]+=1;
			bool played=0;
			while (cnt[current]>0)
			{
				played=1;
				cnt[current]--;
				ans++;current++;
			}
			if (!played)
			{
				while (cap>=k-1&&pq.size())
				{
					cap--;
					cnt[pq.top()]--;
					pq.pop();
				}
				cap++;
				pq.emplace(A[i]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
