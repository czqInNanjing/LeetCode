//
// Created by Qiang Chen on 12/09/2017.
//



#include <vector>
using namespace std;
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return true;
}
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
        { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
        sort(people.begin(), people.end(), cmp);




        return vector<pair<int, int>>();
    }
};
int main() {

}