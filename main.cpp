#include <iostream>
#include "No54_SprialMatrix.cpp"

using namespace std;
int main() {

    No54_SprialMatrix* matrix = new No54_SprialMatrix;

    vector<vector<int>> vector1 = {
            {1 , 2, 3 , 4},
            { 5, 6 , 7 , 8 },
            {9 , 10 ,11 ,12}
    };

    vector<int> result = matrix->spiralOrder(vector1);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " " ;
    }

    std::cout << "Hello, World!" << std::endl;

    return 0;
}