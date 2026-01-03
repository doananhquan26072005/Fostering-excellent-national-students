int giaithua[65];

int Pow(int x , int y){
    if(y == 0)return 1;
    int c = Pow(x , y / 2);
    if(y % 2 == 0)return (c * c) % MOD;
    return ((c * c) % MOD * x) % MOD;
}

int C(int x , int y){
    return ((giaithua[x] * Pow(giaithua[x - y] , MOD - 2) % MOD) * Pow(giaithua[y] , MOD - 2)) % MOD;
}

    giaithua[0] = 1;
    FOR(i , 1 , 60)giaithua[i] = (giaithua[i - 1] * i) % MOD;