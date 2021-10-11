#include <bits/stdc++.h>
#define rep(i,n) for(long long int i=0;i<n;i++)
#define repinv(i,n) for(long long int i=n-1;i>=0;i--)
#define for1(i,n) for(long long int i=1;i<=n;i++)
#define loop(i,a,b,k) for(long long int i=a;i<=b;i=i+k)
 
#define pb push_back
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vb vector<bool>
#define vstr vector<string>
#define vd vector<double>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define maxpq priority_queue<int,vector<int>>
#define minpq priority_queue<int,vector<int>,greater<int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define mp make_pair
 
#define modulo 1000000007
#define longmodulo 1000000000000000000
 
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
     
	int n;
	cin>>n;
	ll a[n];
	ll b[n];
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n){
		cin>>b[i];
	}
	ll diff[n];
 
	ll cnt=0;
	ll sum=0;
	rep(i,n){
		diff[i]= a[i]-b[i];
	}
	sort(diff,diff+n);
	rep(i,n){
		if(diff[i]>0){
			cnt++;
		}
		else{
			ll up = upper_bound(diff , diff+n , -1*diff[i]) - diff;
			sum = sum+ n-up;
		}
	}
		
		
	sum = sum+ (cnt*(cnt-1))/2;
	cout<<sum<<endl;
	
	
	return 0;
}

