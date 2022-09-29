#include <stdio.h>
#include <stdlib.h>

struct treenode {
    int val; // data
    int color; // 1-red, 0-black
    struct treenode* root_parent; // parent
    struct treenode* child_right; // right-child
    struct treenode* child_left; // left child
};

// root umum untuk semua tree 
struct treenode* root = NULL;

// func yntuk melakukan binary search tree penggantian dari treenode baru
struct treenode* bst(struct treenode* pivot, struct treenode* new_node)
{
    if (pivot == NULL)
        return new_node;
    if (new_node->val < pivot->val){
        pivot->child_left = bst(pivot->child_left, new_node);
        pivot->child_left->root_parent = pivot;
    }
    else if (new_node->val > pivot->val){
        pivot->child_right = bst(pivot->child_right, new_node);
        pivot->child_right->root_parent = pivot;
	}
    return pivot;
}

void rightrotate(struct treenode* new_node)
{
    struct treenode* left = new_node->child_left;
    new_node->child_left = left->child_right;
    if (new_node->child_left)
        new_node->child_left->root_parent = new_node;
        left->root_parent = new_node->root_parent;
    if (!new_node->root_parent)
        root = left;
    else if (new_node == new_node->root_parent->child_left)
        new_node->root_parent->child_left = left;
    else
        new_node->root_parent->child_right = left;
        left->child_right = new_node;
        new_node->root_parent = left;
}

void leftrotate(struct treenode* new_node){
    struct treenode* right = new_node->child_right;
    new_node->child_right = right->child_left;
    if (new_node->child_right)
        new_node->child_right->root_parent = new_node;
        right->root_parent = new_node->root_parent;
    if (!new_node->root_parent)
        root = right;
    else if (new_node == new_node->root_parent->child_left)
        new_node->root_parent->child_left = right;
    else
    	new_node->root_parent->child_right = right;
        right->child_left = new_node;
        new_node->root_parent = right;
}

// color correction red-black // 1-red, 0-black
void fixup(struct treenode* root, struct treenode* pt)
{
    struct treenode* parent_pt = NULL;
    struct treenode* grand_parent_pt = NULL;
	while ((pt != root) && (pt->color != 0)&& (pt->root_parent->color == 1)){
        parent_pt = pt->root_parent;
        grand_parent_pt = pt->root_parent->root_parent;
    // case a: Parent dari pt adalah left child dari grand parent pt
    if (parent_pt == grand_parent_pt->child_left){
		struct treenode* uncle_pt = grand_parent_pt->child_right;
		//case 1 uncle dari pt hanya colour red saja yang diganti
    if (uncle_pt != NULL && uncle_pt->color == 1){
        grand_parent_pt->color = 1;
    	parent_pt->color = 0;
        uncle_pt->color = 0;
        pt = grand_parent_pt;
    }
	else {
	//case 2 adalah right child dari parent (dibutuhkan left rotation)
    if (pt == parent_pt->child_right) {
        leftrotate(parent_pt);
        pt = parent_pt;
        parent_pt = pt->root_parent;
    }
    //case 3 pt adalah leftchild dari parent (dibutuhkan right rotation)
    rightrotate(grand_parent_pt);
    int t = parent_pt->color;
    parent_pt->color = grand_parent_pt->color;
    grand_parent_pt->color = t;
    pt = parent_pt;
    }
    
    }
// case b Parent dari pt adalah rightchild dari grand parent pt
    else {
    	struct treenode* uncle_pt = grand_parent_pt->child_left;
	//case 1 uncle dari pt hanya colour red saja yang diganti
    	if ((uncle_pt != NULL) && (uncle_pt->color == 1)){
            grand_parent_pt->color = 1;
            parent_pt->color = 0;
            uncle_pt->color = 0;
            pt = grand_parent_pt;
        }
        else {
 	//case 2 adalah left child dari parent (dibutuhkan right rotation)
        	if (pt == parent_pt->child_left) {
                rightrotate(parent_pt);
                pt = parent_pt;
                parent_pt = pt->root_parent;
            }
//case 3 pt adalah righchild dari parent (dibutuhkan left rotation)
            leftrotate(grand_parent_pt);
            int t = parent_pt->color;
            parent_pt->color = grand_parent_pt->color;
        	grand_parent_pt->color = t;
            pt = parent_pt;
        }
    }
    }

        root->color = 0;
}

// Check whether BST properties has been maintained or not
void inorder(struct treenode* pivot)
{
	if (pivot == NULL)
        return;
        inorder(pivot->child_left);
        printf("%d ", pivot->val);
        inorder(pivot->child_right);
}

// driver code
int main()
{
    int n,i;
    int *a;
    printf("\nEnter No of elements: ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("\nEnter the elements (spasi terpisah): ");
    for (i = 0; i < n; i++) 
        scanf("%d",&a[i]);
		for (i = 0; i < n; i++) {
			struct treenode* new_node=(struct treenode*)malloc(sizeof(struct treenode));
            new_node->child_right = NULL;
            new_node->child_left = NULL;
            new_node->root_parent = NULL;
            new_node->val = a[i];
            new_node->color = 1; // initially color is red and all link are NULL
            root = bst(root, new_node); // insertion to the tree
			fixup(root, new_node); // properties red-black tree is checked and fixed up
        }

        printf("Inoder traversal of Created Tree:");
        inorder(root); 

        return 0;
}
