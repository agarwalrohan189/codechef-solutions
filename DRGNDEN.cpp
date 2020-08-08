#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb  push_back
#define show(x) cerr<<(#x)<<" : "<<x<<endl;
#define ll  long long
#define ld  long double
#define fill(a,val) memset(a,val,sizeof(a))
#define mp  make_pair
#define ff  first
#define ss  second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sq(x) ((x)*(x))
#define all(v) v.begin(),v.end()
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
#define foo(i,x,n) for(int i=x;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define w(x) int x;cin>>x;while(x--)
#define display(a,n) {fo(i,n) {cout<<a[i]<<" ";}cout<<endl;}
#define fil(a,n,val) {fo(i,n) a[i]=val; }
#define sp(x,y) cout<<fixed<<setprecision(y)<<x<<endl;
#define int ll
const ll MOD   = 1000 * 1000 * 1000 + 7;
const ll MOD2  = 998244353;
const ll N = 1000 * 1000 + 5;
const double PI  = 3.14159265;
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
ll search(vl arr, ll l, ll r, ll x) {if (r >= l) {ll mid = l + (r - l) / 2; if (arr[mid] == x)return mid; if (arr[mid] > x)return search(arr, l, mid - 1, x); return search(arr, mid + 1, r, x);} return -1;}
ll gcd(ll a, ll b) {if (!b)return a; return gcd(b, a % b);}
ll lcm(ll a , ll b) {return (a * b) / gcd(a, b);}
ll power(ll x, ll y, ll p) {ll res = 1; x = x % p; while (y > 0) { if (y & 1) res = (res * x) % p; y = y >> 1; x = (x * x) % p; } return res; }
ll modInverse(ll n, ll p) {return power(n, p - 2, p);}
const int maxn = 2e5 + 5;

int fen[maxn][2];
int h[maxn], tas[maxn], rng[maxn], lng[maxn];
int n, q;


void update(int idx, int val, int tree){
	while(idx<=n){
		fen[idx][tree]+=val;
		idx+=idx&-idx;
	}
}

int query(int idx, int tree){
	int sum=0;
	while(idx>0){
		sum+=fen[idx][tree];
		idx-=idx&-idx;
	}
	return sum;
}



signed main() {
	fastio();
	cin >> n >> q;
	foo(i, 1, n + 1) cin >> h[i];
	foo(i, 1, n + 1) cin >> tas[i];
	fill(fen,0);
	stack<int> st;

	int i = 1;
	while (i < n + 1) {
		if (st.empty() || h[i] < h[st.top()]) {
			st.push(i);
			i++;
		}
		else {
			rng[st.top()] = i;
			st.pop();
		}
	}

	while (!st.empty()) {
		rng[st.top()] = -1;
		st.pop();
	}


	i = n;
	while (i > 0) {
		if (st.empty() || h[i] < h[st.top()]) {
			st.push(i);
			i--;
		}
		else {
			lng[st.top()] = i;
			st.pop();
		}
	}

	while (!st.empty()) {
		lng[st.top()] = -1;
		st.pop();
	}


	vi rsum(n + 1,0), lsum(n + 1,0);

	foo(i, 1, n + 1) {
		rsum[i] = tas[i];
		lsum[i] = tas[i];
	}

	for (int i = n; i > 0; i--) {
		int tmp = rng[i];
		while (tmp != -1 && h[tmp] == h[i])
			tmp = rng[tmp];
		if (tmp == -1){
			continue;
		}
		rsum[i] += rsum[tmp];
	}

	foo(i, 1, n + 1) {
		int tmp = lng[i];
		while (tmp != -1 && h[tmp] == h[i])
			tmp = lng[tmp];
		if (tmp == -1){
			continue;
		}
		lsum[i] += lsum[tmp];
	}


	foo(i,1,n+1){
		update(i,rsum[i]-rsum[i-1],0);
		update(i,lsum[i]-lsum[i-1],1);
	}




	while (q--) {
		int u, a, b;
		cin >> u >> a >> b;
		if (u == 1) {
			int val=b-tas[a];
			tas[a]=b;
			// cout<<"v "<<val<<endl;
			//for fen0
			int idx=lng[a];
			if(idx==-1){
				update(1,val,0);
				update(a+1,-val,0);
			}
			else{
				update(idx+1,val,0);
				update(a+1,-val,0);
			}

			idx=rng[a];
			if(idx==-1){
				update(a,val,1);
			}
			else{
				update(a,val,1);
				update(idx,-val,1);
			}
		}
		else {
			swap(a, b);
			if (a == b) {
				cout << tas[a] << endl;
				continue;
			}
			if (a < b) { //first typ

				if (lng[b] >= a) {
					cout << -1 << endl;
					continue;
				}

				cout << (query(a,0) - query(b,0) + tas[b]) << endl;
			}
			else {

				if (rng[b] != -1 && rng[b] <= a) {
					cout << -1 << endl;
					continue;
				}

				cout << (query(a,1)- query(b,1) + tas[b] )<< endl;
			}
		}
	}

}
