#include<bits/stdc++.h>

typedef long long int ll;
#define mod 1000000007

using namespace std;

void addEdge(ll u, ll v, list<ll> *adj)
{
    adj[u].push_back(v);
}

void DFStraversal(ll node, ll max_dis, bool visited[], ll *node_val, list<ll> *adj, ll val[], ll edge)
{
    visited[node-1] = true;

    list <ll>::iterator i;
    for (i = adj[node].begin(); i!= adj[node].end(); ++i)
    {
        if (!visited[*i-1])
        {
            ++edge;
            if(edge == (max_dis+1))
                return;
            visited[*i-1] = true;
            node_val[*i] = ((node_val[*i]%mod) + (val[edge]%mod))%mod;
            DFStraversal(*i, max_dis, visited, node_val, adj, val,edge);
            --edge;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=0; cin>>t;
    while(t--)
    {
        ll N, Q;
        cin>>N>>Q;
        list<ll> adj[N+1];

        ll u, v;
        for(ll i=1; i<=N-1; i++)
        {
            cin>>u>>v;
            addEdge(u,v, adj);
            addEdge(v,u, adj);
        }

        ll node_val [N+1];

        for(ll i =0; i<N+1; i++)
            node_val[i]=0;

        while(Q--)
        {
            ll q_type; cin>>q_type;

            if(q_type == 1)
            {
                ll node, max_dis, val1, val2;
                cin>>node>>max_dis>>val1>>val2;
                ll val [max_dis+1];

                val[0]=val1%mod;
                if(max_dis!=0)
                    val[1]=val2%mod;
                for(ll i=2; i<max_dis+1; i++)
                {
                    val[i]=0;
                    val[i]=((val[i-1]%mod)+(val[i-2]%mod))%mod;
                }
                /*for(ll i=0; i<max_dis+1; i++)
                    cout<<val[i]<<" ";
                cout<<endl;*/
                bool *visited = new bool[N];
                for (ll i = 0; i<N; i++)
                    visited[i] = false;

                node_val[node] = ((node_val[node]%mod)+ (val[0]%mod))%mod;
                DFStraversal(node, max_dis, visited, node_val, adj, val, 0);
                /*for(ll i=1;i<N+1; i++)
                    cout<<node_val[i]<<" ";
                cout<<endl;*/
            }
            else
            {
                ll node; cin>>node;
                cout<<(node_val[node]%mod)<<endl;
            }
        }
    }
    return 0;
}
