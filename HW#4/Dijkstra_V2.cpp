/*	Shofiqur Rahman
		shofi384@gmail.com
		Dijkstra's Algorithm for a directed graph*/

#include <iostream>
#include <vector>
#include <fstream> // For ifstream
#include <cstdlib> // For exit(1)

using namespace std;

struct groupData{int index, depth, parent;};

void read_file(ifstream& inFile, int adjMax[][12])
{
	int i, j, weight;
	while (!inFile.eof())
	{
		inFile >>i >>j >>weight;
		adjMax[i][j] = weight;
	}
}

void singleSource(vector <groupData>& Q, int n, int s)
{
	for(int i=0; i<n; i++)
	{
		groupData v;
		v.index = i;
		v.depth = 1000000000;
		Q.push_back(v);
	}
	Q[s].depth = 0;
}

groupData extractMin(vector <groupData>& q)
{
	int index=0, min=q[index].depth;

	for(int i =1; i<q.size(); i++)
	{
		if(min>q[i].depth)
		{
			index=i;
			min=q[index].depth;
		}
	}
	groupData z = q[index];
	for(int j=index; j<(q.size()-1); j++)
	{
		q[j]=q[j+1];
	}
	q.pop_back();
	return z;
}

void relax(groupData& u, groupData& v, int w, int i)
{
	if(v.depth>(u.depth+w))
	{
		v.depth = (u.depth+w);
		v.parent=i;
	}
}

void dijkstra(int adjMax[][12], vector <groupData>& g, int n, int s)
{
	vector <groupData> Q;
	singleSource(Q, n, s);

	while(Q.size()!=0)
	{
		groupData z = extractMin(Q);
		g.push_back(z);
		for(int i=0; i<Q.size(); i++)
			if(adjMax[z.index][Q[i].index] != -1)
				relax(z, Q[i], adjMax[z.index][Q[i].index], z.index);
	}
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
	dijkstra(adjMax, g, sizeof(adjMax[0])/4, 0);

	int s=0, e=11;
	cout<<"\t The path from "<<s<<" to "<<e<<" on a directed graph is: ";
	printPath(g,s,e);
	cout<<"\n\t\tAnd the distance is: "<<g[e].depth<<endl;

	return 0;
}
