#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter the Size of the Array: ";
	int n;
	cin>>n;
	
	int a[n],i;
	cout<<"Enter the Array: ";
	for(i=0;i<n;i++)
		cin>>a[i];

	
	int mxl[n],mxr[n];
	mxl[0]=a[0];
	for(i=1;i<n;i++)
	{
		mxl[i]=max(mxl[i-1],a[i]);
	}

	
	mxr[n-1]=n-1;
	for(i=n-2;i>=0;i--)
	{
		mxr[i]=max(mxr[i+1],a[i]);
	}

	int water[n];
	for(i=0;i<n;i++)
	{
		water[i]=min(mxl[i],mxr[i]-a[i]);
	}
	
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+water[i];
	}
	
	cout<<"The amount of water is: "<<sum<<" units";
	return 0;
}
