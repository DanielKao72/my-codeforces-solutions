#include<bits/stdc++.h>

using namespace std;

#define el "\n"
#define ll long long
#define yes cout << "YES" << el
#define no cout << "NO" << el
#define vll vector<ll>
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define mll map<ll,ll>
#define bob cout<<"Bob"<<el
#define alice cout<<"Alice"<<el

vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

vector<bool> sieveOfEratosthenes(ll n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// const vll& a
int binarySearch(ll k) {
    ll inicio = -1, fin = k + 1; 
    // Inicio apunta a la posicion del primer elemento del arreglo que cumple con la condicion
    // Fin apunta a la posicion del ultimo elemento del arreglo que cumple con la condicion


    while(inicio + 1 < fin){
        ll mitad = inicio + (fin - inicio) / 2;

        if(k >= ((mitad*(mitad+1))/2)){
            inicio = mitad;
        }
        else{
            fin = mitad;
        }
    }
    
    return inicio+1; 
}


void solve();

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; 
    cin>>t;
    //t = 1;
    
    while(t--){
        solve();
    }

    return 0;
}

void solve(){
    ll ans, n; cin>>n;
    ll maximoMayorQue = -1, minimoMenorQue = 1e9 + 1;
    vll numerosExcluidos;
    
    rep(i, 0, n) {
        ll a, x; cin>>a>>x;

        if(a == 1){
            maximoMayorQue = max(maximoMayorQue, x);
        }
        else if(a == 2) {
            minimoMenorQue = min(minimoMenorQue, x);
        }
        else {
            numerosExcluidos.push_back(x);
        }
    }

    if(maximoMayorQue > minimoMenorQue) {
        cout<<0<<el; 
        return;
    }

    ans = minimoMenorQue - maximoMayorQue + 1;

    for(const auto & numero : numerosExcluidos) {
        if(numero >= maximoMayorQue && numero <= minimoMenorQue) {
            ans--;
        }
    }

    cout<<ans<<el;
    
    return;
}