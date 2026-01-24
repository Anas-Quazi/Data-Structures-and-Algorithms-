//! binary tree in C++
//todo solve recursively : left -> right -> calc root (combined)

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <map>

//? create a binary tree (preorder : root -> left -> right)
class Node {
public:
    //^ data, and adress of left nd right child
    int data;
    Node* left;
    Node* right;

    //^ constructor for initialization
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
//* build tree using preorder sequence
Node* buildTree(std :: vector<int> preSequence) {

    //^ increase val of index
    idx++;

    //^ base case
    if(preSequence[idx] == -1) return NULL;

    //todo create root node
    Node* root = new Node(preSequence[idx]);

    root -> left = buildTree(preSequence); //~ recursively build left sub-tree
    root -> right = buildTree(preSequence); //~ recursively build right sub-tree

    return root;
}

//& input and build tree
Node* inputTree(std :: string prompt) {

    //^ input val in each call
    int val;
    std :: cout << prompt; 
    std :: cin >> val;

    //^ base case
    if(val == -1) return NULL;

    //? create root nod
    Node* root = new Node(val);

    //~ left nd right sub tree calls
    root -> left = inputTree("enter left chld of " + std :: to_string(root -> data) + " : ");
    root -> right = inputTree("enter right chld of " + std :: to_string(root -> data) + " : ");

    return root;
}

//& print tree visualizaion
void printTree(Node* root) {
    if(root == NULL) return;
    
    std::queue<Node*> q;
    std::vector<std::vector<Node*>> levels;
    
    q.push(root);
    
    // Collect nodes level by level
    while(!q.empty()) {
        int size = q.size();
        std::vector<Node*> level;
        bool hasNonNull = false;
        
        for(int i = 0; i < size; i++) {
            Node* crt = q.front();
            q.pop();
            level.push_back(crt);
            
            if(crt != NULL) {
                hasNonNull = true;
                q.push(crt->left);
                q.push(crt->right);
            } else {
                q.push(NULL);
                q.push(NULL);
            }
        }
        
        levels.push_back(level);
        if(!hasNonNull) break;
    }
    
    // Remove last empty level
    if(!levels.empty()) {
        levels.pop_back();
    }
    
    // Print each level
    int height = levels.size();
    
    for(int lvl = 0; lvl < levels.size(); lvl++) {
        int spaces = pow(2, height - lvl) - 1;
        int betweenSpaces = pow(2, height - lvl + 1) - 1;
        
        // Leading spaces
        for(int i = 0; i < spaces; i++) {
            std::cout << " ";
        }
        
        // Print nodes
        for(int i = 0; i < levels[lvl].size(); i++) {
            if(levels[lvl][i] != NULL) {
                std::cout << levels[lvl][i]->data;
            } else {
                std::cout << " ";
            }
            
            if(i < levels[lvl].size() - 1) {
                for(int j = 0; j < betweenSpaces; j++) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
        
        // Print connections only if not last level
        if(lvl < levels.size() - 1) {
            int slashSpaces = pow(2, height - lvl - 1) - 1;
            
            // Leading spaces for connectors
            for(int i = 0; i < spaces - slashSpaces - 1; i++) {
                std::cout << " ";
            }
            
            for(int i = 0; i < levels[lvl].size(); i++) {
                if(levels[lvl][i] != NULL) {
                    // Left child
                    if(levels[lvl][i]->left != NULL) {
                        std::cout << "/";
                    } else {
                        std::cout << " ";
                    }
                    
                    // Middle spaces
                    for(int j = 0; j < 2 * slashSpaces + 1; j++) {
                        std::cout << " ";
                    }
                    
                    // Right child
                    if(levels[lvl][i]->right != NULL) {
                        std::cout << "\\";
                    } else {
                        std::cout << " ";
                    }
                } else {
                    for(int j = 0; j < 2 * slashSpaces + 3; j++) {
                        std::cout << " ";
                    }
                }
                
                // Between spacing
                if(i < levels[lvl].size() - 1) {
                    for(int j = 0; j < betweenSpaces - 2 * slashSpaces - 2; j++) {
                        std::cout << " ";
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}

//! tree traversal algorithms

//* 1) preorder (root -> left -> right) : O(n)
void preOrder(Node* root) {

    //^ base case
    if(root == NULL) {
        return;
    }

    std :: cout << root -> data << " ";
    //~ recursive calls for left & right sub-tree
    preOrder(root -> left);
    preOrder(root -> right);
}

//* 2) inorder (left -> root -> right) 
void inOrder(Node* root) {

    //^ base case
    if(root == NULL) return;

    //~ first call for left, then root nd right
    inOrder(root -> left);
    std :: cout << root -> data << " ";
    inOrder(root -> right);
}

//* 3) postorder (left -> right -> root) 
void postOrder(Node* root) {

    //^ base case
    if(root == NULL) return;

    postOrder(root -> left);
    postOrder(root -> right);
    std :: cout << root -> data << " ";
}

//& level order traversal (BFS)
void levelOrder(Node* root) {

    //? use queue for traversal
    std :: queue<Node*> q;
    q.push(root);

    //todo push and print values until queue is empty
    while(!q.empty()) {

        Node* crt = q.front();
        q.pop();
        std :: cout << crt -> data << " ";

        //^ include left nd right childs (if exists)
        if(crt -> left != NULL) {
            q.push(crt -> left);
        }
        if(crt -> right != NULL) {
            q.push(crt -> right);
        }
    }
}

//! leetcode problems

//* inorder traversal : leetcode 94
void inOrder(Node* root, std :: vector<int> &ans) {

    //^ base case
    if(root == NULL) return;

    //~ first call for left, then root nd right
    inOrder(root -> left, ans);
    ans.push_back(root -> data);
    inOrder(root -> right, ans);
}

std :: vector<int> inorderTraversal(Node* root) {
    std :: vector<int> ans;
    inOrder(root, ans);
    return ans;
}

//* preorder traversal : leetcode 144
// helper function
void preOrderHelper(Node* root, std :: vector<int> &ans) {

    if(root == NULL) return;

    ans.push_back(root -> data);
    preOrderHelper(root -> left, ans);
    preOrderHelper(root -> right, ans);
}

std :: vector<int> preorderTraversal(Node* root) {
    
    std :: vector<int> ans;
    preOrderHelper(root, ans);

    return ans;
}

//* postorder traversal
// helper function 
void postOrderHelper(Node* root, std :: vector<int> &ans) {

    if(root == NULL) return;

    postOrderHelper(root -> left, ans);
    postOrderHelper(root -> right, ans);
    ans.push_back(root -> data);
}

std :: vector<int> postorderTraversal(Node* root) {

    std :: vector<int> ans;
    postOrderHelper(root, ans);

    return ans;      
}


//* minimum depth : leetcode 111
int minDepth(Node* root) {
    
    //^ base case
    if(root == NULL) return 0;

    //~ rexurion...
    int leftDepth = minDepth(root -> left);
    int rightDepth = minDepth(root -> right);

    //? note answer maybe wrong because of null nodes
    int ans = std :: min(leftDepth, rightDepth) + 1;
    int ans2 = std :: max(leftDepth, rightDepth) + 1;;

    //! handle possible logical error
    return ans != 1 ? ans : ans2;
}


//* count nodes in tree : leetcode 222
int countNodes(Node* root) {

    //^ base case
    if(root == NULL) return 0;

    //~ rEcuRsiON... magiccc!
    int leftNodes = countNodes(root -> left);
    int rightNodes = countNodes(root -> right);

    //! the whole logic is here 
    return (leftNodes + rightNodes) + 1;
}

//* sum of nodes
int sumOfNodes(Node* root) {

    //^ base case
    if(root == NULL) return 0;

    int leftSum = sumOfNodes(root -> left);
    int rightSum = sumOfNodes(root -> right);

    //? the overalll logic rely here
    return leftSum + rightSum + root -> data;
}

//* same tree : leetcode 100
bool isSameTree(Node* p, Node* q) {

    //^ base case (3 in 1)
    if(p == NULL || q == NULL) return p == q;

    bool isLeftSame = isSameTree(p -> left, q -> left);
    bool isRightSame = isSameTree(p -> right, q -> right);

    return isLeftSame && isRightSame && (p -> data == q -> data);
}

//* subtree of another tree : leetcode 572
bool isSubtree(Node* root, Node* subRoot) {
        
    //^ base case
    if(root == NULL || subRoot == NULL) return root == subRoot; 
    if(root -> data == subRoot -> data && isSameTree(root, subRoot)) return true;

    //~ recursive call for left & right subtree
    return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
}

//* sum of left leaves : leetcode 404
int sumOfLeftLeaves(Node* root) {
    
    //? initialize sum with zero
    int sum = 0;
    if(root == NULL) return 0;

    if(root -> left != NULL) {
        if(root -> left -> left == NULL && root -> left -> right == NULL) {
            sum += root -> left -> data;
        }
        else {
            sum += sumOfLeftLeaves(root -> left);
        }
    }

    sum += sumOfLeftLeaves(root -> right);

    return sum;
}

//^ global answer for max val
int ans = 0;

//* max height of tree : leetcode 104
int maxHeight(Node* root) {

    //^ base case
    if(root == NULL) return 0;

    //~ nothing.. just recursion is recursioning!
    int leftHT = maxHeight(root -> left);
    int rightHT = maxHeight(root -> right);

    //! current diameter
    ans = std :: max(ans, leftHT + rightHT);

    //? the overalll logic rely here
    return std :: max(leftHT, rightHT) + 1;
}

//* diameter of binary tree : leetcode 543 
//? O(n^2) : unoptimized (271 ms)
int treeDiameter(Node* root) {

    //^ base case
    if(root == NULL) return 0;

    //~ root, left and right subtre~e diameter 
    int leftDiameter = treeDiameter(root -> left);
    int rightDiameter = treeDiameter(root -> right);
    int crtDiameter = maxHeight(root ->  left) + maxHeight(root -> right);

    return std :: max(leftDiameter, std :: max(rightDiameter, crtDiameter));
}

//? optimized approach (0 ms)
int treeDiameterOpt(Node* root) {

    //^ calling height function
    maxHeight(root);

    return ans;
}

//* top view of binary tree
void topView(Node* root) {

    //& use horizontal distance concept
    std :: map<int, int> dist; //? dist, node -> val

    //^ level order traversal
    std :: queue<std :: pair<Node*, int>> q; //? node, dist
    q.push({root, 0});

    //todo push values (also write logic here)
    while(!q.empty()) {

        Node* crt = q.front().first;
        int crtHD = q.front().second;
        q.pop();

        //^ if already exist in map
        if(dist.find(crtHD) == dist.end()) {
            dist[crtHD] = crt -> data;
        }

        //~ left nd right childs
        if(crt -> left != NULL) {
            q.push({crt -> left, crtHD-1});
        }
        if(crt -> right != NULL) {
            q.push({crt -> right, crtHD+1});
        }
    }

    for(auto val : dist) {
        std :: cout << val.second << " ";
    }
}

//* kth level of binary tree
void kthLevel(Node* root, int k) {

    //^ use level order traversal
    std :: queue<std :: pair<Node*, int>> q; 
    q.push({root, 1});

    while(!q.empty()) {

        Node* crt = q.front().first;
        int level = q.front().second;
        q.pop();

        if(level < k) {
            if(crt -> left != NULL) {
                q.push({crt -> left, level+1});
            }
            if(crt -> right != NULL) {
                q.push({crt -> right, level+1});
            }
        }

        if(level == k) {
            std :: cout << crt -> data << " ";
        }
    }

    //todo print element of queue (kth level only)
    while(!q.empty()) {

        if(q.front().second == k) {
            std :: cout << q.front().first << " ";
        }
        q.pop();
    }
}

int main() {

    //~ input preorder sequence
    std :: vector<int> preSequence = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preSequence);
    // Node* root = inputTree("enter root node : ");
    std :: cout << "\n\n";

    // preOrder(root);
    // std :: cout << "\n\n";
    // inOrder(root);
    // std :: cout << "\n\n";
    // postOrder(root);
    // std :: cout << "\n\n";
    // levelOrder(root);

    printTree(root);
    kthLevel(root, 3);

    return 0;
}