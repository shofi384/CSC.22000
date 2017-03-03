//	Shofiqur Rahman
//	shofi384@gmail.com

#include <iostream>

using namespace std;

int* MakeArray(int n);
int* MakeUnqArray(int n);
bool contains(int a[], int i, int r);
void StrSeqS(int* a, int n, int* key);

main()
{
	int* key=MakeArray(1000);
	size_t n;
	cout<<"Give me the number of array elements you want to search from: "<<endl;
	cin>>n;
	int* a =MakeUnqArray(n);
	StrSeqS(a, n, key);
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

	void StrSeqS(int* a, int n, int* key)
	{
		int op=0,found=0, avg;
		bool nf = true;
		int j=0;
		for(int i=0; i<1000; i++)
		{
			op+=3;
			while(j< n && nf) // n comparison
		{
			op+=2;
			if (key[i]==a[j]) // n comparisons
			{
				nf = false;
				found++;
				cout<<"Total count of operation is "<<op<<endl;
			}
			else
				{
					j++; // n assignment
					op++;
				}
			}
		}
		avg = op/1000;
		cout<<"\nTotal number of key found is "<<found
		<<"\nAnd average number of operations is "<<avg<<endl;
	}
