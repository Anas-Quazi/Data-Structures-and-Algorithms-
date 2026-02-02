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

int main() {

    std :: vector<int> arr = {3, 2, 1, 5, 6, 11, 2, 4};
    Node* root = buildTree(arr);

    inorder(root);
    std :: cout << "\n\n";
    printTree(root);
    std :: cout << search(root, 6);

    return 0;
}