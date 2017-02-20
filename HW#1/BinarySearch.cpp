//	Shofiqur Rahman
//	shofi384@gmail.com

#include <iostream>
#include <cmath>

using namespace std;

int* MakeArray(int n);
int* MakeUnqArray(int n);
bool contains(int a[], int i, int r);
int BinarySearch(int a[], int n, int key, int& FoundKey, 		int& OpCount);

main()
{
	int* key=MakeArray(1000);
	size_t n;
	cout<<"Give me the number of array elements you want to search from: "<<endl;
	cin>>n;
	int* a =MakeUnqArray(n);
	int avg;
	int op=0;
	int FoundKey=0;

	for(int i=0; i<1000; i++)
	{
		BinarySearch(a, n, key[i], FoundKey, op);
	}
	avg=op/1000;
	cout<<"\nTotal number of key found is "<<FoundKey
		<<"\nAnd average number of operations is "<<avg<<endl;
}

	int* MakeArray(int n)
	{
		int* a=new int[n];
		cout<<"The vector has been created with "<<n
		<<" values!\nNow the array is being filled with unique integers. . ."<<endl;
		for(int i=0; i<n; i++)
		{
			a[i]= rand()%n;
			cout<<"\n"<<a[i];
		}
		cout<<endl;
		return a;
	}

	int* MakeUnqArray(int n)
	{
		int* a=new int[n];
		for(int i=0; i<n; i++)
		{
			int r = rand()%(n+1);
			while(contains(a,i,r))
			{
				r = rand()%(n+1);
			}
			a[i] = r;
			cout<<"\n"<<a[i];
		}
		cout<<endl;
		return a;
	}

	bool contains(int a[], int i, int r)
	{
		for(int j=0; j<=i; j++)
		{
			if(a[j]==r)
				return true;
		}
		return false;
	}

	int BinarySearch(int a[], int n, int key, int& FoundKey, int& OpCount)
	{
		int low = 0; // 1 assignment
		int high = n-1;	// 1 assignment
		OpCount+=2;

		while(low <= high)	// log n comparisons
		{
			int mid =(low + high)/2;	// log n assignments
			OpCount+=2;
			if (a[mid]>key) // log n comparisons
			{
				high = mid-1;	// log n assignments
				OpCount+=2;
			}
			else if(a[mid]<key)	// log n comparisons
			{
				low = mid+1;	// log n assignments
				OpCount+=2;
			}
			else
			{
				FoundKey++;
				return OpCount;
			}
		}
		return OpCount;
	}
