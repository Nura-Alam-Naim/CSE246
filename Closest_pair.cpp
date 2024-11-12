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
double dis(pair<ll, ll> a, pair<ll, ll> b)
{
    return (double)sqrt((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss));
}
bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.ss < b.ss;
}
double min(double a, double b)
{
    return a < b ? a : b;
}
double close(vp &v,double d)
{
    double mn = d;
    sort(all(v), comp);
    for (ll i = 0; i < (ll)v.size(); i++)
        for (ll j = i + 1;j<min(i+7,v.size());j++)
            mn = min(dis(v[i], v[j]),mn);
    return mn;
}
double closestPath(vp &v, ll l, ll r)
{
    if (r - l <= 2)
    {
        double mn = DBL_MAX;
        for (ll i = l; i < r; i++)
            for (ll j = i + 1; j < r; j++)
                mn = min(mn, dis(v[i], v[j]));
        return mn;
    }
    ll mid = (l + r) / 2;
    double d1 = closestPath(v, l, mid);
    double d2 = closestPath(v, mid + 1, r);
    double d = min(d1, d2);
    vp strip;
    for(auto &i:v)
    {
        if((double)(abs(i.ff-v[mid].ff)<d))
            strip.pb(i);
    }
    
    double d3 = close(strip,d);
    //cout << d3 << nl;
    return min(d, d3);
}
void solve()
{
    vp v = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    //vp v = {{2, 3}, {3, 4}};
    //vp v = {{5, 5}, {10, 10}};
    // for (auto i : v)
    //     cout << i.ff << sp << i.ss << nl;
    sort(all(v));
    // double mn = DBL_MAX;
    // for (ll i = 0; i < 5; i++)
    //     for (ll j = i + 1; j < 6 ; j++)
    //             mn = min(mn,dis(v[i], v[j]));
    // cout << nl;
    cout << closestPath(v, 0, 5) << nl;
    //cout << mn << nl;
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