#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int key;
    struct list_node* left;
    struct list_node* right;
}list_node;

list_node* create_list_node(int key) {
    list_node* new_list_node = malloc(sizeof(list_node));
    if(!new_list_node) {
        printf((const char*)stderr, "malloc failure\n");
    }
    new_list_node->key = key;
    new_list_node->left = NULL;
    new_list_node->right = NULL;
    return new_list_node;
}

list_node* insert_list_node(list_node* root, int key) {
    if(!root) {
        return create_list_node(key);
    }
    if(key < root->key) {
        root->left = insert_list_node(root->left, key);
    }
    else if(key > root->key) {
        root->right = insert_list_node(root->right, key);
    }
    return root;
}

list_node* minValueNode(list_node* root) {
    list_node* current = root;
    while(current && current->left) {
        current = current->left;
    }
    return current;
}

list_node* delete_node(list_node* root, int key) {
    if(!root) {
        return root;
    }
    if(key < root->key) {
        root->left = delete_node(root->left, key);
    }
    else if(key > root->key) {
        root->right = delete_node(root->right, key);
    }
    else {
        if(!root->left) {
            list_node* temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right) {
            list_node* temp = root->left;
            free(root);
            return temp;
        }
        list_node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

int tree_height(list_node* root) {
    if(!root) {
        return 0;
    }
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    if(left_height >= right_height) {
        return left_height + 1;
    }
    else {
        return right_height + 1;
    }
}

int nodeExists(list_node* root, int key) {
    if(!root) {
        return 0; 
    }
    if(root->key == key) {
        return 1; 
    }
    int left_check = nodeExists(root->left, key); 
    if(left_check == 1) {
        return 1; 
    }
    int right_check = nodeExists(root->right, key); 
    if(right_check == 1) {
        return 1; 
    }
}

void inorder(list_node* root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void postorder(list_node* root) {
    if(root) {
        printf("%d ", root->key);
        postorder(root->left);
        postorder(root->right);
    }
}

void preorder(list_node* root) {
    if(root) {
        preorder(root->left);
        preorder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    list_node* root = create_list_node(5);
    insert_list_node(root, 10);
    insert_list_node(root, 15);
    inorder(root);
}
