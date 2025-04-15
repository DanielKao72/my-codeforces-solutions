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
#define ALL(x) x.begin(), x.end() 

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
    ll n; cin>>n;
    vll arreglo(n);
    ll numeroMinimo = 1e+9+1;
    rep(i, 0, n) {
        cin>>arreglo[i];
        numeroMinimo = min(arreglo[i], numeroMinimo);
    }

    if(numeroMinimo == arreglo[0]) bob;
    else alice;
}