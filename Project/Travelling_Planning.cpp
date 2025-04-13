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
const ll N = 10;                                    // Nodes
const ll M = 15;                                    // Edges: max: (N*(N-1))/2
vector<vl> dis(N + 1, vl(N + 1, 0));
vector<vl> cst(N + 1, vl(N + 1, 0));
vector<vl> tim(N + 1, vl(N + 1, 0));
ll cnt = 0;
void initial()
{
    srand(time(0));
    while (cnt < M)
    {
        ll u = 1 + rand() % N;
        ll v = 1 + rand() % N;

        if (u == v or dis[u][v])
            continue;

        ll d = 2 + rand() % 99;
        ll c = 5 + rand() % 499;
        ll t = 2 + rand() % 149;

        dis[u][v] = d;
        cst[u][v] = c;
        tim[u][v] = t;

        dis[v][u] = d;
        cst[v][u] = c;
        tim[v][u] = t;

        cnt++;
    }
}
void print_route(vl &route)
{
    cout << "The route: ";
    for (ll i = 0; i < (ll)route.size(); i++)
    {
        cout << route[i];
        if (i == (ll)route.size() - 1)
            cout << nl;
        else
            cout << " -> ";
    }
}
void print()
{
    cout << "Distance Graph: " << nl;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 1; j <= N; j++)
            cout << dis[i][j] << sp;
        cout << nl;
    }
    cout << nl;
    cout << "Cost Graph: " << nl;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 1; j <= N; j++)
            cout << cst[i][j] << sp;
        cout << nl;
    }
    cout << nl;
    cout << "Time Graph: " << nl;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 1; j <= N; j++)
            cout << tim[i][j] << sp;
        cout << nl;
    }
    cout << nl << nl;
}
ll minFind(vector<bool> &visited, vl &dist)
{
    ll mn = LLONG_MAX;
    ll node = -1;
    for (ll i = 1; i <= N; i++)
    {
        if (!visited[i] and dist[i] <= mn)
        {
            mn = dist[i];
            node = i;
        }
    }
    return node;
}
vl dijstra(ll src, ll target, ll &req, vector<vl> &graph)
{
    vl dist(N + 1, LLONG_MAX);
    vector<bool> visited(N + 1, false);
    vl parent(N + 1, 0);
    dist[src] = 0;
    parent[src] = src;
    for (ll i = 1; i <= N; i++)
    {
        ll u = minFind(visited, dist);
        if (u == -1)
            break;
        visited[u] = true;
        for (ll v = 1; v <= N; v++)
            if (!visited[v] and graph[u][v] and dist[u] != LLONG_MAX and dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }
    ll t = target;
    vl route;
    if (!parent[t])
    {
        req = -1;
        return route;
    }
    route.pb(target);
    while (t != src)
    {
        if (!parent[t])
        {
            req = -1;
            return route;
        }
        route.pb(parent[t]);
        t = parent[t];
    }
    req = dist[target];
    reverse(all(route));
    return route;
}
void calc(vl &route, ll &tot_dis, ll &tot_tm, ll &tot_cst)
{
    ll u = route[0];
    for (ll i = 1; i < (ll)route.size(); i++)
    {
        tot_dis += dis[u][route[i]];
        tot_tm += tim[u][route[i]];
        tot_cst += cst[u][route[i]];
        u = route[i];
    }
}
void shortest_distance()
{
    cout << "\n# Minimum Distance from source to target #" << nl;
    ll src, target;
    src = 1;
    target = 5;
    cout << "Enter your Source Node (Between 1 to " << N << " ): ";
    cin >> src;
    cout << "Enter your Target Node (Between 1 to " << N << " ): ";
    cin >> target;
    ll req = -1;
    vl route = dijstra(src, target, req, dis);
    if (req == -1)
    {
        cout << "No Path Exixts" << nl;
        return;
    }
    ll tot_dis = 0, tot_tm = 0, tot_cst = 0;
    calc(route, tot_dis, tot_tm, tot_cst);
    cout << "Minimum Distance From: " << src << " to " << target << " is: " << tot_dis << nl;
    print_route(route);
    cout << "Total Cost: " << tot_cst << nl;
    cout << "Total Required Time: " << tot_tm << nl;
    cout << nl;
}
void minimum_time()
{
    cout << "\n# Miminum Required Time from source to target #" << nl;
    ll src, target;
    src = 1;
    target = 5;
    cout << "Enter your Source Node (Between 1 to " << N << " ): ";
    cin >> src;
    cout << "Enter your Target Node (Between 1 to " << N << " ): ";
    cin >> target;
    ll req = -1;
    vl route = dijstra(src, target, req, tim);
    if (req == -1)
    {
        cout << "No Path Exixts" << nl;
        return;
    }
    ll tot_dis = 0, tot_tm = 0, tot_cst = 0;
    calc(route, tot_dis, tot_tm, tot_cst);
    cout << "Minimum Required time From: " << src << " to " << target << " is: " << tot_tm << nl;
    cout << "The route: ";
    print_route(route);
    cout << "Total Cost: " << tot_cst << nl;
    cout << "Total Distance: " << tot_dis << nl;
    cout << nl;
}
void minimum_cost()
{
    cout << "\n# Miminum Required Cost from source to target #" << nl;
    ll src, target;
    src = 1;
    target = 5;
    cout << "Enter your Source Node (Between 1 to " << N << " ): ";
    cin >> src;
    cout << "Enter your Target Node (Between 1 to " << N << " ): ";
    cin >> target;
    ll req = -1;
    vl route = dijstra(src, target, req, cst);
    if (req == -1)
    {
        cout << "No Path Exixts" << nl;
        return;
    }
    ll tot_dis = 0, tot_tm = 0, tot_cst = 0;
    calc(route, tot_dis, tot_tm, tot_cst);
    cout << "Minimum Required Cost From: " << src << " to " << target << " is: " << tot_cst << nl;
    cout << "The route: ";
    print_route(route);
    cout << "Total Reqired: " << tot_tm << nl;
    cout << "Total Distance: " << tot_dis << nl;
    cout << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initial();
    print();
    ll inp = 5;
    while (inp != 4)
    {
        cout << "#####################################################" << nl;
        cout << "1 -> Minimum Distance from source to target." << nl;
        cout << "2 -> Miminum Required Time from source to target." << nl;
        cout << "3 -> Miminum Required Cost from source to target." << nl;
        cout << "4 -> EXIT." << nl;
        cout << "     Enter Choice: ";
        cin >> inp;
        if (inp == 1)
            shortest_distance();
        else if (inp == 2)
            minimum_time();
        else if (inp == 3)
            minimum_cost();
        else if (inp == 4)
            exit(1);
        else
            cout << "Wrong Input" << nl;
    }
}