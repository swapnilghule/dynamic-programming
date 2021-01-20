#include<bits/stdc++.h>
//#include<unordered_map>
using namespace std;

int t[1001][1001][2];


int solve(string x,int i,int j,bool b)   //hidden features since the xor has property that to find the # of true ,it needs to find for both true and false so  
{
	int ans=0;
	if(i > j)                              // Invalid Input 
	return 0;
	
	if(i==j)                               // if its points to single character
	{
		if(b==true)
		return x[i]=='T';
		else
		return x[i]=='F';
	}
	
	/*string temp=to_string(i);                 // temp is key of format i j b
	temp.push_back(" ");
	temp.append(to_string(j));
	temp.push_back(" ");
	temp.append(to_string(b));
	
	if(mp.find(temp) != mp.end())             // if temp's value is found means subtree is already solved then return that value
	return mp[temp];
	
	*/
	
	
	if(t[i][j][b]!=-1)
	return t[i][j][b];
	
	for(int k=i+1;k<=j-1;k=k+2)           //we are breaking at operator operator is at 1 position  means i+1 and its breaks at operator so k=k+2 move to operator only
	{
		int lt= solve(x,i,k-1,true);  
		int rt= solve(x,k+1,j,true);
		int lf= solve(x,i,k-1,false);
		int rf= solve(x,k+1,j,false);
		
		
		if(x[k]== '&')                   //if(k is breaks at & opearator)
		{
			if(b==true)                 
			ans += (lt * lt);
			else
			ans += (lf * rt) + (lt*rf) + (lf * rf);
		}
		
		else if(x[k]=='|')
		{
			if(b==true)
			ans += (lf *rt) + (lt *rf) +(lt*rt);
			else
			ans += (lf *rf);
		}
		
		else if(x[k]=='^')
		{
			if(b==true)
			ans += (lf * rt) + (lt* rf);
			else
			ans += (lf *rf) + (rf *lf);
		}
	}
	return t[i][j][b]=ans;
}
int main()
{
	string x;
	cin>>x;
	
	int n = x.length();
	
//	mp.clear();
	memset(t,-1,sizeof(t));
	int k = solve(x,0,n-1,true);     //point 1
	
	

	
		cout<<k;


	return 0;
}
