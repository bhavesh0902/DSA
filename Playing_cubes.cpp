#include <bits/stdc++.h>
using namespace std;

// // ordered set header files
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define ld long double
#define endl "\n"

// loops here
#define f(i,n) for(ll i=0;i<n;i++)
#define f1(i,n) for(ll i=1;i<n;i++)
#define rf(i,n) for(ll i=n-1;i>=0;i--)
#define fab(i,a,b) for(ll i=a;i<b;i++)
#define rfab(i,a,b) for(ll i=a;i>=b;i--)

#define mod 1000000007
#define maxi INT_MAX

// input here
#define c(x) ll x=0;cin>>x
#define cc(x,y) ll x=0,y=0;cin>>x>>y
#define ccc(x,y,z) ll x=0,y=0,z=0; cin>>x>>y>>z
#define cv(v,n) for(ll i=0;i<n;i++){ll e;cin>>e;v.push_back(e);}
#define ca(a,n) for(ll i=0;i<n;i++){cin>>a[i];}

// vector here
#define pb push_back
#define vll vector<ll>
#define vchar vector<char>
#define vstr vector<string>
#define vvll vector<vll>
#define vint vector<int>
#define pll pair<ll,ll>
#define vpair vector<pll>
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second

// stl func here
#define bs(a,n) binary_search(all(a),n)
#define lb(a,n) lower_bound(all(a),n)
#define ub(a,n) upper_bound(all(a),n)
#define dist(a,it) std::distance(a.begin(),it)
#define adv(it,n) std::advance(it, n)
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))

// yes/no
#define yes() cout<<"YES"<<endl
#define no() cout<<"NO"<<endl

#define err() cout<<"==================================\n";
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<"\n";
#define err1(a) cout<<#a<<" "<<a<<"\n"
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<"\n"
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<"\n"

//  // largest power of 2 less than or equal to given nobr
// ll largest_power(ll n) { ll p = (ll)log2(n);
//    return (ll)pow(2, p); }

// // check if a given nobr is power of 2
// bool isPowerOfTwo(ll n) { if(n==0) return false;
// return (ceil(log2(n)) == floor(log2(n)));  }

// // sort vector of pair by second value
// bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b){
//     return (a.second < b.second);
// }

// #define MAXN 100001
// ll spf[MAXN];

// // Function to Calculate smallest prime factor (spf) of first MAXN natural numbers
// void sieve() {
//     spf[1] = 1; for (ll i=2; i<MAXN; i++) spf[i] = i; for (ll i=4; i<MAXN; i+=2) spf[i] = 2;
//     for (ll i=3; i*i<MAXN; i++) if (spf[i] == i) for (ll j=i*i; j<MAXN; j+=i) if (spf[j]==j) spf[j] = i;
// }

// // Function to get factorization of a number (uncomment sieve function and declaration of spf, MAXN)
// vector<ll> getFactorization(ll x) {
//     vector<ll> ret; while (x != 1) { ret.push_back(spf[x]); x = x / spf[x]; } return ret;
// }

// // Function to Check whether a number is prime
// bool isPrime(ll n) {
//     if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false;
//     for (ll i = 5; i * i <= n; i = i + 6)  if (n % i == 0 || n % (i + 2) == 0) return false; return true;
// }

// // Function to Calculate a^b
// ll power(ll a, ll b) {
//     ll res = 1; while (b > 0) { if (b & 1) res = (res * a); a = (a * a); b >>= 1;} return res;
// }

// // Function to Calculate a^b % mod
// ll modpow(ll a, ll b,ll x) {
//     ll res = 1; while (b > 0) { if (b & 1) res = (res * a)%x; a = (a * a)%x; b >>= 1;} return res;
// }

// // Returns n^(-1) mod p (uncomment modpow function to use)
// ll modInverse(ll n, ll p) {
//     return modpow(n, p - 2, p);
// }

// const ll N=3e5+5;
// ll fac[N+1];
// void factorial(){
// fac[0] = 1;
// for (ll i = 1; i <= N; i++) fac[i] = (fac[i - 1] * i) % mod;
// }

// // Returns nCr % p using Fermat's little theorem. (uncomment above modInverse, modpow functions to use)
// ll nCrModPFermat(ll n, ll r,ll p) {
//     if(n<r) return 0;
//     if (r == 0) return 1;
//     return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
// }

// // Returns nCr
// ll nCr(ll n,ll r) {
//     ll p = 1, k = 1;
//     if (n - r < r) r = n - r;
//     if (r != 0) {
//         while (r) {
//          p *= n; k *= r;
//             ll m = __gcd(p, k);
//             p /= m; k /= m; n--; r--;
//         }
//    }
//     else p = 1;
//     return p;
// }

// //modular operations

// //uncomment modpow function to use
// ll divide(ll a,ll b,ll m) {
//     return (a % m) * modpow(b, m - 2) % m;
// }

// ll mul(ll a,ll b,ll m) {
//     return ((a % m) * (b % m)) % m;
// }

// ll add(ll a,ll b,ll m) {
//     return (a % m + b % m) % m;
// }

void solve()
{
   cc(a, b);
   string s1 = "0", s2 = "";
   ll n = a + b;
   ll cnt_zero = 1, cnt_one = 0;
   f(i, n - 1)
   {
      if (!(i & 1))
      {
         if (*s1.rbegin() == '0' && cnt_one < b)
         {
            s1 += '1';
            cnt_one++;
         }
         else if (*s1.rbegin() == '1' && cnt_zero < a)
         {
            s1 += '0';
            cnt_zero++;
         }
         else
         {
            if (cnt_zero < a)
            {
               s1 += '0';
               cnt_zero++;
            }
            else
            {
               s1 += '1';
               cnt_one++;
            }
         }
      }
      else
      {
         if (*s1.rbegin() == '0' && cnt_zero < a)
         {
            s1 += '0';
            cnt_zero++;
         }
         else if (*s1.rbegin() == '1' && cnt_one < b)
         {
            s1 += '1';
            cnt_one++;
         }
         else
         {
            if (cnt_zero < a)
            {
               s1 += '0';
               cnt_zero++;
            }
            else
            {
               s1 += '1';
               cnt_one++;
            }
         }
      }
   }
   cnt_zero = 0, cnt_one = 0;
   f(i, n)
   {
      if (s1[i] == '0' && cnt_one < b)
      {
         s2 += '1';
         cnt_one++;
      }
      else if (s1[i] == '1' && cnt_zero < a)
      {
         s2 += '0';
         cnt_zero++;
      }
      else
      {
         if (cnt_zero < a)
         {
            s2 += '0';
            cnt_zero++;
         }
         else
         {
            s2 += '1';
            cnt_one++;
         }
      }
   }
   // cout << s1 << " " << s2 << endl;
   ll g1_x = 0, g1_y = 0, g2_x = 0, g2_y = 0;
   f1(i, n)
   {
      if (s1[i] == s1[i - 1])
      {
         g1_x++;
      }
      else
      {
         g1_y++;
      }
      if (s2[i] == s2[i - 1])
      {
         g2_x++;
      }
      else
      {
         g2_y++;
      }
   }
   if (g1_x > g2_x)
   {
      cout << g1_x << " " << g1_y << endl;
   }
   else
   {
      cout << g2_x << " " << g2_y << endl;
   }
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   cout << fixed << setprecision(8);

   solve();
   return 0;
}
