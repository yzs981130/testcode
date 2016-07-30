#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct point
{
	double left;
	double right;
}p[1001];
int cmp(const void *a, const void *b)
{
	return (*(point*)a).left >= (*(point*)b).left;
}
int main()
{
	int n, d, t = 0;
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	while(cin >> n >> d && n != 0)
	{
		memset(p, 0, sizeof(p));
		bool flag = true;
		int tx, ty;
		for(int i = 0; i < n; i++)
		{
			cin >> tx >> ty;
			if(ty > d)
				flag = false;
			p[i].left = tx - sqrt(double(d * d - ty * ty));
			p[i].right = tx + sqrt(double(d * d - ty * ty));
		}
		if (!flag)
			cout << "Case " << ++t << ": " << -1 << endl;
		else
		{
			double st;
			qsort(p, n, sizeof(point), cmp);
			int ans = 1;
			st = p[0].right;
			for(int i = 1; i < n; i++)
			{
				if (p[i].left > st)
				{
					st = p[i].right;
					ans++;
				}
				else if (p[i].right < st)
					st = p[i].right;
			}
			cout << "Case " << ++t << ": " << ans << endl;
		}
	}
	system("pause");
	return 0;
}