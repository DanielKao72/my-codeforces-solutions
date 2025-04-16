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
    vll digitos(n);
    ll contadorCeros = 0, contadorUnos = 0, contadorCincos = 0, contadorTres = 0, contadorDos = 0;
    ll respuesta = 0;
    
    rep(i, 0, n) {
        cin>>digitos[i];
        
        if(digitos[i] == 0) contadorCeros++;
        else if(digitos[i] == 1) contadorUnos++;
        else if(digitos[i] == 2) contadorDos++;
        else if(digitos[i] == 3) contadorTres++;
        else if(digitos[i] == 5) contadorCincos++;
        
        if(respuesta == 0 && contadorCeros >= 3 && contadorUnos >= 1 && contadorDos >= 2 && contadorTres >= 1 && contadorCincos >= 1)
            respuesta = i + 1 ;
    }

    cout<<respuesta<<el;
    return;
}