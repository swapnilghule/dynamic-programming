#include<bits/stdc++.h>
using namespace std;
int t[200][2000];

int knapsack(int a[],int sum,int n)
{
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(a[i-1]<=j)
			t[i][j]=min((t[i][j-a[i-1]]+1) , t[i-1][j]);
			else
			t[i][j]=t[i-1][j];
		}
	}
	
	return t[n][sum];
}

int main()
{
	int n;
	cin>>n;
	int sum;
	
	int coins[n];
	for(int i=0;i<n;i++)
	cin>>coins[i];
	
	cin>>sum;
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(j==0)
			t[i][j]=0;
			if(i==0)
			t[i][j]=INT_MAX - 1;
			
			if(j%coins[0]==0)
			t[i][j]=j/coins[0];
			else
			t[i][j]=INT_MAX - 1;
		}
	}
	
	
	int k=knapsack(coins,sum,n);
	cout<<k;
	return 0;
}
