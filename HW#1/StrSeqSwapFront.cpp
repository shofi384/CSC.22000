//	Shofiqur Rahman
//	shofi384@gmail.com

#include <iostream>
#include <algorithm>

using namespace std;

int* MakeArray(int n);
int* MakeUnqArray(int n);
bool contains(int a[], int i, int r);
int StrSeqS(int a[], int n, int key, int& FoundKey);

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
		op+=StrSeqS(a, n, key[i], FoundKey);
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

	int StrSeqS(int a[], int n, int key, int& FoundKey)
	{
		int i=0;
		int OpCount=0;
		while(i< n) // n comparison
		{
			OpCount++;
			if (a[i]==key) // n comparisons
			{
				swap(a[i], a[i+1]);
				OpCount+=2;
				FoundKey++;
				cout<<"Total count of operation is "
					<<OpCount<<endl;
				return OpCount;
			}
			else
			{
				i++; // n assignment
				OpCount++;
			}
		}
		cout<<"Total count of operation is "<<OpCount<<endl;
		return OpCount;
	}
