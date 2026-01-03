#include <bits/stdc++.h>
using namespace std;
const int SIZE = 50000;
const int MAX = 200;

int mu10(int x, int a) {
	int k = 1;
	for(int i= 1;i<= x;i+=1)
		k = (k * 10) % a;
	return k;
}

struct Pos {
	int x, y;
	Pos(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
};

template<typename T>
class Queue {
public:
	T arr[SIZE];
	int first, last;
	Queue() {
		first = last = 0;
	}
	void clear() {
		first = last = 0;
	}
	void push(const T& x) {
		arr[(++last) % SIZE] = x;
	}
	T pop() {
		return arr[(++first) % SIZE];
	}
	bool isNotEmpty() {
		return first < last;
	}
};

int T, N;
Queue<Pos> Q;
int F[MAX + 1][MAX + 1];
bool Check[MAX + 1][MAX + 1];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

int mu10(int x, int a);

int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("NUM86.inp","r",stdin);
freopen("NUM86.out","w",stdout);
		cin >> N;
		for(int i=0;i<=MAX;i+=1)
			for(int j=0;j<=MAX;j+=1){
                Check[i][j] = false;
                F[i][j] = -1;
            }
		Q.clear();
		Q.push(Pos(0, 0));
		Check[0][0] = true;
		F[0][0] = 0;
		bool found = false;

		while (Q.isNotEmpty() && found == false) {
			Pos x = Q.pop();
			for(int i=0;i<= 1;i+=1) {
				int nx = x.x + dx[i];
				int ny = x.y + dy[i];
				if (Check[nx][ny] == false && nx + ny <= MAX) {
					Check[nx][ny] = true;
					if (i == 0) {
						F[nx][ny] = (F[nx][ny - 1] * 10 + 6) % N;
					}
					else F[nx][ny] = (8 * mu10(nx - 1 + ny, N) + F[nx - 1][ny]) % N;
					if (F[nx][ny] == 0){
						for(int k=1;k<=nx;k+=1) cout << 8;
						for(int k=1;k<=ny;k+=1) cout << 6;
						found = true;
						break;
					}
					Q.push(Pos(nx, ny));
				}
			}
		}
		if (found == false) cout << -1 << endl;
	return 0;
}
