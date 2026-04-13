#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BST.h"

/*
    ===============================
         LINKED LIST FUNCTIONS
    ===============================
*/

// menambahkan kata ke lingked list
listnode addList(listnode head, char *kata)
{
    // Cek duplikasi
    listnode curr = head; // current menyimpan data pada head
    while (curr != NULL)  // loop sampai ketemu dengan NULL
    {
        if (strcmp(curr->kata, kata) == 0) // membandingkan nilai dari kata yang pada current dan data yang akan ditambahkan
            return head;                   // jika sama berarti kata sudah ada, tidak ditambahkan lagi
        curr = curr->next;                 // current sekarang berpindah ke node selanjutnya
    }

    // Buat node baru menggunakan malloc
    listnode newNode = malloc(sizeof(ListNode));
    if (newNode == NULL)
    {
        printf("Gagal alokasi memori untuk ListNode\n");
        return head;
    }

    // menyimpan kata kedalam node seukuran kata
    strncpy(newNode->kata, kata, 99);
    newNode->kata[99] = '\0';
    newNode->next = NULL;

    // Jika list kosong
    if (head == NULL)
        return newNode;

    // Tambahkan ke akhir list
    curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = newNode;

    // keluar fungsi
    return head;
}

// menghitung jumlah node
int countList(listnode head)
{
    int count = 0;
    listnode curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

// menampilkan kata dari linked list
void displayList(listnode head)
{
    int total = countList(head);
    int count = 0;
    listnode curr = head;

    while (curr != NULL && count < 5)
    {
        printf("%d. %s\n", count + 1, curr->kata);
        curr = curr->next; // berpindah ke node selanjutnya
        count++;
    }
    printf("Totalnya = %d kata\n", total);
    printf("--------------------------------\n\n");
}

// membebaskan memori pada lingked list
void freeList(listnode head)
{
    listnode curr = head;
    listnode temp;
    while (curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}
/*
    =============================
            BST FUNCTIONS
    =============================
*/

// menyisipkan data kedalam bst
treenode insertBST(treenode root, char huruf, char *kata)
{
    if (root == NULL)
    {
        // Buat node BST baru
        treenode newNode = (treenode)malloc(sizeof(TreeNode));
        if (newNode == NULL)
        {
            printf("Gagal alokasi memori untuk TreeNode\n");
            return NULL;
        }

        newNode->huruf = huruf;
        newNode->head = NULL;
        newNode->left = newNode->right = NULL;
        newNode->head = addList(newNode->head, kata);
        return newNode;
    }
    // membandingkan nilai huruf apakah lebih kecil dari root atau sebaliknya
    if (huruf < root->huruf)
        root->left = insertBST(root->left, huruf, kata);
    else if (huruf > root->huruf)
        root->right = insertBST(root->right, huruf, kata);
    else
        // Node dengan huruf ini sudah ada, tambahkan kata ke linked list
        root->head = addList(root->head, kata);

    return root;
}

// mencari huruf dalam bst
treenode findBST(treenode root, char huruf)
{
    if (root == NULL)
        return NULL;

    if (huruf == root->huruf)
        return root;
    else if (huruf < root->huruf)
        return findBST(root->left, huruf);
    else
        return findBST(root->right, huruf);
}

// mencetak data
void inorderStat(treenode root)
{
    if (root == NULL)
        return;

    // mencetak data sebeleh kiri/kecil dahulu
    inorderStat(root->left);

    int total = countList(root->head);
    printf("%-5c %d\n", root->huruf, total);
    inorderStat(root->right); // setelah root sebelah kiri habis dicetak maka root berpindah ke kanan
}

// membebaskan memory pada bst
void freeBST(treenode root)
{
    if (root == NULL)
        return;

    freeBST(root->left);
    freeBST(root->right);
    freeList(root->head);
    free(root);
}

/*
    =============================
          READ FILE FUNCTION
    =============================
*/

treenode readFile(treenode root, char *namaFile)
{
    // membuka file
    FILE *fp = fopen(namaFile, "r");
    if (fp == NULL)
    {
        printf("Error: File '%s' tidak dapat dibuka.\n", namaFile);
        return root;
    }

    char kata[100];
    // membaca satu kata per iterasi yang dibatasi sebanyak 99 hingga akhir file
    while (fscanf(fp, "%99s", kata) == 1)
    {
        // mengubah huruf pertama setiap kata menjadi huruf kecil sebelum dimasukkan kedalam bst
        char huruf = (char)tolower((unsigned char)kata[0]);
        // cek apakah huruf pertama adalah huruf atau bukan
        if (isalpha((unsigned char)huruf))
        {
            // mengubah seleruh kata menjadi huruf kecil
            for (int i = 0; kata[i]; i++)
                kata[i] = (char)tolower((unsigned char)kata[i]);

            root = insertBST(root, huruf, kata); // huruf dan kata disimpan kedalam root insert bst
        }
    }
    // menutup file dan mengembalikan nilai ke fungsi
    fclose(fp);
    return root;
}