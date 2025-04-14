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
    
    while(t--) solve();

    return 0;
}

void solve(){
    string cad1, cad2, cad3; cin>>cad1>>cad2>>cad3;
    cout<<cad1[0]<< ""<<cad2[0]<<""<<cad3[0]<<el;
}