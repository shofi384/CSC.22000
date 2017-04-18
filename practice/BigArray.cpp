#include <iostream>

using namespace std;

main()
{
	int elements, index;
	cout<<"Give me the number of elements for the array: ";
	cin>>elements;
	int* a = new int[elements];
	cout<<"Building Array. . . "<<endl;

	for(int i=0; i<elements; i++)
	{
		a[i] = i;
	}
	for(int j=0; j<elements; j++)
	{
		index = rand()%elements;
		swap(a[j],a[index]);
	}
	cout<<"\nArray with "<<elements<<" elements has been built!"<<endl;
	for(int j=0; j<elements; j++)
	{
		cout<<a[j]<<" ";
	}
	cout<<endl;
	int b[elements];
	for(int j=0; j<elements; j++)
	{
		b[j]=a[j];
		cout<<b[j]<<" ";
	}
}
