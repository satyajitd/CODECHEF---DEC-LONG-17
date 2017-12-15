#include<bits/stdc++.h>
using namespace std;
 
const double inf = 10e9;
 
double slope_cal(int x1, int y1, int x2, int y2)
{
    double temp = (double)(y2-y1)/(double)(x2-x1);
    return temp;
}
 
int main()
{
    int t=0; cin>>t;
    while(t--)
    {
        int r=0, b=0;
        cin>>r>>b;
        int n=r+b;
        int X[n], Y[n];
        
        pair<double, int> slope[n]; // double stores the slope and int indicates the point number.
        
        for(int i=0; i<n; i++)
            cin>>X[i]>>Y[i];
        int rem = min(r,b); // represents the minimum number of points to be deleted.
        
        // for each red point are pivot, find out the slope the lines formed it with all other points
        for(int i=0; i<r; i++)
        {
            int red=0, blue=0;
            for(int j=0; j<n; j++)
            {
                slope[j].second = j; // stores the point number (starting from 0 to n-1)
                if(X[i]==X[j])
                {
                    if(Y[i]<Y[j])
                        slope[j].first = inf; // plus infinity slope
                    else
                        slope[j].first = -inf; // minus infinity slope
                }
                else
                {
                    slope[j].first = slope_cal(X[i], Y[i], X[j], Y[j]); // calculating slope
                }
                if(X[j]>=X[i]) // checking if the jth point is right of the pivot or not
                {
                    if(j<r)
                        ++red;
                    else
                        ++blue;
                }
            }
            // We have finished storing the slopes of all the lines formed by the pivot red point.
            sort(slope, slope+n);
            // We sort the lines according their slope.
            
            //Now, using the pivot point we rotate required line and so we do change count of
            //left and right point. And check for minimum points to be removed after each rotation.
            
            for(int k=0; k<n; k++)
            {
                rem = min(rem, r-red + blue);
                rem = min(rem, b-blue + red-1);
                //r-red : red points to left
                //b-blue : blue points to left
                // red-1 : red points to right except pivot
                
                //rotation:
                int j=slope[k].second;
                if(i==j)
                    continue;
                if(X[j]>=X[i]) // checking if the jth point is left of the pivot or not
                {
                    if(j<r)
                        --red;
                    else
                        --blue;
                }
                else
                {
                    if(j<r)
                        ++red;
                    else
                        ++blue;
                }
                //after each rotation check the minimum number points to be removed.
                rem = min(rem, r-red + blue);
                rem = min(rem, b-blue + red-1);
            }
        }
        cout<<rem<<endl;
    }
    return 0;
}   
