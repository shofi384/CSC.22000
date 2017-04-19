/*	Shofiqur Rahman
		shofi384@gmail.com
		Shortest path algorithm for undirected graph*/

#include <iostream>
#include <vector>
#include <fstream> // For ifstream
#include <cstdlib> // For exit(1)

using namespace std;

void read_file(ifstream& inFile, int adjMax[][12])
{
	int i, j, weight;
	while (!inFile.eof())
	{
		inFile >>i >>j >>weight;
		adjMax[i][j] = weight;
	}
}

struct groupData{int index, depth, parent;
	string color;};

void enqueue(vector <int>& q, int n)
{
	q.push_back(n);
}

int dequeue(vector <int>& q)
{
	int n=q[0];
	for(int i =0; i<q.size(); i++)
	{
		q[i] = q[i+1];
	}
	q.pop_back();
	return n;
}

void BFS( int adjMax[][12], vector <groupData>& g, int n, int s)
{
	for(int i=0; i<n; i++)
	{
		groupData n;
		n.index = i;
		n.color = "white";
		n.depth = -1;
		n.parent = -1;
		g.push_back(n);
	}

	g[s].color = "gray";
	g[s].depth = 0;
	vector <int> q;
	enqueue(q, s);

	while(q.size()!=0)
	{
		int i = dequeue(q);
		for(int j=0; j<12; j++)
		{
			if(adjMax[i][j]!=-1 && g[j].color=="white")
			{
				g[j].color="gray";
				g[j].depth = g[i].depth+1;
				g[j].parent = i;
				enqueue(q,j);
			}
		}
		g[i].color = "black";
	}
}

void printPath(vector <groupData> g, int s, int e)
{
	if(s==e)
		cout<<s<<" ";
	else if(g[e].parent==-1)
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
		adjMax[i][0]=i;
		for(int j=1; j<12; j++)
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
	BFS(adjMax, g, sizeof(adjMax[0])/4, 0);

	int s=0, e=5;
	cout<<"\t The path from "<<s<<" to "<<e<<" is: ";
	printPath(g,s,e);
	cout<<"\n\t\tAnd the distance is: "<<g[e].depth<<endl;

	return 0;
}
