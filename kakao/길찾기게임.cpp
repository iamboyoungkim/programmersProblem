#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> pre;
vector<int> post;

struct Tree {
    int x;
    int y;
    int idx;
    Tree * left;
    Tree * right;
};

// y좌표 큰, x좌표 작은 순으로 정렬
bool compare(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) return a[0] < b[0];
    else return a[1] > b[1];
}

void preOrder(Tree *tree) {
	pre.push_back(tree->idx);
	if (tree->left != NULL)	preOrder(tree->left);
	if (tree->right != NULL) preOrder(tree->right);
    return;
}

void postOrder(Tree *tree) {
	if (tree->left != NULL)	postOrder(tree->left);
	if (tree->right != NULL) postOrder(tree->right);
	post.push_back(tree->idx);
    return;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    // index 추가
    for (int i = 0; i<nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i+1);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    
    // root 만들기
    Tree tree = { nodeinfo[0][0], nodeinfo[0][1], nodeinfo[0][2], NULL, NULL };
    
    for (int i = 1; i<nodeinfo.size(); i++) {
        Tree * iterator = &tree;
        while(1) {
            // 왼쪽 노드
            if (iterator-> x > nodeinfo[i][0]) {
                if (iterator->left == NULL) {
                    iterator->left = new Tree{nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2], NULL, NULL};
                break;
                }
                else iterator = iterator -> left;
            }
            // 오른쪽 노드
            else {
                if (iterator->right == NULL) {
                    iterator->right = new Tree{nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2], NULL, NULL};
                break;
                }
                else iterator = iterator -> right;
            }
        }
    }
    preOrder(&tree);
    postOrder(&tree);
    answer.push_back(pre);
    answer.push_back(post);
    
    pre.clear();
    post.clear();
    
    return answer;
}