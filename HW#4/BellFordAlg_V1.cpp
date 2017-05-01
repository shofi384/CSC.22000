/*	Shofiqur Rahman
		shofi384@gmail.com
		Bellman Ford Algorithm for a directed graph g*/

#include <iostream>
#include <vector>
#include <fstream> // For ifstream
#include <cstdlib> // For exit(1)

using namespace std;

struct groupData{int depth, parent;};

void read_file(ifstream& inFile, int adjMax[][12])
{
	int i, j, weight;
	while (!inFile.eof())
	{
		inFile >>i >>j >>weight;
		adjMax[i][j] = weight;
	}
}

void singleSource(vector <groupData>& g, int n, int s)
{
	for(int i=0; i<n; i++)
	{
		groupData v;
		v.depth = 1000000000;
		v.parent = -1000000000;
		g.push_back(v);
	}
	g[s].depth = 0;
}

void relax(groupData& u, groupData& v, int w, int i)
{
	if(v.depth>(u.depth+w))
	{
		v.depth = (u.depth+w);
		v.parent=i;
	}
}

bool BellFord( int adjMax[][12], vector <groupData>& g, int n, int s)
{
	singleSource(g, n, s);
	for(int k=1; k<g.size(); k++)
	{
		for(int i=0;i<g.size(); i++)
		{
			for(int j=0; j<12; j++)
			{
				if(adjMax[i][j]!=-1)
				{
					relax(g[i], g[j], adjMax[i][j], i);
				}
			}
		}
	}

	for(int i=0;i<g.size(); i++)
	{
		for(int j=0; j<12; j++)
		{
			if(adjMax[i][j]!=-1)
				if(g[j].depth>g[i].depth+adjMax[i][j])
					return false;
		}
	}
	return true;
}

void printPath(vector <groupData> g, int s, int e)
{
	if(s==e)
		cout<<s<<" ";
	else if(g[e].parent==-1000000000)
		cout<<"\tNo path from "<<s<<" to "<<e<<" exists!"<<endl;
	else
	{
		printPath(g, s, g[e].parent);
		cout<<e<<" ";
	}
}

int main()
{
	int adjMax[12][12];
	for(int i=0; i<12; i++)
	{
		for(int j=0; j<12; j++)
		{
			adjMax[i][j] = -1;
		}
	}
	ifstream inFile;
	inFile.open("input.txt"); // Open the file
	// Check if the file is opened or not; Exit if not
	if (inFile.fail())
		{
			cout << "Fail to open the file" << endl;
			exit(1);
		}
	read_file(inFile, adjMax);
	inFile.close(); // Close the file

	vector <groupData> g;
	BellFord(adjMax, g, sizeof(adjMax[0])/4, 0);

	int s=0, e=11;
	cout<<"\t The path from "<<s<<" to "<<e<<" on a directed graph is: ";
	printPath(g,s,e);
	cout<<"\n\t\tAnd the distance is: "<<g[e].depth<<endl;

	return 0;
}
