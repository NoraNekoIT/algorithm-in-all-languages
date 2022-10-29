// Name-Avnish Kumar
// Username-Avnish010

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define M 0
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl "\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define mem(a, val) memset(a, val, sizeof(a))
#define vi vector<int>
#define vvl vector<vector<long>>
#define vl vector<ll>
#define vpl vector<pair<ll, ll>>
#define vpi vector<pair<int, int>>
const int LOG = 20;
const int lim = 200001;
vi adj[lim];
int up[lim][LOG];
int depth[lim];

bool vis[lim];

void dfs(int a)
{
    vis[a] = 1;
    for (auto b : adj[a])
    {
        if (vis[b])
            continue;
        depth[b] = depth[a] + 1;
        up[b][0] = a;
        for (int j = 1; j < LOG; j++)
        {
            up[b][j] = up[up[b][j - 1]][j - 1];
        }
        dfs(b);
    }
}
int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int k = depth[a] - depth[b];
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (k & (1 << j))
            a = up[a][j];
    }
    if (a == b)
        return a;
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[a][j];
        }
    }
    return up[a][0];
}
int kthlca(int node, int k) // extra function to calculate the kth ancestor of a node.
{
    for (int i = 0; i < LOG; i++)
    {
        if (k & (1 << i))
            node = node[up][i];
    }
    return node;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int x, y;
    for (int i = 0; i < edges; i++)
    {

        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1);
    cout << "Enter the value of nodes whose lca is to be calculated" << endl;
    int node1, node2;
    cin >> node1 >> node2;
    cout << "Longest common ancestor is:";
    cout << lca(node1, node2);
}
