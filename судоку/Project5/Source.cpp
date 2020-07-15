
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;
int a[9][9];
int p[20];
int p1[100];
int px[100];
int py[100];
int b1[9][9][100];

void printf()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

bool strok(int i, int j, int x)
{
	for (int s = 0; s < 9; s++)
	{
		if (a[i][s] == x)
			return 0;
	}
	return 1;
}

bool column(int i, int j, int x)
{
	for (int s = 0; s < 9; s++)
	{
		if (a[s][j] == x)
			return 0;
	}
	return 1;
}

bool square(int i, int j, int x)
{
	if ((i >= 0) && (i < 3))
	{
		if ((j >= 0) && (j < 3))
		{
			for (int c = 0; c < 3; c++)
			{
				for (int d = 0; d < 3; d++)
				{
					if (a[c][d] == x)
						return 0;
				}
			}
		}
		if ((j >= 3) && (j < 6))
		{
			for (int c = 0; c < 3; c++)
			{
				for (int d = 3; d < 6; d++)
				{
					if (a[c][d] == x)
						return 0;
				}
			}
		}
		if ((j >= 6) && (j < 9))
		{
			for (int c = 0; c < 3; c++)
			{
				for (int d = 6; d < 9; d++)
				{
					if (a[c][d] == x)
						return 0;
				}
			}
		}
	}
	if ((i >= 3) && (i < 6))
	{
		if ((j >= 0) && (j < 3))
		{
			for (int c = 3; c < 6; c++)
			{
				for (int d = 0; d < 3; d++)
				{
					if (a[c][d] == x)
						return 0;
				}
			}
		}
		if ((j >= 3) && (j < 6))
		{
			for (int c = 3; c < 6; c++)
			{
				for (int d = 3; d < 6; d++)
				{
					if (a[c][d] == x)
						return 0;
				}
			}
		}
		if ((j >= 6) && (j < 9))
		{
			for (int c = 3; c < 6; c++)
			{
				for (int d = 6; d < 9; d++)
				{
					if (a[c][d] == x)
						return 0;
				}
			}
		}
	}
	if ((i >= 6) && (i < 9))
	{
		if ((j >= 0) && (j < 3))
		{
			for (int c = 6; c < 9; c++)
			{
				for (int d = 0; d < 3; d++)
				{
					if (a[c][d] == x)
						return 0;
				}
			}
		}
		if ((j >= 3) && (j < 6))
		{
			for (int c = 6; c < 9; c++)
			{
				for (int d = 3; d < 6; d++)
				{
					if (a[c][d] == x)
						return 0;
				}
			}
		}
		if ((j >= 6) && (j < 9))
		{
			for (int c = 6; c < 9; c++)
			{
				for (int d = 6; d < 9; d++)
				{
					if (a[c][d] == x)
						return 0;
				}
			}
		}
	}
	return 1;
}

bool proverka()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (a[i][j] == 0) return 0;
		}
	}
	return 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));
	bool q = 0;
	int t, x = 0, y, n = 0, m = 10, h = 0, l = 1, r = 0;
	const char* f = "Text.txt";
	ifstream in(f);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			in >> a[i][j];
			if (!a[i][j])
				l++;
		}
	}
	in.close();
	printf();
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			t = 0;
			if (a[i][j] == 0)
			{
				for (int k = 1; k < 10; k++)
				{
					if (strok(i, j, k) && column(i, j, k) && square(i, j, k))
					{
						t++;
						n = k;
					}
				}
				if (t == 0) {
					l = 0;
					cout << i << j << endl;
				}
				else {
					if (t == 1)
						a[i][j] = n;
					else if (t <= m) {
						m = t;
						x = i;
						y = j;
					}
				}
			}
		}
	}
	while (!q)
	{
		if (m)
		{
			if (l > 0) {
				for (int g = 0; g < m; g++)
				{
					for (int k = 1; k < 10; k++)
					{
						if (strok(x, y, k) && column(x, y, k) && square(x, y, k)) {
							p[g] = k;
							g++;
						}
					}
				}
				if (p[1] > 0)
				{
					p1[h] = p[1];
					px[h] = x;
					py[h] = y;
					for (int i = 0; i < 9; i++) {
						for (int j = 0; j < 9; j++) {
							b1[i][j][h] = a[i][j];
							if (x == i && y == j)
							{
								b1[i][j][h] = p1[h];
							}
						}
					}
					h++;
				}
				if (p[2] > 0)
				{
					p1[h] = p[2];
					px[h] = x;
					py[h] = y;
					for (int i = 0; i < 9; i++) {
						for (int j = 0; j < 9; j++) {
							b1[i][j][h] = a[i][j];
							if (x == i && y == j)
							{
								b1[i][j][h] = p1[h];
							}
						}
					}
					h++;
				}

				a[x][y] = p[0];
			}
			l = 1;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					t = 0;
					if (a[i][j] == 0)
					{
						for (int k = 1; k < 10; k++)
						{
							if (strok(i, j, k) && column(i, j, k) && square(i, j, k))
							{
								t++;
								n = k;
							}
						}

						if (t == 0)
						{
							l = 0;
						}
						else {
							if (t == 1)
								a[i][j] = n;
							else {
								if (t <= m) {
									m = t;
									x = i;
									y = j;
								}
							}
						}
					}
				}
			}
			if (l == 0)
			{
				h--;
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						a[i][j] = b1[i][j][h];
					}
				}
				a[px[h]][py[h]] = p1[h];
				m = 3;
			}
		}
		q = proverka();
		if (h > 99) {
			q = 1;
		}
	}
	if (h > 99) {
		cout << "нет решения" << endl;
	}
	else {
		cout << "--------------------------------------" << endl;
		printf();
	}
	cout << "Время: " << clock() / 1000.0 << endl;
	system("pause");
	return 0;
}
