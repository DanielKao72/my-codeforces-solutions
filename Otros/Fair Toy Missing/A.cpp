
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t; 
    //cin>>t;
    t = 1;
    
    while(t--){
        solve();
    }

    return 0;
}

void solve(){
    mll juguetesAlice;

    rep(i,0,5){
        ll x; cin>>x;
        juguetesAlice[x]++;
    }

    rep(i,0,4){
        ll x; cin>>x;
        juguetesAlice[x]--;
    }

    for (auto juguete : juguetesAlice){
        if(juguete.second > 0){
            cout << juguete.first << el;
            return;
        }
    }
} 