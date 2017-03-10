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

void StrInsSort(int a[], int p, int r, int& CompCount, int& SwapCount)
{
	int n = r-p+1;
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

void RepeatStrInsSort(int n)
{
	int CompCount=0, SwapCount=0;
	for(int r=0; r<10; r++)
	{
	int* a = MakeRandArray(n);
	StrInsSort(a, 0, n-1, CompCount, SwapCount);
	}
	cout<<"The average of Insertion sorting "<<n<<" elements 10 times: \n   Comparison: "<<CompCount/10<<"\n   Swapping: "<<SwapCount/10<<endl;
}

void merge(int a[], int p, int q, int r, int& CompCount)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1];
	int R[n2+1];
	for(int i=1;i<=n1;i++)
	{
		L[i]=a[p+i-1];
	}
	for(int j=1;j<=n2;j++)
	{
		R[j]=a[q+j];
	}

	L[n1+1]=900000000;
	R[n2+1]=999000000;

	int i=1, j=1;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			CompCount++;
			a[k]=L[i];
			i=i+1;
		}
		else
		{
			a[k]=R[j];
			j=j+1;
		}
	}
}

void MergeSort(int a[], int p, int r, int& CompCount)
{
	int q;
	if(p<r)
	{
		CompCount++;
		q=(p+r)/2;
		MergeSort(a,p,q, CompCount);
		MergeSort(a,q+1,r, CompCount);
		merge(a,p,q,r, CompCount);
	}
}

void RepeatMerge(int n)
{
	int CompCount=0;
	for(int i =0; i<10; i++)
	{
		int* a = MakeRandArray(n);
		MergeSort(a, 0, n-1, CompCount);
	}
	cout<<"The average of Merge sorting "<<n<<" elements 10 times: \n   Comparison: "<<CompCount/10<<endl;
}

void KMergeSort(int a[], int p, int r, int& CompCount, int& SwapCount)
{
	int q;
	int n = r-p+1, k=20;
	if(n>1)
	{
		CompCount++;

	if(n<=k)
	{
		CompCount++;
		StrInsSort(a, p, r, CompCount, SwapCount);
	}
		else
		{
			q=(p+r)/2;
		KMergeSort(a,p,q, CompCount, SwapCount);
		KMergeSort(a,q+1,r, CompCount, SwapCount);
		merge(a,p,q,r, CompCount);}
	}
}

void RepeatKMerge(int n)
{
	int CompCount=0, SwapCount=0;
	for(int i =0; i<10; i++)
	{
		int* a = MakeRandArray(n);
		KMergeSort(a, 0, n-1, CompCount, SwapCount);

		for(int i=0; i<n; i++)
		{
			cout<<a[i]<<" ";
		}
	}
	cout<<"The average of KMerge sorting "<<n<<" elements 10 times: \n   Comparison: "<<CompCount/10<<"\n   Swapping: "<<SwapCount/10<<endl;
}

main()
{
	int* seq2;
	int* seq4;
	int* seq6;
	seq2 = MakeSeqArray(100);
	seq4 = MakeSeqArray(10000);
	//seq6 = MakeSeqArray(1000000);

	int* rev2;
	int* rev4;
	int* rev6;
	rev2 = MakeRevSeqArray(100);
	rev4 = MakeRevSeqArray(10000);
	//rev6 = MakeRevSeqArray(1000000);

	RepeatStrInsSort(100);
	RepeatMerge(100);
	RepeatKMerge(100);

	/*RepeatStrInsSort(10000);
	RepeatMerge(10000);
	RepeatKMerge(10000);

	RepeatStrInsSort1000000);
	RepeatMerge(1000000);
	RepeatKMerge(1000000);*/
}
