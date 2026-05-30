#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct TreeNode {
    element data;
    struct TreeNode* left, * right;
}TreeNode;

TreeNode n7 = { 'G', NULL, NULL };
TreeNode n6 = { 'F', NULL, &n7 };
TreeNode n5 = { 'E', NULL, NULL };
TreeNode n4 = { 'D', NULL, NULL };
TreeNode n3 = { 'C', &n5, &n6 };
TreeNode n2 = { 'B', &n4, NULL };
TreeNode n1 = { 'A', &n2, &n3 };
TreeNode* root = &n1;

void inorder(TreeNode* root) { //중위 순회
    if (root != NULL) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode* root) { //전위 순회
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root) { //후위 순회
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {

    printf("전위 순회한 결과: ");
    preorder(root);
    printf("\n");
    printf("중위 순회한 결과: ");
    inorder(root);
    printf("\n");
    printf("후위 순회한 결과: ");
    postorder(root);
    printf("\n");
    return 0;

}