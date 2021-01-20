#include<bits/stdc++.h>
using namespace std;


int t[102][1002];


int knapsack(int wt[],int val[],int c,int n)
{
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<c+1;j++)
		{
			if(wt[i-1]<=j)
			t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
			else  if(wt[i-1]>j)
			t[i][j]=t[i-1][j];
			
		}
	}
return t[n][c];
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

	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<capacity+1;j++)
		{
			if(i==0 || j==0)
			t[i][j]=0;
		}
	}
	
	
	int ans=knapsack(wt,val,capacity,n);
/*for(int i=0;i<n+1;i++)
{
	for(int j=0;j<capacity+1; j++)
	{
    cout<<t[i][j]<<"\t";
	}
	cout<<"\n";
}*/
	cout<<"\n"<<ans;
return 0;	
}
