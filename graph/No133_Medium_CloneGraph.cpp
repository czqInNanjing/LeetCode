//
// Created by Qiang Chen on 06/09/2017.
//

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class No133_Medium_CloneGraph{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return nullptr;

        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> original;
        queue<UndirectedGraphNode*> duplicate;
        unordered_map<int, UndirectedGraphNode*> nodeMap;
        original.push(node);
        duplicate.push(newNode);
        nodeMap[node->label] = newNode;

        while (!original.empty()) {
            UndirectedGraphNode *old = original.front();
            original.pop();
            UndirectedGraphNode *dup = duplicate.front();
            duplicate.pop();

            for (int i = 0; i < old->neighbors.size(); ++i) {
                int val = old->neighbors[i]->label;
                UndirectedGraphNode* newTemp;
                if (nodeMap.count(val)) {
                    newTemp = nodeMap[val];
                } else {
                    newTemp = new UndirectedGraphNode(val);
                    nodeMap[val] = newTemp;
                    original.push(old->neighbors[i]);
                    duplicate.push(newTemp);
                }
                dup->neighbors.push_back(newTemp);
            }


        }
        return newNode;
    }
};
