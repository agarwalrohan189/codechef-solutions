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
#define int long long
const ll MOD   = 1000*1000*1000+7;
const ll MOD2  = 998244353;
const ll N = 1000*1000+5;
const double PI  = 3.14159265;
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
ll search(vl arr, ll l, ll r, ll x){if (r >= l) {ll mid = l + (r - l) / 2;if (arr[mid] == x)return mid;if (arr[mid] > x)return search(arr, l, mid - 1, x);return search(arr, mid + 1, r, x);} return -1;}
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll lcm(ll a , ll b){return (a*b)/ gcd(a,b);}
ll power(ll x, ll y, ll p){ll res = 1;x = x % p;while (y > 0){ if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p; } return res; }
ll modInverse(ll n, ll p){return power(n, p-2, p);}
const int maxn=3e5+5;

signed main(){
	fastio();
	w(t){
		int n,x;
		cin>>n>>x;
		multiset<int> nat;
		int y,days=0;
		fo(i,n){
			cin>>y;
			nat.insert(y);
		}

		nat.insert(0);

		while(nat.size()>1){
			auto it=nat.end();
			it--;
			if(*it<=x){
				days+=nat.size()-1;
				break;
			}
			it=nat.lower_bound(x);
			if(*it!=x)
				it--;
			int cur=*it;
			if(cur*2>=x){
				x=2*cur;
				nat.erase(it);
				days++;
			}
			else{
				auto itt=nat.end();
				itt--;
				cur=*itt;
				if(x<(cur+1)/2){
					x=x*2;
					days++;
				}
				else{
					days+=nat.size();
					break;
				}
			}

		}
		cout<<days<<endl;
	}
}
