#include <iostream>
#include <vector>

using namespace std;

int* MakeArray(int n);
int* MakeUnqArray(int n);
bool contains(int a[], int i, int r);
int StrSeqS(int a[], int n, int key);

main()
{
	int* key=MakeArray(1000);

	int* a =MakeUnqArray(1000000);
	int avg,op=0;
	for(int i=1; i<=101; i++)
	{
		op+=StrSeqS(a, 1000000, key[i]);
	}
	avg=op/101;
	cout<<"Average number of operation for 10^2 is "<<avg<<endl;
}

	int* MakeArray(int n)
	{
		int* a=new int[n];
		cout<<"The vector has been created with "<<n
		<<" values!\nNow the array is being filled with unique integers. . ."<<endl;
		for(int i=0; i<n; i++)
		{
			a[i]= rand()%10003;
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
			int r = rand()%1000003;
			while(contains(a,i,r))
			{
				r = rand()%1000003;
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

	int StrSeqS(int a[], int n, int key)
	{
		int i=0, count=0;
		while(i< n) // n comparison
		{
			count++;
			if (a[i]==key) // n comparisons
			{
				count++;
				cout<<"Total count of operation is "<<count<<endl;
				return count;
			}
			else
			{
				i= i+1; // n assignment
				count+=2;
			}
		}
		cout<<"Total count of operation is "<<count<<endl;
		return count;
	}
