//Shofiqur Rahman
//shofi384@gmail.com
//CSC.21100, Spring 2017

#include <iostream>
#include <vector>

using namespace std;

void binary(int n);
void hexa(int n);

main()
{
	int n;
	cout<<"Please enter any integer. \nI will print the binary and decimal equivalint of the integer: "<<endl;
	cin>>n;

	cout<<"Decimal: "<<n<<endl;
	binary(n);
	cout<<endl;
	hexa(n);
	cout<<endl;

	cout<<"Now I am going to show it for "<<n+1
			<<"\nDecimal: "<<n+1<<endl;
	binary(n+1);
	cout<<endl;
	hexa(n+1);
	cout<<endl;
}

void binary(int n)
{
	vector <int> b;
	int r;
	cout<<"The Binary: ";
	do
	{
		r=n%2;
		b.push_back(r);
		n=n/2;
	}while(n>=2);
	cout<<n<<" ";
	for(int i=b.size()-1; i>=0; i--)
	{
		cout<<b[i]<<" ";
	}
}

void hexa(int n)
{
	vector <char> b;
	int r;
	cout<<"The Hexadecimal: ";
	do
	{
		r = n%16;
		if(r==0)
			b.push_back('0');
		if(r==1)
			b.push_back('1');
		if(r==2)
			b.push_back('2');
		if(r==3)
			b.push_back('3');
		if(r==4)
			b.push_back('4');
		if(r==5)
			b.push_back('5');
		if(r==6)
			b.push_back('6');
		if(r==7)
			b.push_back('7');
		if(r==8)
			b.push_back('8');
		if(r==9)
			b.push_back('9');
		if(r==10)
			b.push_back('A');
		else if(r==11)
			b.push_back('B');
		else if(r==12)
			b.push_back('C');
		else if(r==13)
			b.push_back('D');
		else if(r==14)
			b.push_back('E');
		else if(r==15)
			b.push_back('F');
		n= n/16;
	}while(n>=16);
	cout<<n<<" ";
	for(int i=b.size()-1; i>=0; i--)
	{
		cout<<b[i]<<" ";
	}
}
