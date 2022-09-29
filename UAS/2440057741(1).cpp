#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node {
int key;
struct node *left;
struct node *right;
} *root;
void search(struct node* curr, int find) {
if(curr){
if(curr->key == find){
printf("%d is found\n", find);
}
else if(find < curr->key){
search(curr->left, find);
}
else{
search(curr->right, find);
}
}
else if(!curr){
printf("%d is not found\n", find);
}
}
void insert(struct node* curr, int val) {
struct node *new_node = (struct node*) malloc(sizeof(struct node));
new_node->key = val;
new_node->left = NULL;
new_node->right = NULL;
if (root == NULL) {root = new_node;
}
else if (val != curr->key) {
if (val < curr->key && curr->left == NULL) {
curr->left = new_node;
}
else if (val > curr->key && curr->right == NULL) {
curr->right = new_node;
}
else if (val < curr->key && curr->left != NULL) {
insert(curr->left, val);
}
else if (val > curr->key && curr->right != NULL) {
insert(curr->right, val);
}
}
}
void inorder_traversal(struct node* curr) {
if (curr == NULL) return;
inorder_traversal(curr->left);
printf("%d ", curr->key);
inorder_traversal(curr->right);
}
void preorder_traversal(struct node* curr) {
if(curr == NULL){
return;
}
printf("%d ",curr->key);
preorder_traversal(curr->left);
preorder_traversal(curr->right);
}void postorder_traversal(struct node* curr) {
if(curr == NULL){
return;
}
postorder_traversal(curr->left);
postorder_traversal(curr->right);
printf("%d ",curr->key);
}
void executeDeleteNode(struct node* curr, struct node* parent) {
if(!curr->left && !curr->right){
if(curr == root){
free(curr);
 root = NULL;
}
else{
if(parent->key > curr->key){
parent->left = NULL;
}
else parent->right = NULL;
 free(curr);
 curr = NULL;
 }
}
else if(!curr->left){
if(curr == root){
 root = curr->right;
 }
 else if(parent->key < curr->key){
 parent->right = curr->right;
 }
else parent->left = curr->right;
 free(curr); curr = NULL;
}
else if(!curr->right){
 if(curr == root){
 root = curr->left;
 }
 else if(parent->key < curr->key){
 parent->right = curr->left;
 }
 else parent->left = curr->left;
 free(curr);
 curr = NULL;
}
else{
 int del;
 struct node* temp_1 = curr->left, *temp_2 = curr;
 while(temp_1->right){
 temp_2 = temp_1;
 temp_1 = temp_1->right;
 }
 del = temp_1->key;
 executeDeleteNode(temp_1, temp_2);
 curr->key = del;
}
}
void deleteNode(struct node* root, int find) {
struct node* curr = root;
struct node* parent = NULL;
while(curr) { 
 if(curr->key == find) break;
 parent = curr;
 if (find < curr->key) { curr = curr->left;
 }
 else if (find > curr->key) {
 curr = curr->right;
 }
}
if(curr == NULL){ 
 printf("%d is not found");
} 
else if(curr){
 executeDeleteNode(curr, parent);
}
}
int minValue(struct node* node) {
while(node->left){
 node = node->left;
}
return node->key;
}
int maxValue(struct node* node){
while(node->right){
 node = node->right;
}
return node->key;
}
int count(struct node* node){
if(node){
 int jumlah = 1;
 jumlah += count(node->left);
 jumlah += count(node->right);
 return jumlah;}
}
int height_of_binary_tree(struct node *node){
if(!node){
return 0;
}
else{
int left, right, res;
left = height_of_binary_tree(node->left);
 right = height_of_binary_tree(node->right);
left > right? res = left : res = right; 
 
return res + 1;
}
}
int main() {
root = NULL;
insert(root, 54);
insert(root, 81);
insert(root, 16);
insert(root, 27);
insert(root, 9);
insert(root, 36);
insert(root, 63);
insert(root, 72);
printf("Total node in BST: %d \n",count(root));
printf("Height of binary tree : %d\n ", height_of_binary_tree(root));
printf("\nInorder: "); inorder_traversal(root);
printf("\nPreorder: "); preorder_traversal(root);printf("\nPostorder: "); postorder_traversal(root);
puts(""); 
deleteNode(root, 54);
printf("\nPreorder (after del 54): "); preorder_traversal(root);
deleteNode(root, 9);
printf("\nPostorder (after del 9): "); postorder_traversal(root);
deleteNode(root, 81);
printf("\nInorder (after del 81): "); inorder_traversal(root);
puts(""); 
printf("Min value: %d \n", minValue(root));
printf("Max value: %d \n", maxValue(root));
puts(""); 
search(root, 72);
search(root, 8);
_getch();
return 0;
}
