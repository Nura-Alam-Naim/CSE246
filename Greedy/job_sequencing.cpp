//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vp;
#define nl "\n"
#define sp ' '
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
const ll N = 1e6 + 1;
bool comp(const tuple<ll, ll, ll> &a, const tuple<ll, ll, ll> &b)
{
    return (get<2>(a) > get<2>(b));
}
void solve()
{
    ll n = 7;
    vector<tuple<ll, ll, ll>> v;
    v.push_back(make_tuple(1, 6, 70));
    v.push_back(make_tuple(2, 7, 60));
    v.push_back(make_tuple(3, 8, 30));
    v.push_back(make_tuple(4, 10, 80));
    v.push_back(make_tuple(5, 12, 20));
    v.push_back(make_tuple(6, 12, 30));
    v.push_back(make_tuple(7, 8, 80));

    sort(all(v), comp);
    vl freq(N, -1);
    ll mx = LLONG_MIN;
    ll max_profit = 0;
    for (ll i = 0; i < n;i++)
    {
        mx = max(mx, get<1>(v[i]));
        ll c = get<1>(v[i]);
        while(freq[c]!=-1)
            c--;
        if(c>-1)
        {
            freq[c] = get<0>(v[i]);
            max_profit += get<2>(v[i]);
        }   
    }
    for (ll i = 0; i <= mx;i++)
        if(freq[i]!=-1)
            cout << i << sp << freq[i] << nl;
    cout << "Max_profit: " << max_profit << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin>>tc;
    while (tc--)
        solve();
}