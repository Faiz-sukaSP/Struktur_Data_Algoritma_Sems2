// PENCEGAHAN REDEFINITOIN APABILA FILE INI DIPANGGIL OLEH LEBIH DARI 1 FILE.C
#ifndef stack_h
#define stack_h

#define MAX 100 // Memberi ukuran nilai max

// DEKLARASI STUCK ARRAY
typedef struct
{
    char data[MAX]; // deklarasi char data yang seukuran dengan MAX
    int top;
} stack_array;

// DEKLARASI STRUCT ALAMAT MEMORI PADA AWAL MENGGUNAKAN "nodeptr" SEHINGGA NEXT BUKAN LAGI "STRUCT *NODE"
typedef struct stacknode *stack_nodeptr;

// DEKLARASI STRUCK STACKNODE
typedef struct stacknode
{
    int elemen;
    stack_nodeptr next; // pointer yang menghubungkan ke alamat seterusnya
} stacknode;

// DEKLARASI STRUCK STACKLL
typedef struct stackLL
{
    stack_nodeptr top; // mendeklarasikan top yang bertipe stack_nodeptr"
    unsigned size;     // mendeklarasikan size yang bertipe unsigned sehingga ukuran selalu dicatat dengan bilangan bulat positif
} stackLL;

// ======= DEKLARASI FUNGSI =======

// Fungsi stack array
void init_array(stack_array *sa);
int isempty_array(stack_array *sa);
void push_array_char(stack_array *sa, char data);
char pop_array_char(stack_array *sa);
char peek_array_char(stack_array *sa);

// Fungsi stack array postfix
void push_array_postfix(stack_array *sa, int data);
int pop_array_postfix(stack_array *sa);

// Fungsi stack Linked List
void initLL(stackLL *ps);
int isemptyLL(stackLL *ps);
void pushLL(stackLL *ps, int element);
int popLL(stackLL *ps);
int peekLL(stackLL *ps);

// Fungsi cek kurung "()" "{}" "[]"
int cek_kurung(char expresi[]);

// Fungsi prioritas operasi
int priority(char operation);

// Fungsi mengubah infix menjadi postfix
void infix_to_postfix(char infix[], char postfix[]);

// Fungsi evaluasi postfix
int ev_post_arr(char postfix[]);
int ev_postLL(char postfix[]);

// Fungsi untuk mencegah kebocoran memori
void freeLL(stackLL *ps);

#endif