//	Shofiqur Rahman
//	shofi384@gmail.com

#include <iostream>
#include <cmath>

using namespace std;

int* MakeArray(int n);
int* MakeUnqArray(int n);
bool contains(int a[], int i, int r);
int OrSeqS(int a[], int n, int key, int& FoundKey);
int MergeSort(int a[], size_t n);
int merge(int data[ ], size_t n1, size_t n2);

main()
{
	int* key=MakeArray(1000);
	size_t n;
	cout<<"Give me the number of array elements you want to search from: "<<endl;
	cin>>n;
	int* a =MakeUnqArray(n);
	int avg, op=0, FoundKey=0;

	op = MergeSort(a, n);

	for(int i=0; i<1000; i+=log10(n))
	{
		op+=OrSeqS(a, n, key[i], FoundKey);
	}
	avg=op/1000;
	cout<<"\nTotal number of key found is "<<FoundKey
		<<"\nAnd average number of operation is "<<avg<<endl;
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

	int OrSeqS(int a[], int n, int key, int& FoundKey)
	{
		int i=0, OpCount=0;
		MergeSort(a,n);
		while(i< n) // n comparison
		{
			OpCount++;
			if (a[i]==key) // n comparisons
			{
				OpCount++;
				FoundKey++;
				cout<<"Total count of operation is "<<OpCount<<endl;
				return OpCount;
			}
			else
			{
				i= i+1; // n assignment
				OpCount+=2;
			}
		}
		cout<<"Total count of operation is "<<OpCount<<endl;
		return OpCount;
	}

	int MergeSort(int data[ ], size_t n)
	{
		int OpeCount=0;
		size_t n1; // Size of the first subarray
    size_t n2; // Size of the second subarray

    if (n > 1)
    {// Compute sizes of the subarrays.
			n1 = n / 2;
      n2 = n-n1;
			OpeCount+=3;

			MergeSort(data, n1);	//Sort from data[0] through data[n1-1]
			MergeSort((data + n1), n2);	//Sort from data[n1] to the end
			OpeCount+=merge(data, n1, n2);
		}
		return OpeCount;
	}

	int merge(int data[ ], size_t n1, size_t n2)
	{
    int OpeCount=0;
		int *temp;
    size_t copied  = 0;
    size_t copied1 = 0;
    size_t copied2 = 0;
    size_t i;	//Array index to copy from temp back into data
    // Allocate memory for the temporary dynamic array.
    temp = new int[n1+n2];
		OpeCount+=4;
    // Merge elements, copying from two halves of data to the temporary array.
    while ((copied1 < n1) && (copied2 < n2))
    {
			OpeCount+=2;
			if (data[copied1] < (data + n1)[copied2])
			{temp[copied++] = data[copied1++];
				OpeCount+=2;
			}
			else
			{
				temp[copied++] = (data + n1)[copied2++];
				OpeCount++;
			}
    }

    // Copy any remaining entries in the left and right subarrays.
    while (copied1 < n1)
		{temp[copied++] = data[copied1++];
			OpeCount+=2;}
    while (copied2 < n2)
		{temp[copied++] = (data+n1)[copied2++];
			OpeCount+=2;}

    // Copy from temp back to the data array, and release temp's memory.
    for (i = 0; i < n1+n2; i++)
			{data[i] = temp[i];
			OpeCount+=4;}
    delete [ ] temp;
		return OpeCount;
}
