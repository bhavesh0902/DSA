// Author : rs258
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define fr(i,a,b) for(ll i=a;i<b;i++)
#define rf(i,a,b) for(ll i=a;i>=b;i--)

#define mod 1000000007
#define endl "\n"

#define pb push_back
#define vll vector<ll>
#define vchar vector<char>
#define vstr vector<string>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vbool vector<bool>
#define vpair vector<pll>
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second

#define err() cout<<"==================================\n";
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<"\n";
#define err1(a) cout<<#a<<" "<<a<<"\n"
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<"\n"
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<"\n"

#define bs(a,n) binary_search(all(a),n)
#define lb(a,n) lower_bound(all(a),n)
#define ub(a,n) upper_bound(all(a),n)
#define dist(a,it) std::distance(a.begin(),it)
#define adv(it,n) std::advance(it, n)
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define unq(a) a.erase(std::unique(a.begin(), a.end()),a.end());
#define rev(a) reverse(all(a))

#define yes() cout<<"YES"<<endl
#define no() cout<<"NO"<<endl

auto clk = clock();

#define MAXN 101 
ll spf[MAXN];

// Function to Calculate smallest prime factor (spf) of first MAXN natural numbers
void sieve() { 
    spf[1] = 1; for (ll i=2; i<MAXN; i++) spf[i] = i; for (ll i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (ll i=3; i*i<MAXN; i++) if (spf[i] == i) for (ll j=i*i; j<MAXN; j+=i) if (spf[j]==j) spf[j] = i; 
} 

// Function to get factorization of a number 
vector<ll> getFactorization(ll x) {
    vector<ll> ret; while (x != 1) { ret.push_back(spf[x]); x = x / spf[x]; } return ret; 
}

// Function to Check whether a number is prime
bool isPrime(ll n) { 
    if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; 
    for (ll i = 5; i * i <= n; i = i + 6)  if (n % i == 0 || n % (i + 2) == 0) return false; return true; 
} 

// Function to Calculate a^b
ll power(ll a, ll b) {
    ll res = 1; while (b > 0) { if (b & 1) res = (res * a); a = (a * a); b >>= 1;} return res;
}

// Function to Calculate a^b % mod
ll modpow(ll a, ll b,ll x) {
    ll res = 1; while (b > 0) { if (b & 1) res = (res * a)%x; a = (a * a)%x; b >>= 1;} return res;
}

// Returns n^(-1) mod p 
ll modInverse(ll n, ll p) { 
    return modpow(n, p - 2, p); 
}   

// Returns nCr % p using Fermat's little theorem. 
ll nCrModPFermat(ll n, ll r,ll p) { 
    if (r == 0) return 1; 
    ll fac[n + 1]; 
    fac[0] = 1; 
    for (ll i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p; 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 

// Returns nCr
ll nCr(ll n,ll r) { 
    ll p = 1, k = 1; 
    if (n - r < r) r = n - r; 
    if (r != 0) { 
        while (r) { 
         p *= n; k *= r; 
            ll m = __gcd(p, k); 
            p /= m; k /= m; n--; r--; 
        } 
   } 
    else p = 1; 
    return p; 
}

// Longest Increasing Subsequence
vll lis(vll a) {
    ll n = a.size(),index = 0;
    vll d(n+1,1e18),in(n+1,-1),p(n,-1),subseq;
    d[0] = -1e18;
    fr(i,0,n) {
        ll j = ub(d,a[i]) - d.begin();
        if(a[i] > d[j-1] && a[i] < d[j]) {
            d[j] = a[i];
            in[j] = i;
            p[i] = in[j-1];
        }
    }
    fr(i,0,n+1) {
        if(d[i] < 1e18)
            index = in[i];
    }
    while(index != -1) {
        subseq.pb(a[index]);
        index = p[index];
    }
    rev(subseq);
    return subseq;
}

// // Diagonal Traversal of n x m matrix
// fr(l,1,n+m) 
// { 
//     ll s =  max(0ll, l-n); 
//     ll c = min({l,(m-s),n}); 
//     fr (j,0,c) 
//     {
//      cout << a[min(n,l)-j-1][s+j] << " " ;
//     }
//     cout << endl; 
// }


// Answer here : 


void solve() 
{
    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(8);
    ll t=1;
    cin>>t;
    while(t--) solve();
    #ifndef ONLINE_JUDGE
    cout << endl << "Time elapsed: " << (double)(clock() - clk) / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}