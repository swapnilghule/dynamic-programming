#include<bits/stdc++.h>
using namespace std;


int t[102][1002];


int knapsack(int wt[],int val[],int w,int n)
{
if(n==0 || w==0)
return 0;
if(t[n][w] != -1)
return t[n][w];
if(wt[n-1]<=w)
return t[n][w]= max(val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
else if(wt[n-1]> w)
return t[n][w]=knapsack(wt,val,w,n-1);
}
int main()
{
int wt[100],val[100],capacity,n;
cin>>n;
cout<<"\n Enter No. of items";
for(int i=0;i<n;i++)
{
cout<<"\n"<<i+1<<":";
cin>>wt[i];
cin>>val[i];
}
cout<<"\n ENter capacity";
cin>>capacity;

    memset(t,-1,sizeof(t));
	
	
	int ans=knapsack(wt,val,capacity,n);
	cout<<ans;
return 0;	
}
