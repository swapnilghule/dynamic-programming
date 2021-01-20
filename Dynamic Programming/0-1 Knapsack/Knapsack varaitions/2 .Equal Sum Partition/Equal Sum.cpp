#include<bits/stdc++.h>
using namespace std;


int t[100][2000];
bool knapsack(int a[],int sum,int n)
{
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(a[i-1]>=j)
			t[i][j]= t[i-1][j-a[i-1]] || t[i-1][j];
			else
			t[i][j]=t[i-1][j];
		}
    }
    
    return t[n][sum];
}

int main()
{
	int n,sum=0;
	bool r;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	for(int i=0;i<n;i++)
	sum =sum +a[i];
	
	cout<<"\n Sum of array:"<<sum;
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
			t[i][j]=false;
			if(j==0)
			t[i][j]=true;
		}
	}
	
	cout<<"\n INITIALSATION: \n";
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<(sum/2)+1;j++)
		{
			cout<<t[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	if(sum % 2!= 0)
	cout<<"\n since  "<<sum<< " is odd so there is no partition who have equal sum";
	else
	{
		cout<<"\n Since "<<sum<<" is not odd so we can move further";
		r=knapsack(a,sum/2,n);
		cout<<"\n So Here is all subset and set t[n][sum] contains the answer \n";
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<(sum/2)+1;j++)
		{
			cout<<t[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
		
		if(r)
		cout<<"\n YES";
		else
		cout<<"\n NO";
	}
	
	return 0;
}
