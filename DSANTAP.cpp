// 5 points
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=0; cin>>t;
    while(t--)
    {
        int N,G,B,X,Y;
        cin>>N>>G>>B>>X>>Y;

        vector <int> vol;
        vector <int> oldgift;
        vector <int> newgift;
        for(int i=0; i<G; i++)
        {
            int vol1; cin>>vol1;
            vol.push_back(vol1);
        }

        int Xc, Yc, K, L;

        for(int i=0; i<N; i++)
        {
            cin>>Xc>>Yc>>K>>L;
            oldgift.push_back(K);
            newgift.push_back(L);
        }
        cout<<1<<" "<<0<<endl;
        for(int i=0; i<N; i++)
        {
            cout<<2<<" "<<newgift[i]<<endl;
            cout<<1<<" "<<i+1<<endl;
            cout<<3<<" "<<newgift[i]<<endl;
            cout<<2<<" "<<oldgift[i]<<endl;
            cout<<1<<" "<<0<<endl;
            cout<<3<<" "<<oldgift[i]<<endl;
        }
        cout<<0<<endl;
    }
    return 0;
}
