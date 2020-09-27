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
	
	stack <int> s;
	vector <int> v;
	
	for(i=n-1;i>=0;i--)
	{
		if(s.size()==0)
		{
			v.push_back(-1);
		}
		else if(s.size()>0 && s.top()>a[i])
		{
			v.push_back(s.top());
		}
		else if(s.size()>0 && s.top()<=a[i] )
		{
			while(s.size()>0 && s.top()<=a[i])
			{
				s.pop();
			}
		
			if(s.size()==0)
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(s.top());
			}
		}
		s.push(a[i]);
	}
	cout<<"Nearest Greatest Element to the right";
	for(i=v.size()-1;i>=0;i--)
		cout<<v[i]<<" ";
	
	
}
