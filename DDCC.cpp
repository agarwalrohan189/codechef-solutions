//A kind of generic implementation of MOs Algorithm and can be used for other problems by just changing the add and remove functions.


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

int a[maxn],freq[1000005];
int n,m;
int cost;

struct query
{
	int l,r,no,block_id;

	bool operator < (const query &q2){
// 		return (q2.block_id==block_id)? r<q2.r : block_id<q2.block_id;
        if(block_id<q2.block_id) return 1;
        else if(q2.block_id<block_id) return 0;
        else return r<q2.r;
	}
};

void add(int el){
	int fx=freq[el];
	freq[el]++;
	cost-=(sq(fx)*el);
	cost+=(sq(fx+1)*el);
}

void Remove(int el){
	int fx=freq[el];
	freq[el]--;
	cost-=(sq(fx)*el);
	cost+=(sq(fx-1)*el);
}

void adjust(int s, int e, int &cl, int &cr){
    
    while(cl<s){
        Remove(a[cl]);
        cl++;
    }
    
    while(cl>s){
        cl--;
        add(a[cl]);
    }
    
    while(cr<e){
        cr++;
        add(a[cr]);
    }
    
    while(cr>e){
        Remove(a[cr]);
        cr--;
    }
}


void solve(vector<query> &queries){
    sort(all(queries));
    fill(freq,0);
    cost=0;
    vi answers(m,0);
    
    foo(i,queries[0].l,queries[0].r+1){
        add(a[i]);
    }
    int cl=queries[0].l;
    int cr=queries[0].r;
    
    answers[queries[0].no]=cost;
    
    foo(i,1,m){
        adjust(queries[i].l, queries[i].r, cl, cr);
        answers[queries[i].no]=cost;
    }
    
    fo(i,m) cout<<answers[i]<<endl;
}

signed main(){
	fastio();
	cin>>n>>m;
	fo(i,n) cin>>a[i];

	vector<query> queries(m);

	int rn=sqrt(n);
	fo(i,m){
		int u,v;
		cin>>u>>v;
		queries[i].l=u-1;
		queries[i].r=v-1;
		queries[i].no=i;
		queries[i].block_id=u/rn;

	}
	
	solve(queries);
	



}
