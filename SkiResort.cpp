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

ll sumatoriaGauss(ll n) {
    return (n == 1) ? 1 : (n * (n+1)) / 2;
}

const int MAX = 1e3+5;
const ll MODULO = 998244353;
long long factorialTable[MAX];

void precomputeFactorials() {
    factorialTable[0] = 1;
    for (int i = 1; i < MAX; i++) {
        factorialTable[i] = (factorialTable[i - 1] * i) % MODULO;
    }
}

long long factorial(int n) {
    return factorialTable[n];
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
    ll n, k, q; cin>>n>>k>>q;
    vll array(n), diasMalos;
    ll combinaciones = 0;

    rep(i, 0, n){
        cin>>array[i];
        if(array[i] > q) {
            diasMalos.push_back(i+1);
        }
    }
    
    if(diasMalos.size() == n) {
        cout<<0<<el;
        return;
    }

    if(diasMalos.size() == 0) {
        cout<<sumatoriaGauss(n - (k - 1))<<el;
        return;
    }

    rep(i, 0, diasMalos.size()) {
        ll diaMalo = diasMalos[i];
        ll cantidadDiasBuenos;
        ll bandera = false;

        if(i != 0 && diaMalo - diasMalos[i-1] - 1 >= k) {
            cantidadDiasBuenos = diaMalo - diasMalos[i-1] - 1; 
            combinaciones += sumatoriaGauss(cantidadDiasBuenos - (k - 1));
        }
        else if(i == 0 && diaMalo - 1 >= k) {
            cantidadDiasBuenos = diaMalo - 1;
            combinaciones += sumatoriaGauss(cantidadDiasBuenos - (k - 1));
        }
    }

    if(diasMalos[diasMalos.size() - 1] != n) {
        ll cantidasDiasBuenos = n - diasMalos[diasMalos.size() - 1];

        if(cantidasDiasBuenos >= k) {
            combinaciones += sumatoriaGauss(cantidasDiasBuenos - (k - 1));
        }
    }

    cout<<combinaciones<<el;
}