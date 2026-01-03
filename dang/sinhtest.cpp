#include<bits/stdc++.h>
using namespace std;

#define int long long int

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)

long long random(int l , int r) {
    return rand() % (r - l + 1) + l;
}

int ntest = 20;
int dd[100005];

signed main() {
    // freopen("test.inp","r",stdin);
    // freopen("test.out","w",stdout);
    srand(time(NULL));
    // FOR(itest , 1 , ntest) {
    //     ofstream inp("tonga.inp");//doi ten
    //     // phan sinh test
    //         int n = random(100 , 1000) , l = random(100 , 1000);
    //         inp << n << ' ' << l << endl;
    //         FOR(i , 1 , n) {
    //             int x = random(1 , 1000 - 1) ;
    //             inp << x << ' ' << random(x + 1, 1000) << endl;
    //         }
    //         int m = random(100 , 1000);
    //         inp << m << endl;
    //         FOR(i , 1 , m) inp << random(1 , l - 1) << endl;
    //     inp.close();
    //     system("tonga.exe");
    //     system("trau.exe");
    //     if (system("fc tonga.out tonga.ans") != 0) {
    //         cout << "TEST " << itest << " : WRONG!\n";
    //         // cout << "YES";
    //         return 0;
    //     }
    //     else cout << "TEST " << itest << " : CORRECT!\n";
    // }

    cout << 10 << endl;
    FOR(i , 1 , 10){
        int a = random(1 , 15);
        int x = random(1,a);
        cout << a << ' ' << random(x,15) << ' ' << x << endl;
    }
    return 0;
}
/*
───────────────────────────────────────
───▐▀▄───────▄▀▌───▄▄▄▄▄▄▄─────────────
───▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀▄──────────
──▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄────────
──▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄──────
▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌─────
▀▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐───▄▄
▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█
▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀─
▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀───
▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌────
─▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐─────
─▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌─────
──▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐──────
──▐▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▌──────
────▀▄▄▀▀▀▀▀▄▄▀▀▀▀▀▀▀▄▄▀▀▀▀▀▄▄▀────────
*/
