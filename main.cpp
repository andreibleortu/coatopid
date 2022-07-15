#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("coa.txt");
ofstream fout("activation-codes.txt");
int nrr = 0;
char coa[1000][1000];

void read()
{
	while (fin.getline(coa[nrr], 20))
	{
		nrr++;
	}
}

void rmChar(int poz, int i)
{
	if (poz < strlen(coa[i]))
	{
		coa[i][poz] = coa[i][poz + 1];
		rmChar(poz + 1, i);
	}
}
void truncSpaces(int i)
{
	if (i < nrr)
	{
		for (int q = 0; q < strlen(coa[i]); q++)
		{
			if (coa[i][q] == ' ')
			{
				rmChar(q, i);
			}
		}
		truncSpaces(i + 1);
	}
}

void addDash(int i)
{
	for (int z = 5; z < strlen(coa[i]); z = z + 6)
	{
		for (int q = strlen(coa[i]); q > z; q--)
		{
			coa[i][q] = coa[i][q - 1];
		}
		coa[i][z] = '-';
	}
}
void addCh(int i)
{
	if (i < nrr)
	{
		char zero[1000] = {'0'};
		strcat(zero, coa[i]);
		strcat(zero, "AAOEM");
		strcpy(coa[i], zero);
		addDash(i);
		addCh(i + 1);
	}
}

void write(int i)
{
	if (i < nrr)
	{
		fout << coa[i] << endl;
		cout<<coa[i]<<endl;
		write(i + 1);
	}
}

int main()
{
	read();
	truncSpaces(0);
	addCh(0);
	write(0);
}