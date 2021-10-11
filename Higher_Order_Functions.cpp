#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define arr(a) new ll int[a]
#define INF 1000000000000
#define MOD 1000000007
#define MOD1 998244353
#define arr1(a) new arra[a]
#define str(a) new string[a]
#define all(v) v.begin(),v.end()
#define mp(a,b) make_pair(a,b)
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}
const int N = 1000008,p=31;
//ll int pw[N],inv_pw[N],hash2[N+1],hash1[N+1],pw1[N],inv_pw1[N],hash1r[N+1],hash2r[N+1];
ll fact[N];
void factorial(ll mod){
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < N; i++)
        fact[i] = (fact[i-1] * i) % mod;
}
 ll power(ll a, ll b, ll mod){
 	ll x = 1, y = a;
 	while (b > 0){
 		if (b%2){
 			x = (x*y)%mod;
 		}
 		y = (y*y)%mod;
 		b /= 2;
 	}
 	return x%mod;
 }

ll modular_inverse(ll n, ll mod){
	return power(n, mod-2, mod);
}
//void precal()
//{
//    pw[0]=1;
//    pw1[0]=1;
//    inv_pw1[0]=1;
//    inv_pw[0]=1;
//    ll int temp=modular_inverse(p,MOD),temp1=modular_inverse(p,MOD1);
//    for(ll int i=1;i<N;i++)
//    {
//        pw[i]=(pw[i-1]*p)%MOD;
//        pw1[i]=(pw1[i-1]*p)%MOD1;
//        inv_pw1[i]=(inv_pw1[i-1]*temp1)%MOD1;
//        inv_pw[i]=(inv_pw[i-1]*temp)%MOD;
//    }
//}
//void build(string& s,ll int hash1[],ll int pw[],ll int mod)
//{
//    ll int n=s.size();
//    for(ll int i=1;i<=n;i++)
//    {
//        hash1[i]=(hash1[i-1]+(pw[i-1]*(s[i-1]-'a'+1))%mod)%mod;
//    }
//}
//ll int get_hash(ll int hash1[],ll int inv_pw[],ll int mod,ll int l,ll int r)
//{
//    if(l>r)return 0;
//    ll int res=(hash1[r]-hash1[l-1]+mod)%mod;
//    res=(res*inv_pw[l-1])%mod;
//    return res;
//}
ll nCr(ll n, ll k, ll mod){
	return (fact[n]*((modular_inverse(fact[k],mod)*modular_inverse(fact[n-k],mod))%mod))%mod;
}
//typedef struct node{
//    node* left;
//    node* right;
//    ll d;
//}node;
//node* create(ll int i)
//{
//    node* temp=new node;
//    temp->d=i;
//    temp->left=NULL;
//    temp->right=NULL;
//    return temp;
//}
//struct arra{
//    ll int a,t;
//}arr[200001];
//bool comp1(ll val,struct arra a) //arr.d in increasing order(upperbound comp function
//{
//    return val<a.d;
//}
//bool comp2(struct arra a,ll val) //arr.d in increasing order(lowerbound comp function
//{
//    return a.d<val;
//}
int f(string & s,int l,int r,vector<int>& v)
{
    if(r<l)return 0;
    int a,b=0;
    if(r!=v[l])a=f(s,l,v[l],v);
    else a=f(s,l+1,v[l]-1,v);
    if(v[l]+3<=r)
    {
        b=f(s,v[l]+3,r,v);
        return max(a+1,b);
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    string s;
    cin>>s;
    int n=s.size();
    stack<int>st;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            st.push(i);
        }
        else if(s[i]==')')
        {
            int a=st.top();
            st.pop();
            v[a]=i;
            v[i]=a;
        }
    }
    int ans=f(s,0,n-1,v);
    cout<<ans<<endl;
    return 0;
}
