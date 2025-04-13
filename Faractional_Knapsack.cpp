//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
#define nl "\n"
#define sp ' '
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
const ll N = 1e6 + 1;
ll maxProfit(vl profit, vl weight, ll N)
{
    multimap<double, ll> ratio;
    double mx = 0;
    for (ll i = 0; i < profit.size(); i++)
        ratio.insert({(double)profit[i] / weight[i], i });

    multimap<double, ll>::reverse_iterator it;

    for (it = ratio.rbegin(); it != ratio.rend();
         it++)
    {
        double fraction = (double)N / weight[it->second];
        if (N >= 0 && N >= weight[it->ss])
        {
            mx += profit[it->ss];
            N -= weight[it->ss];
        }

        else if (N < weight[it->ss])
        {
            mx += fraction * profit[it->ss];
            break;
        }
    }
    return mx;
}
void solve()
{
    vl profit(4), weight(4);

    profit[0] = 100, profit[1] = 280,
    profit[2] = 120, profit[3] = 120;
    weight[0] = 10, weight[1] = 40,
    weight[2] = 20, weight[3] = 24;
    cout<<"Max Profit: "<<maxProfit(profit, weight, 60);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin>>tc;
    while (tc--)
        solve();
}


