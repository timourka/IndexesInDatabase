#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) x.begin(), x.end()

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;// колво массивов
	vector<vector<int>> arr(n, vector<int>());
	for (int i = 0; i < n; i++) {
		int m; cin >> m; // длинна массиива
		arr[i] = vector<int>(m);
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; // элементы массива
		}		
	}

	// полный проход по массивам
	{
		vector<int> indexes(n, 0);
		bool end = false;
		while (!end) {
			for (int i = 0; i < n; i++) {
				cout << arr[i][indexes[i]];
			}
			cout << " ";
			indexes[n - 1]++;
			for (int i = n - 1; i >= 0 && indexes[i] >= arr[i].size(); i--) {
				indexes[i] = 0;
				if (i == 0) {
					end = true;
					break;
				}
				indexes[i - 1]++;
			}
		}
		cout << "\n";
	}

	// вариант 1
	{
		int m; cin >> m;
		vector<vector<int>> neededIndexes(m, vector<int>(n)); // список комбинаций кайфовых индексов
		for (auto& it : neededIndexes) {
			for (auto& itt : it) {
				int a; cin >> a; --a;
				itt = a;
			}
		}
		sort(all(neededIndexes), [](vector<int>& first, vector<int>& second) -> bool {
			for (int i = 0; i < first.size(); i++) {
				if (first[i] != second[i])
					return first[i] < second[i];
			}
			return false;
			});
		for (auto& it : neededIndexes) {
			for (int i = 0; i < n; i++) {
				cout << arr[i][it[i]];
			}
			cout << " ";
		}
		cout << "\n";
	}	

	// вариант 2
	{
		vector<vector<int>> neededIndexes(n, vector<int>()); // список кайфовых индексов
		for (auto& it : neededIndexes) {
			int m; cin >> m;
			it = vector<int>(m);
			for (auto & itt : it) {
				int a; cin >> a; --a;
				itt = a;
			}
			sort(all(it));
		}
		vector<int> indexes(n, 0);
		bool end = false;
		while (!end) {
			for (int i = 0; i < n; i++) {
				cout << arr[i][neededIndexes[i][indexes[i]]];
			}
			cout << " ";
			indexes[n - 1]++;
			for (int i = n - 1; i >= 0 && indexes[i] >= neededIndexes[i].size(); i--) {
				indexes[i] = 0;
				if (i == 0) {
					end = true;
					break;
				}
				indexes[i - 1]++;
			}
		}
		cout << "\n";
	}
}

/*
159 153 ... 154 169 163 ... 174 259 ... 474


111 112 113 
121 122 123 
131 132 133
211 ...
*/