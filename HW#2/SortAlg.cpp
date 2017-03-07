#include <iostream>

using namespace std;

int* MakeRandArray(int n)
{
	int* a = new int[n];
	for(int i=0; i<n; i++)
	{
		a[i] = i;
	}

	int index;
	for(int j=0; j<n; j++)
	{
		index = rand()%n;
		swap(a[j],a[index]);
	}
	return a;
}

int* MakeSeqArray(int n)
{
	int* a = new int[n];
	for(int i=0; i<n; i++)
	{
		a[i] = i+1;
	}
	return a;
}

int* MakeRevSeqArray(int n)
{
	int* a = new int[n];
	for(int i=n; i>=1; i--)
	{
		a[i-1] = i;
	}
	return a;
}

void StrInsSort(int n)
{
	int CompCount=0, SwapCount=0;
	for(int r=0; r<10; r++)
	{
	int* a = MakeRandArray(n);
	for(int i=1; i<n; i++)
	{
		CompCount++;
		while(i>0 && a[i]<a[i-1])
		{
			CompCount+=2;
			SwapCount++;
			swap(a[i], a[i-1]);
			i--;
		}
	}
	}
	cout<<"The average of insertion sorting "<<n<<" elements 10 times: \n   Comparison: "<<CompCount/10<<"\n   Swapping: "<<SwapCount/10<<endl;
}

main()
{
	int* seq2;
	int* seq4;
	int* seq6;
	seq2 = MakeSeqArray(100);
	seq4 = MakeSeqArray(10000);
	seq6 = MakeSeqArray(1000000);

	int* rev2;
	int* rev4;
	int* rev6;
	rev2 = MakeRevSeqArray(100);
	rev4 = MakeRevSeqArray(10000);
	rev6 = MakeRevSeqArray(1000000);

	StrInsSort(100);
	StrInsSort(10000);
	StrInsSort(1000000);
}
