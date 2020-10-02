// Author : rs258
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

ll binarySearch(vll a,ll low, ll high, ll x) {
    ll mid = (low + high) / 2;
    if(low > high) {
        return -1;
    }
    if(a[mid] == x) {
        return mid;
    } 

    if(a[mid] > x) {
        return binarySearch(a,low,mid-1,x);
    } else {
        return binarySearch(a,mid+1,high,x);
    }
}

void solve() {
    ll n,x;
    cin >> n >> x;
    vll a(n);
    for(ll i = 0 ; i < n; i++) cin >> a[i];
    cout << binarySearch(a,0,n-1,x) << endl;
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