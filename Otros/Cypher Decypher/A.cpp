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

void solve();
void criba(int n);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; 
    cin>>t;
    //t = 1;
    criba(1e+6+1);
    
    while(t--){
        solve();
    }

    return 0;
}

vector<bool> isPrime;
vector<int> primes;
vll prefix;

void criba(int n) {
    isPrime = vector<bool>(n, true);
    primes = vector<int>();
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int h=2; h*i<n; ++h) isPrime[i*h] = 0;
        }
    }
    
    prefix = vll(n);
    
    prefix[0] = isPrime[0];
    
    for(int v = 1; v<n; v++){
        prefix[v] = prefix[v-1] + isPrime[v]; 
    }
}

void solve(){
    ll i, j; cin>>i>>j;
    cout<<prefix[j] - prefix[i-1]<<el;
}