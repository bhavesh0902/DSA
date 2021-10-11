
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;
template <typename T>
using omultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, 
tree_order_statistics_node_update>; 

#define ll         long long
#define ld         long double
#define endl       "\n"
#define pb         push_back
#define vll        vector<ll>
#define vvll       vector<vll>
#define pll        pair<ll,ll>
#define vbool      vector<bool>
#define vvbool     vector<vbool>
#define vstr       vector<string>
#define vpair      vector<pll>
#define F          first
#define S          second
#define mp(x,y)    make_pair(x,y)
#define all(a)     a.begin(),a.end()
#define rall(a)    a.rbegin(),a.rend()
#define rev(a)     reverse(all(a))
#define unq(a)     a.erase(std::unique(all(a)),a.end());
#define fr(i,a,b)  for(ll i=a;i<b;i++)
#define rf(i,a,b)  for(ll i=a;i>=b;i--)
#define yes()      cout<<"YES"<<endl
#define no()       cout<<"NO"<<endl
#define err()      cout<<"===========\n";
#define errA(A)    for(auto i:A) cout<<i<<" ";cout<<"\n";
#define err1(a)    cout<<#a<<" "<<a<<"\n"
#define err2(a,b)  cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"

const ll mod1 =    1000000007;
const ll mod2 =    998244353;
const ll infi =    1e18;
const ld eps  =    1e-9;

ll test_case = 0;
void google() {
    test_case++;
    cout << "Case #" << test_case << ": ";
}

ll pwr(ll a, ll b) {
    ll res = 1;
    while (b > 0) { 
        if (b & 1) res = (res * a);   
        a = (a * a); b >>= 1;
    }
    return res;
}

ll modpwr(ll a, ll b, ll x = mod1) {
    ll res = 1; 
    while (b > 0) { 
        if (b & 1) res = (res * a) % x;
        a = (a * a) % x; b >>= 1;
    } 
    return res;
}

ll modInverse(ll n, ll p = mod1) { 
    return modpwr(n, p - 2, p); 
}

void solve() {
    ll n;
    cin >> n;
    vll f(n + 1, 1);
    fr(i, 1, n + 1) {
        f[i] = (f[i - 1] * i) % mod2;
    }
    vll a(n), b(n);
    map<ll, ll> ma, mb;
    map<pll, ll> mp;
    fr(i, 0, n) {
        cin >> a[i] >> b[i];
        ma[a[i]]++; mb[b[i]]++;
        mp[{a[i], b[i]}]++;
    }
    ll ans = f[n];
    ll r = 1;
    for(auto i : ma) {
        (r *= f[i.S]) %= mod2;
    }
    (ans += mod2 - r) % mod2;
    r = 1;
    for(auto i : mb) {
        (r *= f[i.S]) %= mod2;
    }
    (ans += mod2 - r) % mod2;
    r = 1;
    sort(all(a)); sort(all(b));
    fr(i, 0, n) {
        if(mp[{a[i], b[i]}] == 0) {
            r = 0;
            break;
        } else {
            (r *= mp[{a[i], b[i]}]) %= mod2;
            mp[{a[i], b[i]}]--;
        }
    }
    (ans += r) %= mod2;
    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1; 
    while(t--) solve();
    return 0;
}
