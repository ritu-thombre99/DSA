# include<iostream>
# include<bits/stdc++.h>
using namespace std;


string lcs(string s1, string s2)
{
	// your code here
	vector<vector<int>> dp(s1.length()+1,vector<int> (s2.length()+1, 0));
	for(int i=1;i<=s1.length();i++)
	{
		for(int j=1;j<=s2.length();j++)
		{
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string ans = "";
	int i=s1.length(), j=s2.length();
	while(i>0 && j>0)
	{
		if(s1[i-1] == s2[j-1])
		{
			ans = s1[i-1] + ans;
			i = i-1;
			j = j-1;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			i = i-1;
		else
			j = j-1;
	}
	return ans;
}

int main()
{	
	string x,y;
	cin>>x;
	cin>>y;
	cout<<"LCS:"<<lcs(x,y)<<endl;
	return 0;
}