//
// Created by Qiang Chen on 08/09/2017.
//
#include "vector"
using namespace std;
class No135_Hard_Candy{
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;

        int n = ratings.size();
        vector<int> candy(n, 1);
        for (int i = 0; i < n; ++i) {
            bool left = checkLeft(ratings,candy,i);
            bool right = checkRight(ratings, candy, i);

            if(left && right)
                continue;
            else {
                if(!left && !right) { //
                    candy[i] = max(candy[i - 1], candy[i + 1]) + 1;
                } else if(!left) {   // ratings[i] > ratings[i - 1] but candy[i] <= candy[i - 1]
                    candy[i] = candy[i - 1] + 1;
                    if(checkRight(ratings, candy, i))
                        continue;
                    else { // backtrack

                    }
                } else { // !right
                    candy[i] = candy[i + 1] + 1;
                    if (checkLeft(ratings, candy, i))
                        continue;
                    else {

                    }
                }
            }


        }



    }
    bool checkLeft(vector<int>& ratings, vector<int>& candy, int i) {
        return i == 0 || ratings[i] <= ratings[i - 1] || candy[i] > candy[i - 1];
    }
    bool checkRight(vector<int>& ratings, vector<int>& candy, int i) {
        return i == ratings.size() - 1 || ratings[i] <= ratings[i + 1] || candy[i] > candy[i + 1];
    }

};
