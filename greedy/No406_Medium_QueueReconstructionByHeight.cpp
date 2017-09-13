//
// Created by Qiang Chen on 12/09/2017.
//
/*
 *
Question:
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

Solution:

Pick out tallest group of people and sort them in a subarray (S). Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.
For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.
E.g.
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
subarray after step 1: [[7,0], [7,1]]
subarray after step 2: [[7,0], [6,1], [7,1]]
...
 */
#include <vector>
using namespace std;
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return true;
}
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        sort(people.begin(), people.end(), comp);
        for(auto& p: people) {
            result.insert(result.begin() + p.second, p);
        }

        return result;
    }
};
//int main() {
//
//}