//! binary search trees
//& left < root < right (generally unique nodes)

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

//? class for node
class Node {

public:
    //^ data, left, right
    int data;
    Node* left;
    Node* right;

    //^ constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }

};
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


//* function for constructing binary search tree (by insertion)
Node* insert(Node* root, int val) {

    //^ base case
    if(root == NULL) {
        return new Node(val);
    }

    //todo insert data in sorted manner
    if(val < root -> data) {
        root -> left = insert(root -> left, val);
    }
    else {
        root -> right = insert(root -> right, val);
    }
    return root;
}

//* build tree
Node* buildTree(std :: vector<int> arr) {

    Node* root = NULL;

    for(int val : arr) {
        root = insert(root, val);
    }

    return root;
}

//* inorder tarversal for varifying
void inorder(Node* root) {

    if(root == NULL) return;

    inorder(root -> left);
    std :: cout << root -> data << " ";
    inorder(root -> right);
}

//* search in binary search tree
bool search(Node* root, int target) {

    //^ base case
    if(root == NULL) return false;

    if(root -> data == target) return true;

    if(root -> data > target) {
        return search(root -> left, target);
    }
    else {
        return search(root -> right, target);
    }

    return false;
}

//* delete Node in BST : leetcode 450
Node* getIS(Node* root) { // leftmost node in right subtree
    while(root != NULL && root -> left != NULL) {
        root = root -> left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {

    //^ base case (if key doesn't exist in tree)
    if(root == NULL) return NULL;

    //~ search for key
    if(key < root -> data) {
        root -> left = deleteNode(root -> left, key);
    }
    else if (key > root -> data) {
        root -> right = deleteNode(root -> right, key);
    }
    //? root == key
    else {

        //& case 1 : delete leaf node
        if(root -> left == NULL && root -> right == NULL) {

            //todo delete node and break connection
            delete root;
            return NULL;
        }

        //& case 2 : one child node
        else if(root -> left == NULL || root -> right == NULL) {

            //todo delete that node and return not-NULL (child) to parent
            delete root;
            return root -> left == NULL ? root -> right : root -> left;
        }

        //& case 3 : two child node
        else {

            //todo find inorder successor & repalce it with root
            Node* IS = getIS(root -> right);
            root -> data = IS -> data;
            root -> right = deleteNode(root -> right, IS -> data);
        }
    }
    return root;
}

//* sorted array to BST : leetocde 108
Node* arrayTo_BST(std :: vector<int> nums, int st, int end) {

    //^ base case
    if(st > end) return NULL;

    int mid = st + (end - st)/2;

    //? mid element will be root of BST
    Node* root = new Node(nums[mid]);

    //~ recursive calls for left nd right subtree
    root -> left = arrayTo_BST(nums, st, mid-1);
    root -> right = arrayTo_BST(nums, mid+1, end);

    return root;
}

//* validate BST : leetcode 98
bool isValidBST(Node* root, Node* min, Node* max) {

    //^ base case
    if(root == NULL) return true;

    //todo compare root with min & max allowed val
    if(min != NULL && (root -> data) <= (min -> data)) return false;
    if(max != NULL && (root -> data) >= (max -> data)) return false;

    //~ recursive call for left nd right subtree
    return isValidBST(root -> left, min, root) && isValidBST(root -> right, root, max);
}

//* min distance between nodes : leetcode 783
//? inorder helper function
void inorderVector(Node* root, std :: vector<int> &nums) {

    //^ base case
    if(root == NULL) return;
    
    inorderVector(root -> left, nums);
    nums.push_back(root -> data);
    inorderVector(root -> right, nums);
}

int minDistance(Node* root) {

    //^ inorder traversal for sorted sequence
    std :: vector<int> nums;
    inorderVector(root, nums);

    int minDist = INT_MAX;
    for(int i=1; i<nums.size(); i++) {
        if(nums[i] - nums[i-1] < minDist) {
            minDist = nums[i] - nums[i-1];
        }
    }

    return minDist;
}

//* kth smallest in BST : leetcode 230
int kthSmall(Node* root, int k) {

    //^ find inorder sequence
    std :: vector<int> nums;
    inorderVector(root, nums);

    return nums[k-1];
}

//* lowest common ancestor : leetcode 235
Node* lowestComAnc(Node* root, Node* p, Node* q) {

    //^ base case
    if(root == NULL) return NULL;

    if((p -> data) < (root -> data) && (q -> data) < (root -> data)) {
        return lowestComAnc(root -> left, p, q);
    }
    else if((p -> data) > (root -> data) && (q -> data) > (root -> data)) {
        return lowestComAnc(root -> right, p, q);
    }
    else {
        return root;
    }
}

//* constrcut BST from preorder : leetcode 1008
Node* preOrderBST(std :: vector<int> nums, int i, int upperBound) {

    //^ base case(s)
    if(i >= nums.size() || nums[i] > upperBound) return NULL;

    Node* root = new Node(nums[i]);
    i++;

    root -> left =  preOrderBST(nums, i, root -> data);
    root -> right =  preOrderBST(nums, i, upperBound);

    return root;
}

//* merge two BSTs 
Node* mergeBST(Node* p, Node* q) {

    //^ array for inorder of both trees
    std :: vector<int> p_inorder;
    std :: vector<int> q_inorder;

    inorderVector(p, p_inorder);
    inorderVector(q, q_inorder);

    //todo merge both arrays
    int i=0, j=0;
    std :: vector<int> merge;

    while(i < p_inorder.size() && j < q_inorder.size()) {
        if(p_inorder[i] < q_inorder[j]) {
            merge.push_back(p_inorder[i]);
            i++;
        }
        else {
            merge.push_back(q_inorder[j]);
            j++;
        }
    }
    while(i < p_inorder.size()) {
        merge.push_back(p_inorder[i]);
    }
    while(j < q_inorder.size()) {
        merge.push_back(q_inorder[j]);
    }

    Node* root = buildTree(merge);

    return root;
}
int main() {

    std :: vector<int> arr = {3, 2, 1, 5, 6, 11, 2, 4};
    std :: vector<int> nums = {42, 52, 62, 82, 88};
    Node* root = buildTree(nums);
    Node* root2 = buildTree(arr);

    inorder(root);
    std :: cout << "\n\n";
    printTree(root);
    std :: cout << "\n\n";
    printTree(root2);
    Node* joeRoot = mergeBST(root, root2);
    std :: cout << "\n\n";
    printTree(joeRoot);

    return 0;
}