#include <iostream>
#include <vector>

using namespace std;

char idR = 'A';
int idI = 1;

struct R
{
	int x, y, x2, y2;
	char id;

	R(int x, int y, int x2, int y2) :
		x(x), y(y), x2(x2), y2(y2)
	{
		id = idR++;
	}
};

struct I
{
	int x, y;
	int id;

	I(int x, int y) :
		x(x), y(y)
	{
		id = idI++;
	}
};

int main(int argc, char **argv)
{
	char C;
	int x, y, x2, y2;
	vector<R> VR;
	vector<I> VI;
	vector<bool> IN;
	bool flag = 1;
	while (cin >> C)
	{
		if (C == '#')
		{
			return 0;
		}

		switch (C)
		{
		case 'R':
			cin >> x >> y >> x2 >> y2;
			VR.push_back(R(x, y, x2, y2));
			break;
		case 'I':
			cin >> x >> y;
			VI.push_back(I(x, y));
			break;
		case 'M':
			cin >> x >> y;

			if (flag)
			{
				IN.resize(VI.size(), 1);
				for (int i = 0; i < VI.size(); ++i)
				{
					for (int j = 0; j < VR.size(); ++j)
					{
						if (VI[i].x >= VR[j].x && VI[i].x <= VR[j].x2 &&
				                VI[i].y >= VR[j].y && VI[i].y <= VR[j].y2)
						{
							IN[i] = 0;
							break;
						}
					}
				}
				flag = 0;
			}

			//With Regions
			char r = ' ';
			//cout << "lee" << endl;
			for (int i = 0; i < VR.size(); ++i)
			{
				if (VR[i].id > r || r == ' ')
				{

					if (VR[i].x <= x && VR[i].x2 >= x && VR[i].y <= y
							&& VR[i].y2 >= y)
					{
						r = VR[i].id;
					}
				}
			}

			if (r == ' ')
			{
				//With Icons
				vector<int> ic;
				int d, mind = 9999999;

				for (int i = 0; i < VI.size(); ++i)
				{
					if (IN[i])
					{
						d = (x - VI[i].x) * (x - VI[i].x) + (y - VI[i].y) * (y
								- VI[i].y);
						if (d == mind)
						{
							ic.push_back(VI[i].id);
						}
						if (d < mind)
						{
							ic.clear();
							ic.push_back(VI[i].id);
							mind = d;
						}
					}

				}

				for (int i = 0; i < ic.size(); ++i)
				{
					cout.width(3);
					cout << ic[i];
				}
			}
			else
			{
				cout << r;
			}
			cout << endl;
			break;
		}
	}

}
