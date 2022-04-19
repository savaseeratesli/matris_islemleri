#include <iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

class Matris
{
private:
	int row, col;
	int** matris;//Ýþaretçilerin adresini tutan iþaretçi

public:
	Matris(int r = 5, int c = 5);
	~Matris();
	Matris(const Matris& oth);
	int getRowNumber()
	{
		return row;
	};
	int getColumnNumber()
	{
		return col;
	};
	void setValue(int r, int c, int value);
	void randomSet();
	void identityMatrisSet();
	void display();
	void addMatris(const Matris& othMatris);//conts üzerinde deðiþiklik yapmayacaðýz deðerlerini kullanacaðýz
};

Matris::Matris(int r,int c)
{
	if (r > 0 && c > 0)
	{
		row = r;
		col = c;
	}
	else
	{
		row = 5;
		col = 5;
	}

	//Matris yer ayýrma
	matris = new int* [row];//Ýþaretçilerin adresini atadýk
	for (int i = 0; i < row; i++)
	{
		matris[i] = new int[col];

		/*
			matris[0] -> - - - - -
			matris[1] -> - - - - -
			matris[2] -> - - - - -
			matris[3] -> - - - - -
			matris[4] -> - - - - -
		*/

	}
	cout << "Matris Olusturuldu." << endl;

}

Matris::~Matris()
{
	for (int i = 0; i < row; i++)
	{
		delete[] matris[i];
		/*
			matris[0] -> 
			matris[1] -> 
			matris[2] -> 
			matris[3] -> 
			matris[4] -> 
		*/
	}
	delete[]matris;

	cout << "Matris Silindi." << endl;
}

Matris::Matris(const Matris& oth)
{
	row = oth.row;
	col = oth.col;

	matris = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matris[i] = new int[col];
		/*
			matris[0] -> - - - - -
			matris[1] -> - - - - -
			matris[2] -> - - - - -
			matris[3] -> - - - - -
			matris[4] -> - - - - -
		*/


	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matris[i][j] = oth.matris[i][j];
		}
	}
	cout << "Matris Kopyalandi." << endl;

}

void Matris::setValue(int r, int c, int value)
{
	matris[r][c] = value;//indexe göre 

}

void Matris::display()
{
	cout << "Matris: " << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matris[i][j] << "	";
		}

		cout << endl;
	}
	cout << endl;

}

void Matris::randomSet()
{
	srand(time(NULL));//Farklý deðer üret

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matris[i][j] = rand() % 10;
		}
	}

}

//Birim Matris i=j 1 
void Matris::identityMatrisSet()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j)
			{
				matris[i][j] = 1;
			}
			else
			{
				matris[i][j] = 0;
			}

		}
	}


}

void Matris::addMatris(const Matris& othMatris)
{
	if (row != othMatris.row || col != othMatris.col)
	{
		cout << "Satýr-Sutun Esit Degil!!" << endl;
		return;
	}

	Matris result(row, col);

	for (int i = 0; i < result.row; i++)
	{
		for (int j = 0; j < result.col; j++)
		{
			result.matris[i][j] = matris[i][j] + othMatris.matris[i][j];
		}
	}

	result.display();

}











