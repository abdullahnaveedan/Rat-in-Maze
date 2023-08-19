#include "myStack.h"
# include <fstream>

int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	if (fin.is_open())
	{
		cout << "File open sucessfully..\n\n";
		char n = {};
		int row = 0, col = 1;
		for (int i = 0; fin.get(n); i++)
		{
			if (n == '\n')
			{
				col++;
			}
			else if (n == ' ')
			{
			}
			else
			{
				if (col < 2)
				{
					row++;
				}
			}
		}
		fin.close();
		fin.open("input.txt");


		int **arr = new int*[row];
		for (int i = 0; i < row; i++)
		{
			arr[i] = new int[col];
		}
		int num = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				fin >> arr[i][j];
			}
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;

		myStack<char> obj(row*row);

		if (arr[0][0] == 1)
		{
			arr[0][0]++;
		}
		int k = 0, l = col - 1;

		for (int i = 0; i < row; i++)
		{
			for (k = 0; k < l;)
			{
				if (arr[i][k + 1] == 1)//go right  R
				{
					if (k < l)
					{
						//cout << "R ";
						obj.push('R');
						k++;
						arr[i][k]++;
						if (i == 1 && k == col - 1)
						{
							if (arr[i][k - 1] == 2)//go left Reverse
							{
								//cout << "L ";
								obj.pop();
								arr[i][k] = -1;
								k--;
							}
						}
					}
				}

				else if (arr[i + 1][k] == 1)//go down  D
				{
					//cout << "D ";
					obj.push('D');
					i++;
					arr[i][k]++;

				}
				else if (arr[i][k - 1] == 2)//go left Reverse
				{
					//cout << "L ";
					obj.pop();
					arr[i][k] = -1;
					k--;
				}
				else if (i > 0)//go up U
				{
					if (arr[i - 1][k] == 1)
					{
						obj.push('U');
						i--;
						arr[i][k]++;
					}
				}


			}
		}


		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] == 1)
				{
					arr[i][j] = 0;
				}
			}
		}
		cout << "\nOutput :-\n\n";

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				fout << arr[i][j] << " ";
			}
			fout << endl;
		}
		cout << endl << endl;
		obj.display();
		cout << endl << endl;
	}

	else
	{
		cout << "File not found..\n\n";
	}
	

	system("pause");
	return 0;
}