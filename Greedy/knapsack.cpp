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
bool cmp(const pair<double, double> &a, const pair<double, double> &b)
{
    return (a.second / a.first) > (b.second / b.first); // Descending order
}
double knapseek(vector<pair<double, double>> &items, double capacity)
{
    sort(all(items), cmp);
    double totalValue = 0.0;
    for (ll i = 0; i < items.size(); i++)
    {
        double weight = items[i].first;
        double value = items[i].second;
        if (capacity > 0 && weight <= capacity)
        {
            capacity -= weight;
            totalValue += value;
        }
        else if (capacity > 0 && weight > capacity)
        {
            totalValue += (capacity / weight) * value;
            break;
        }
    }
    return totalValue;
}
void solve()
{
    vector<pair<double, double>> items;
    ll n;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    double capacity;
    cin >> capacity;
    for (ll i = 0; i < n; i++)
    {
        double weight, value;
        cin >> weight >> value;
        items.push_back({weight, value});
    }
    double maxValue = knapseek(items, capacity);
    for (ll i = 0; i < n; i++)
        cout << "weight: " << items[i].first << ", value: " << items[i].second << nl;
    cout << "Maximum value in Knapsack: " << maxValue << nl;
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