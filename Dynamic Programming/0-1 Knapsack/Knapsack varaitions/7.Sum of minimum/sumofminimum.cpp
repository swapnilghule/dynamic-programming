#include<bits/stdc++.h>
using namespace std;

int t[100][2000];



int knapsack(int a[],int sum,int n)
{
	int min,sum1;
	vector<int> v;
	vector<int> :: iterator i1;
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			
			min=*min_element(a,a+n);
			cout<<"\n\t"<<min;
			if(a[i-1]<=j)
			t[i][j]= max(min+t[i-1][j-a[i-1]] , t[i-1][j]);
			else
			t[i][j]=t[i-1][j];
		}
	}
	cout<<"\n Possible subsets: \n";
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
		 cout<<t[i][j]<<"\t";
		}
		cout<<"\n";
	}
/*	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(t[i][j])
			{
				cout<<"\n";
		      for(int k=0;k<n;k++)
		      cout<<"\t"<<a[k];
			  v.push_back(min);	
			}
		}
	}

	cout<<"\n Minimum elements:\n";
	for(i1=v.begin();i1<v.end();i1++)
	cout<<"\t"<<*i1;
	sum1=accumulate(v.begin(),v.end(),0);
*/	
	
	return t[n][sum];
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	cout<<"\n Input Array: \n";
	for(int i=0;i<n;i++)
	cout<<"\t"<<a[i];
	
	int sum=accumulate(a,a+n,0);
	cout<<"\n Sum Of Array(Range for subset):";
	cout<<"\t"<<sum;
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
	cout<<"\n Initialisation \n";
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
		 cout<<t[i][j]<<"\t";
		}
		cout<<"\n";
	}
	int sumOFmin=knapsack(a,sum,n);
	cout<<"\n Sum of minimum elements:\t";
	cout<<sumOFmin;
	
	return 0;
}
