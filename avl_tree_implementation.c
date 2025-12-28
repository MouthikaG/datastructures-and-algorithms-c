#include <stdio.h>
#include <stdlib.h>
typedef struct BinaryNode {
int data;
struct BinaryNode* left;
struct BinaryNode* right;
int height;
} 
BinaryNode;
BinaryNode* createNode(int data) {
BinaryNode* newNode = (BinaryNode*) malloc(sizeof(BinaryNode));
if (!newNode) {
printf("Memory error\n");
return NULL;
}
newNode->data = data;
newNode->left = newNode->right = NULL;
newNode->height = 1;
return newNode;
}
int getHeight(BinaryNode* node) {
if (node == NULL)
return 0;
return node->height;
}
void updateHeight(BinaryNode* node) {
if (node == NULL)
return;
node->height = 1 + ((getHeight(node->left) > getHeight(node->right)) ? getHeight(node->left) :
getHeight(node->right));
}
int getBalanceFactor(BinaryNode* node) {
if (node == NULL)
return 0;
return getHeight(node->left) - getHeight(node->right);
}

BinaryNode* singleLeftRotation(BinaryNode* k1) {
BinaryNode* k2 = k1->right;
k1->right = k2->left;
k2->left = k1;
updateHeight(k1);
updateHeight(k2);
return k2;
}

BinaryNode* singleRightRotation(BinaryNode* k1) {
BinaryNode* k2 = k1->left;
k1->left = k2->right;
k2->right = k1;
updateHeight(k1);
updateHeight(k2);
return k2;
}

BinaryNode* doubleLeftRotation(BinaryNode* k1) {
k1->right = singleRightRotation(k1->right);
return singleLeftRotation(k1);
}

BinaryNode* doubleRightRotation(BinaryNode* k1) {
k1->left = singleLeftRotation(k1->left);
return singleRightRotation(k1);
}

BinaryNode* insertNode(BinaryNode* root, int data) {
if (root == NULL)
return createNode(data);

if (data< root->data)
root->left = insertNode(root->left, data);
else if (data > root->data)
root->right = insertNode(root->right, data);
else
return root;

updateHeight(root);

int balanceFactor = getBalanceFactor(root);

if (balanceFactor >1) {
if (data < root->left->data)
return singleRightRotation(root); 
else
return doubleRightRotation(root); 
}

if (balanceFactor < -1) {
if (data >root->right->data)
return singleLeftRotation(root); 
else
return doubleLeftRotation(root); 
}

return root;
}

void printInorder(BinaryNode* root) {
if (root == NULL)
return;

printInorder( root->left);
printf("%d ", root->data);
printInorder( root->right);
}

void printpreorder(BinaryNode* root) {
if (root == NULL)
return;

printf("%d ", root->data);
printpreorder( root->left);
printpreorder( root->right);
}

void printpostorder(BinaryNode* root) {
if (root == NULL)
return;

printpostorder( root->left);
printpostorder( root->right);
printf("%d ", root->data);
}
int main() {
BinaryNode* root = NULL;

root = insertNode(root,63);
root = insertNode(root,9);
root = insertNode(root,19);
root = insertNode(root,27);
root = insertNode(root,18);
root = insertNode(root,108);
root = insertNode(root,99);
root = insertNode(root,81);

printf("Inorder traversal of the AVL tree:");
printInorder(root);
printf("\n\n");
printf("Preorder traversal of the AVL tree:");
printpreorder(root);
printf("\n\n");
printf("Postorder traversal of the AVL tree:");
printpostorder(root);

return 0;
}
