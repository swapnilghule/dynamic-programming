#include<bits/stdc++.h>
using namespace std;

int t[200][1200];


int knapsack(int a[],int sum,int n)
{
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(a[i-1]<=sum)
			t[i][j]= t[i-1][j-a[i-1]] + t[i-1][j];
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
int diff,sum;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
cin>>diff;

int sumofarray=accumulate(a,a+n,0);
sum = (diff+sumofarray)/2;

for(int i=0;i<n+1;i++)
{
	for(int j=0;j<sum+1;j++)
	{
		if(i==0)
		t[i][j]=0;
		if(j==0)
		t[i][j]=1;
	}
}


int n1=knapsack(a,sum,n);

cout<<n1;


return 0;	
}
