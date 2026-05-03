#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

const int INF = 1e9;

void solve(){
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll m;
    cin >> m;

    // {maxi, mini}
    vii dp(n+m+1);
    vi a(n+m+1, 0);
    vi b(n+m+1, 0);

    for (ll i = n-1; i >= 0; --i) {
        if (s[i] != 'b') {
            a[i] = 1 + b[i+1];
        }
        if (s[i] != 'a') {
            b[i] = 1 + a[i+1];
        }
    }

    vi c(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') c[i] = 1;
    }
    for (int i = 1; i < n; ++i) c[i] += c[i-1];

    auto find_cost = [&](int l, int r) -> int {
        int response = c[r];
        if (l-1 >= 0) response -= c[l-1];
        return response;
    };

    for (ll i = n-1; i >= 0; --i) {
        // encuentro la maxima longitud de segmento ababab.... que puedo crear desde aqui
        ll len = a[i];

        if (len >= m) {
            pii wb = dp[i+m];
            wb.first++;
            // hallar el costo
            int cost = find_cost(i, i+m-1);
            // cout << i << " cost: " << cost << endl;

            wb.second += cost;

            if (wb.first > dp[i].first) {
                dp[i] = wb;
            } else if (wb.first == dp[i].first) {
                dp[i].second = min(dp[i].second, wb.second);
            }
        } 

        if (dp[i+1].first > dp[i].first) {
            dp[i] = dp[i+1];
        } else if (dp[i+1].first == dp[i].first) {
            dp[i].second = min(dp[i].second, dp[i+1].second);
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << "i: " << i << " " << dp[i].first << " " << dp[i].second << endl;
    // }
    cout << dp[0].second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; 
    tt = 1;
    // cin >> tt;
    while(tt--) solve();
}
