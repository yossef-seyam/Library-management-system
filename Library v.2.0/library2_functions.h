#ifndef LIBRARY2_FUNCTIONS_H
#define LIBRARY2_FUNCTIONS_H
//#include <time.h>

typedef struct profile{
    struct profil *prev;
    u32 prof_arr[50];
    u8 user_name[50];
    u8 password[50];
    struct profile *next;

}profile;



typedef struct node{
    struct node *prev;
    u8 book_name[50];
    u8 author_name[50];
    u8 id[20];
    u32 price;
    u32 time;
    struct node *next;

}node;
void pass();
void mode(node*head);
void createfirst();
void create(node *head);
void del (node*head);
void print(node *head);
void sort(node* head);
void edit(node *head);
void search(node *head);
void temp_print(node *ptr,u32 x);
void temp_del(node *ptr,node *temp,u8 i,u8 j);
void temp_sort(node *temp , node *ptr);








#endif
