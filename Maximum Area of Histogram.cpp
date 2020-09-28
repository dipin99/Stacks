#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
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
	
	int pi=-1;
	stack < pair<int,int> > s;
	vector <int> left;
	
	for(i=0;i<n;i++)
	{
		if(s.size()==0)
		{
			left.push_back(pi);
		}
		else if(s.size()>0 && s.top().first<a[i])
		{
			left.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first>=a[i] )
		{
			while(s.size()>0 && s.top().first>=a[i])
			{
				s.pop();
			}
		
			if(s.size()==0)
			{
				left.push_back(-1);
			}
			else
			{
				left.push_back(s.top().second);
			}
		}
		s.push({a[i],i});
	}
	
	
	stack < pair<int,int> > s1;
	vector <int> right;
	pi=n;
	
	for(i=n-1;i>=0;i--)
	{
		if(s1.size()==0)
		{
			right.push_back(pi);
		}
		else if(s1.size()>0 && s1.top().first<a[i])
		{
			right.push_back(s1.top().second);
		}
		else if(s1.size()>0 && s1.top().first>=a[i] )
		{
			while(s1.size()>0 && s1.top().first>=a[i])
			{
				s1.pop();
			}
		
			if(s1.size()==0)
			{
				right.push_back(-1);
			}
			else
			{
				right.push_back(s1.top().second);
			}
		}
		s1.push({a[i],i});
	}
	
	
	
	
	
	
	
	int w[n];
	int ar[n];
	reverse(right.begin(),right.end());
	
	

	for(i=0;i<n;i++)
	{	
		w[i]=right[i]-left[i]-1;
		
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		ar[i]=a[i]*w[i];
		
	}
	
	sort(ar,ar+n);
	
	cout<<"The Maximum Area of the Histogram is: "<<ar[n-1];
	
}
