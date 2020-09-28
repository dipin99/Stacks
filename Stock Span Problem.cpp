#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the Size of the Array: ";
	cin>>n;
	int a[n];
	int i,j;
	cout<<"Enter the Array: ";
	for(i=0;i<n;i++)
		cin>>a[i];
	
	stack < pair<int,int> > s;
	vector <int> v;
	
	for(i=0;i<n;i++)
	{
		if(s.size()==0)
		{
			v.push_back(-1);
		}
		else if(s.size()>0 && s.top().first>a[i])
		{
			v.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first<=a[i] )
		{
			while(s.size()>0 && s.top().first<=a[i])
			{
				s.pop();
			}
		
			if(s.size()==0)
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(s.top().second);
			}
		}
		s.push({a[i],i});
	}
	cout<<"Solution: ";
	for(i=0;i<v.size();i++)
	{
		v[i]=i-v[i];
		cout<<v[i]<<" ";
		
	}	
	
	
}
