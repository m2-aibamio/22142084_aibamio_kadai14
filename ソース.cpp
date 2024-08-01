#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Search {
	int s;//真マップでのスタートマス
	int g;//真マップでのゴールマス
	int side;//真マップの横のマス数
	vector<int>cell;
	
	void Compare() {
		int length = side + 2;//仮マップの横のマス数
		int start = length + s + (s - 1) / side * 2;//仮マップでのスタートマス
		int goal = length + g + (g - 1) / side * 2;//仮マップでのゴールマス

		vector<int>v1{ -1 * length,-1,1,length };
		vector<int>v2;
		vector<int>v3;
		v2.push_back(0);
		v2.push_back(start);

		for (int j = 1;j < 100;j = j + 1) {

			int now = v2[j];
			
			int compare = 100;
			int n;
			if (now == goal)break;//現在地がgoalになったら探索終了
			for (int i = 0;i < 4;i = i + 1) {//現在地の上下左右のマスを調べる

				int c = now + v1[i];
				int target = c;
				auto pos = find(v2.begin(), v2.end(), target);

				if (pos == v2.end()) {//通ってきたマスは調べない

					
					int g = 0;//移動コスト
					int g_hat = 0;
					if (v2.size() == 2) {
						g = cell[c];
					}
					if (v2.size() > 2) {

						for (int k = 2;k < v2.size();k = k + 1) {
							int l = v2[k];
							g_hat = g_hat + cell[l];
						}
						g = cell[c] + g_hat;
					}
					int x = (c % length + 1);//調査地の座標
					int y = (c / length + 1);
					int fin_x = (goal % length + 1);//ゴールの座標
					int fin_y = (goal / length + 1);
					int h;//推定コスト
					if (x <= fin_x)h = fin_x - x + fin_y - y;
					else h = x - fin_x + fin_y - y;
					int f = g + h;
					if (f < compare) {//現在値の上下左右にあるセルの中で合計コストが最小のセルを調べる
						compare = f;
						n = c;
					}

				}
			}
			v2.push_back(n);
		}
		for (int m = 1;m < v2.size();m = m + 1) {
			int o = (v2[m] / length - 1) * (length - 2) + v2[m] % length;
			v3.push_back(o);
		}
		for (auto a : v3)cout << a << ",";
		cout << endl;



	}
};


int main() {
	vector<int>cell_1 = { 100,100,100,100,
				   		  100,100,1,  100,
						  100,3,  1,  100,
						  100,3,  1,  100,
						  100,3,  1,  100,
						  100,3,  1,  100,
						  100,3,  1,  100,
						  100,3,  1,  100,
						  100,0,  1,  100,
						  100,100,100,100, };
	Search map1{ 1,15,2, cell_1 };//[start,goal,横のマス数,map名]
	map1.Compare();

	vector<int>cell_2 = {
	100,100,100,100,100,100,100,100,100,100,
	100,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,100,100,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,100,100,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,100,100,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,100,100,100,100,1  ,1  ,100,
	100,1  ,1  ,1  ,1  ,1  ,100,1  ,1  ,100,
	100,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,100,
	100,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,100,
	100,100,100,100,100,100,100,100,100,100, };
	
	
	Search map2{ 8,105,8, cell_2 };
	map2.Compare();
}
		