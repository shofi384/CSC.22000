//	Sofiqur Rahman
//	shofi384@gmail.com

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
	for(int i=p+1; i<=r; i++)
	{
		CompCount++;
		while(i>p && a[i]<a[i-1])
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
		CompCount++;
		L[i]=a[p+i-1];
	}
	for(int j=1;j<=n2;j++)
	{
		CompCount++;
		R[j]=a[q+j];
	}

	L[n1+1]=900000000;
	R[n2+1]=900000000;

	int i=1, j=1;
	for(int k=p;k<=r;k++)
	{
		CompCount++;
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
	int CompCount=0, SwapCount=0;
	for(int i =0; i<10; i++)
	{
		int* a = MakeRandArray(n);
		MergeSort(a, 0, n-1, CompCount);
	}
	cout<<"The average of Merge sorting "<<n<<" elements 10 times: \n   Comparison: "<<CompCount/10<<"\n   Swapping: "<<SwapCount/10<<endl;
}

void KMergeSort(int a[], int p, int r, int& CompCount, int& SwapCount)
{
	int n = r-p+1;
	int q;
	CompCount++;
	if(n>8)
	{
		q=(p+r)/2;
		KMergeSort(a,p,q, CompCount, SwapCount);
		KMergeSort(a,q+1,r, CompCount, SwapCount);
		merge(a,p,q,r, CompCount);
	}
	else
	{
		StrInsSort(a, p, r, CompCount, SwapCount);
	}
}

void RepeatKMerge(int n)
{
	int CompCount=0, SwapCount=0;
	for(int i =0; i<10; i++)
	{
		int* a = MakeRandArray(n);
		KMergeSort(a, 0, n-1, CompCount, SwapCount);
	}
	cout<<"The average of Merge sorting with Insertion sort "<<n<<" elements 10 times: \n   Comparison: "<<CompCount/10<<"\n   Swapping: "<<SwapCount/10<<endl;
}

int partition(int a[], int p, int r, int& CompCount, int& SwapCount)
{
	int pivot = a[r];
	int i = p-1;
	for(int j=p; j<=r-1; j++)
	{
		CompCount+=2;
		if(a[j]<pivot)
		{
			i = i+1;
			swap(a[i], a[j]);
			SwapCount++;
		}
	}
	swap(a[i+1], a[r]);
	SwapCount++;
	return i+1;
}

void quick(int a[], int p, int r, int& CompCount, int& SwapCount)
{
	CompCount++;
	if(p<r)
	{
		int q = partition(a, p, r, CompCount, SwapCount);
		quick(a, p, q-1, CompCount, SwapCount);
		quick(a, q+1, r, CompCount, SwapCount);
	}
}

void RepeatQuick(int n)
{
	int CompCount=0, SwapCount=0;
	for(int r=0; r<10; r++)
	{
	int* a = MakeRandArray(n);
	quick(a, 0, n-1, CompCount, SwapCount);
	}
	cout<<"The average of Quick sorting "<<n<<" elements 10 times: \n   Comparison: "<<CompCount/10<<"\n   Swapping: "<<SwapCount/10<<endl;
}

void KQuick(int a[], int p, int r, int& CompCount, int& SwapCount)
{
	int n = r-p+1;
	int k=4;

	CompCount++;
	if(n<=k)
	{
		StrInsSort(a, p, r, CompCount, SwapCount);
	}

	CompCount++;
	if(n>k)
	{
		int q = partition(a, p, r, CompCount, SwapCount);
		quick(a, p, q-1, CompCount, SwapCount);
		quick(a, q+1, r, CompCount, SwapCount);
	}
}

void RepeatKQuick(int n)
{
	int CompCount=0, SwapCount=0;
	for(int r=0; r<10; r++)
	{
	int* a = MakeRandArray(n);
	KQuick(a, 0, n-1, CompCount, SwapCount);
	}
	cout<<"The average of Quick sorting with Insertion Sort "<<n<<" elements 10 times: \n   Comparison: "<<CompCount/10<<"\n   Swapping: "<<SwapCount/10<<endl;
}

void MaxHeapify(int a[], int i, int n, int& CompCount, int& SwapCount)
{
	int l = 2*i;
	int r = 2*i+1;

	int larger;
	CompCount++;
	if(l<n && a[l]>a[i])
		larger=l;
	else
		larger=i;
	CompCount++;
	if(r<n && a[r]>a[larger])
		larger=r;
	CompCount++;
	if(i!=larger)
	{
		SwapCount++;
		swap(a[i],a[larger]);
		MaxHeapify(a, larger, n, CompCount, SwapCount);
	}
}

void BuildHeap(int a[], int n, int& CompCount, int& SwapCount)
{
	for(int i=n/2+1; i>=0; i--)
	{
		CompCount++;
		MaxHeapify(a, i, n, CompCount, SwapCount);
	}
}

void heap(int a[], int n, int& CompCount, int& SwapCount)
{
	BuildHeap(a, n, CompCount, SwapCount);
	int c = n;
	for(int i=c-1; i>0; i--)
	{
		CompCount++;
		swap(a[0], a[i]);
		n=n-1;
		MaxHeapify(a, 0, n, CompCount, SwapCount);
	}
}

void RepeatHeap(int n)
{
	int CompCount=0, SwapCount=0;
	for(int i =0; i<10; i++)
	{
		int* a = MakeRandArray(n);
		heap(a, n, CompCount, SwapCount);
	}
	cout<<"The average of Heap sorting "<<n<<" elements 10 times: \n   Comparison: "<<CompCount/10<<"\n   Swapping: "<<SwapCount/10<<endl;
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

	RepeatStrInsSort(100);
	RepeatMerge(100);
	RepeatKMerge(100);
	RepeatQuick(100);
	RepeatKQuick(100);
	RepeatHeap(100);

	RepeatStrInsSort(10000);
	RepeatMerge(10000);
	RepeatKMerge(10000);
	RepeatQuick(10000);
	RepeatKQuick(10000);
	RepeatHeap(10000);

	RepeatStrInsSort(1000000);
	RepeatMerge(1000000);
	RepeatKMerge(1000000);
	RepeatQuick(1000000);
	RepeatKQuick(1000000);
	RepeatHeap(1000000);
}
