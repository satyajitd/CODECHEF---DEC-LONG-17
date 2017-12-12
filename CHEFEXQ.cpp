#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll ar[100007]; // all the elements
ll block[1007][1007]; // contains elements block wise
ll block_xor[1007]; // stores cumulative XOR value of each block
map <ll,ll> xval[1007]; // contains XOR value block wise
ll block_sz=0;

void build(ll a[], ll sz)
{
    ll block_id=-1;
    block_sz = sqrt(sz);
    ll j=1;
    for(ll i=0; i<sz; i++)
    {
        ar[i]=a[i];
        if(i%block_sz == 0)
        {
            if(i!=0 && block_id!=-1)
                block[block_id][0]=j-1; // position denoting the end of block elements.

            ++block_id; j=1;
            block_xor[block_id]=a[i];
        }
        block[block_id][j] = a[i];
        if(j!=1)
            block_xor[block_id] = block_xor[block_id]^a[i];

        ++xval[block_id][block_xor[block_id]]; ++j;
        if(i ==sz-1)
            block[block_id][0]=j-1;
    }
}

void update(ll id, ll val, ll  block_id)
{
    xval[block_id].clear();
    block[block_id][id]=val;
    ++xval[block_id][block[block_id][1]];

    ll temp = block[block_id][1];
    for(ll i=2; i<=block[block_id][0]; i++)
    {
        temp^=block[block_id][i];
        ++xval[block_id][temp];
    }
    block_xor[block_id] = temp;
    return;
}

ll query(ll id, ll val, ll block_id)
{
    ll  temp = val; ll result=0; ll temp1=0;
    // counting frequency of val in blocks having block-id less than block_id
    for(ll i=0; i<block_id; i++)
    {
        if(xval[i].find(temp)!= xval[i].end())
            result+=xval[i][temp];
        temp^=block_xor[i];
        temp1^=block_xor[i];
    }
    // counting frequency of val in the block having block-id = block_id
    for(ll i=1; i<=id; i++)
    {
        temp1^=block[block_id][i];
        if(temp1 == val)
            ++result;
    }
    return result;
}

int main()
{
    ll N=0, Q=0; cin>>N>>Q;
    ll a[N];
    for(ll i=0; i<N; i++)
        cin>>a[i];
    build(a,N);
    while(Q--)
    {
        ll ty, id, val;
        cin>>ty>>id>>val;
        if(ty==1)
        {
            ll block_id=(id-1)/block_sz;
            ll pos = id -(block_sz*block_id);
            update(pos, val, block_id);
        }
        else
        {
            ll block_id=(id-1)/block_sz;
            ll pos = id -(block_sz*block_id);
            ll result = query(pos, val, block_id);
            cout<<result<<endl;
        }
    }
    return 0;
}
