// QueenTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

int col[20], upDiag[39], downDiag[39], colNum[20];
void Queen(int count)
{
	int i, c, r;
	static int comb, row = -1;

	row++;

	/* Проверяем колонки */
	for (i = 0; i <= count-1; i++)
	{
		/* если клетка не находится под ударом */
		if (col[i] && upDiag[i + row] && downDiag[row - i + count-1])
		{
			/* запоминаем, что в строке находится ферзь */
			colNum[row] = i;

			/* маркируем колонку и диагональ */
			col[i] = 0;
			upDiag[i + row] = 0;
			downDiag[row - i + count-1] = 0;

			/* если заполнены все строки */
			if (row >= count-1)
			{
				comb++;
				/*printf("\n\n\nприкол номер - %d", comb);*/
				//for (r = 0; r <= count-1; r++)
				//{
				//	/*printf("\n");*/
				//	for (c = 0; c <= count-1; c++)
				//	{
				//		/*if (c == colNum[r])
				//			printf("[Q]");
				//		else
				//			printf("[_]");*/
				//	}
				//}
			}
			else
				Queen(count);

			/* снимаем пометку с колонки и диагонали */
			col[colNum[row]] = 1;
			upDiag[row + colNum[row]] = 1;
			downDiag[row - colNum[row] + count-1] = 1;
		}
	}
	row--; // возврат на предыдщ колонну
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int i,count;
	cin >> count;
	for (i = 0; i <= count; i++)
		col[i] = 1;
	for (i = 0; i <= count*2; i++)
		upDiag[i] = downDiag[i] = 1;
	Queen(count);
	cout << "vse";
	}

