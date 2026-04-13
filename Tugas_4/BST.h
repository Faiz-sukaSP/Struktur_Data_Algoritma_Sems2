#ifndef BST_H
#define BST_H

// mendeklarasikan struct list node
typedef struct ListNode *listnode;
typedef struct ListNode
{
    char kata[100]; // mendeklarasikan kata berukuran 99
    listnode next;
} ListNode;

// mendeklarasikan struct three node
typedef struct TreeNode *treenode;
typedef struct TreeNode
{
    char huruf;
    listnode head;        // deklarasikan variabel head bertipe struct listnode
    treenode left, right; // mendeklarasikan variabel left & right bertipe struct three node
} TreeNode;

// Linked List
listnode addList(listnode head, char *kata);
int countList(listnode head);
void displayList(listnode head);
void freeList(listnode head);

// BST
treenode insertBST(treenode root, char huruf, char *kata);
treenode findBST(treenode root, char huruf);
void inorderStat(treenode root);
void freeBST(treenode root);

// File
treenode readFile(treenode root, char *namaFile);

#endif