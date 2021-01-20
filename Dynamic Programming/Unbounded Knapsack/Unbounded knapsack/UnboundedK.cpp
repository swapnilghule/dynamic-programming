#include<bits/stdc++.h>
using namespace std;

int t[202][2002];


int knapsack(int wt[],int v[],int w,int n)
{
	for(int i=1;i<n+1;i++)
	{
	   for(int j=1;j<w+1;j++)
	   {
	       if(wt[i-1]<=w)
		   t[i][j]= max(v[i-1]+t[i][j-wt[i-1]], t[i-1][j]);
		   else
		   t[i][j]=t[i-1][j];	
       }
	}
	
	return t[n][w];
}
int main()
{
	int n;
	cin>>n;
	
	int wt[n];
	int v[n];
	int w;
	for(int i=0;i<n;i++)
	{
	cin>>wt[i];
	cin>>v[i];
    }
    cin>>w;
    for(int i=0;i<n+1;i++)
    {
    	for(int j=0;j<w+1;j++)
    	{
    		if(i==0 || j==0)
    		t[i][j]=0;
		}
	}
	
	int k=knapsack(wt,v,w,n);
	
	cout<<k;
    
	return 0;
}
