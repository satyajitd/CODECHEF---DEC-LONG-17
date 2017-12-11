#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=0; cin>>t;
    while(t--)
    {
        int N=0, M=0;
        cin>>N>>M;
        char ary[N][M];
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin>>ary[i][j];

        int cost1=0, cost2=0;

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j+=2)
            {
                if(i%2 == 0)
                {
                    if(ary[i][j]!= 'R')
                        cost1+=3;
                    if(ary[i][j+1]!= 'G' && j+1 != M)
                        cost1+=5;
                }
                else
                {
                    if(ary[i][j]!= 'G')
                        cost1+=5;
                    if(ary[i][j+1]!= 'R' && j+1 != M)
                        cost1+=3;
                }
            }
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j+=2)
            {
                if(i%2!= 0)
                {
                    if(ary[i][j]!= 'R')
                        cost2+=3;
                    if(ary[i][j+1]!= 'G' && j+1 != M)
                        cost2+=5;
                }
                else
                {
                    if(ary[i][j]!= 'G')
                        cost2+=5;
                    if(ary[i][j+1]!= 'R' && j+1 != M)
                        cost2+=3;
                }
            }
        }
        int min;
        //cout<<cost1<<" "<<cost2<<endl;
        if(cost1<=cost2)
            min=cost1;
        else
            min=cost2;
        cout<<min<<endl;
    }
    return 0;
}
