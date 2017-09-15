//
// Created by Qiang Chen on 12/09/2017.
//

#include <iostream>
#include <vector>
using namespace std;
int maxInfectionPeople(vector<vector<int>>& grid, vector<vector<bool>>& ever, int nowPeople);
//int main() {
//    int m, n, k;
//    cin >> m >> n >> k;
//
//    if(!m || !n || !k) return 0;
//
//    vector<vector<int>> grid(m, vector<int>(n, 0));
//    vector<vector<bool>> ever(m, vector<bool>(n, false));
//    int x,y;
//    for (int i = 0; i < k; ++i) {
//        cin >> x >> y;
//        grid[x - 1][y - 1] = 1;
//        ever[x - 1][y - 1] = true;
//    }
//    return maxInfectionPeople(grid, ever, k);
//
//}

int maxInfectionPeople(vector<vector<int>>& grid, vector<vector<bool>>& ever, int nowPeople) {

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> nextGrid(grid);
    int result = nowPeople;
    int tempPeople = nowPeople;

    while (tempPeople != 0) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(ever[i][j] && grid[i][j]) {
                    if (grid[i][j] == 5) {
                        tempPeople--;
                        nextGrid[i][j] = 0;
                    }
                    else {
                        nextGrid[i][j]++;
                        if(nextGrid[i][j] >= 4) { // able to infect others
                            if(i > 0 && !ever[i - 1][j]) {ever[i - 1][j] = true; nextGrid[i - 1][j] = 1; tempPeople++;}
                            if(j > 0 && !ever[i][j - 1]) {ever[i][j - 1] = true; nextGrid[i][j - 1] = 1; tempPeople++;}
                            if(i < m - 1 && !ever[i + 1][j]) {ever[i + 1][j] = true; nextGrid[i + 1][j] = 1; tempPeople++;}
                            if(j < n - 1 && !ever[i][j + 1]) {ever[i][j + 1] = true; nextGrid[i][j + 1] = 1; tempPeople++;}
                        }
                    }
                }


            }
        }
        cout << tempPeople << " ";
        result = max(result, tempPeople);
        grid = nextGrid;

    }

    return result;

};