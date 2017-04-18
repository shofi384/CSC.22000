/*	Shofiqur Rahman
		shofi384@gmail.com	*/

#include <iostream>
#include <fstream> // For ifstream
#include <cstdlib> // For exit(1)

using namespace std;

void read_file(ifstream& inFile, int start[], int end[], int value[], bool channel[][4])
{
	int i = 0;
	while (!inFile.eof())
	{
		inFile >> start[i] >> end[i] >> value[i] >> channel[i][0] >>channel[i][1] >> channel[i][2] >> channel[i][3];
		i++;
	}
}

void merge(int a[], int p, int q, int r, int start[], int value[], bool channel[][4])
{
	int n1=q-p+1;
	int n2=r-q;
	int La[n1+1];
	int Ra[n2+1];
	int Lstart[n1+1];
	int Rstart[n2+1];
	int Lvalue[n1+1];
	int Rvalue[n2+1];
	int Lchannel[n1+1][4];
	int Rchannel[n2+1][4];

	for(int i=1;i<=n1;i++)
	{
		La[i]=a[p+i-1];
		Lstart[i]=start[p+i-1];
		Lvalue[i]=value[p+i-1];
		for(int j=0; j<4; j++)
		{
			Lchannel[i][j]=channel[p+i-1][j];
		}
	}
	for(int j=1;j<=n2;j++)
	{
		Ra[j]=a[q+j];
		Rstart[j]=start[q+j];
		Rvalue[j]=value[q+j];
		for(int k=0; k<4; k++)
		{
			Rchannel[j][k]=channel[q+j][k];
		}
	}

	La[n1+1]=900000000;
	Ra[n2+1]=900000000;

	int i=1, j=1;
	for(int k=p;k<=r;k++)
	{
		if(La[i]<=Ra[j])
		{
			a[k]=La[i];
			start[k]=Lstart[i];
			value[k]=Lvalue[i];
			for(int m=0; m<4; m++)
			{
				channel[k][m]=Lchannel[i][m];
			}
			i=i+1;
		}
		else
		{
			a[k]=Ra[j];
			start[k]=Rstart[j];
			value[k]=Rvalue[j];
			for(int m=0; m<4; m++)
			{
				channel[k][m]=Rchannel[j][m];
			}
			j=j+1;
		}
	}
}

void MergeSort(int a[], int p, int r, int start[], int value[], bool channel[][4])
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		MergeSort(a,p,q, start, value, channel);
		MergeSort(a,q+1,r, start, value, channel);
		merge(a,p,q,r, start, value, channel);
	}
}

int mostProfit(int start[], int end[], int value[], bool channel[], int n, int &advNo)
{
	int k[5000];
	k[0] = value[0];
	int m = 0;
		for(int j=1; j<n; j++)
		{
			int q = 0;
			if(start[j]>end[m] && channel[j]== 1)
			{
				for(int i=1; i<j; i++)
				{
				q = max(q, value[i] + k[j-i]);
				k[j] = q;
				}
				advNo++;
				m=j;
			}
			else
				k[j] = k[j-1];
		}
		return k[n-1];
}

int main()
{
	int start[5000], end[5000], value[5000];
	bool channel[5000][4];

	ifstream inFile;
	inFile.open("input.txt"); // Open the file
	// Check if the file is opened or not; Exit if not
	if (inFile.fail())
		{
			cout << "Fail to open the file" << endl;
			exit(1);
		}
	read_file(inFile, start, end, value, channel);
	inFile.close(); // Close the file

	MergeSort(end, 0, 5000-1, start, value, channel);
		cout<<"\nNumber of advs. and most profits that could be obtained from each channel is as follows: \n\t\t\t#Advs\tProfit"<<endl;
	for(int r=0; r<4; r++)
	{
		int advNo = 1;
		int p = mostProfit(start, end, value, channel[r], 5000, advNo);
		cout<<"\tChannel "<<r+1<<":\t"<<advNo<<"\t"<<p<<endl;

	}

	return 0;
}
