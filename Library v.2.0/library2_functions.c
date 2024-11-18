#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "library2_functions.h"
#define NULL ((void*) 0)
//initializing variables
u8 name[50],author[50],id[50],question[20];
f32 price;
// count var for the number of books in the inventory
static u32 count=0;
u8 a[20];
u32 result,result2;
struct node *head=NULL;


void pass()
{


    ps:
    printf("=> Please create your new password : ");
    u8 user_pass[20];
    u8 p=0;
    do
    {
        //a function to turn the scanned chars into astrisk
        user_pass[p]=getch();

        if(user_pass[0]=='\r')
        {
            printf("\nYou didn't enter a password!\n");
            goto ps;
        }
        if(user_pass[p]!='\r')
        {
            if (user_pass[p]== '\b' ){
                if (p>0){
                    printf("\b \b");
                    p--;
                }
                else {
                    p=0;
                }
            }
            else{
                printf("*");
                p++;
            }
        }

    }
    while(user_pass[p]!='\r');
    user_pass[p]='\0';

    printf("\nPassword saved !\n");


}

void mode(node*head)
{
    printf("\nselect mode :\n-------------\n");
    printf("1) Add book\n2) Delete book\n3) View books\n4) Sort books\n5) Edit books\n6) Search books\n7) Delete entire list\n8) Exit\n");
    printf("Type (h) or (?) for help.\n=> ");
    scanf("%s",&a);

    if (a[0]=='1'&& a[1]==NULL)
    {
        if (head==NULL)
        {
            //create the first node in the list
            createfirst(head);
        }
        else if (head!=NULL)
        {
            create(head);
        }

    }
    else if (a[0]=='2'&& a[1]==NULL)
    {
        del(head);
    }
    else if (a[0]=='3'&& a[1]==NULL)
    {
        print(head);
    }
    else if (a[0]=='4'&& a[1]==NULL)
    {
        sort(head);
    }
    else if (a[0]=='5'&& a[1]==NULL)
    {
        edit(head);
    }
    else if (a[0]=='6'&& a[1]==NULL)
    {
        search(head);
    }
    else if (a[0]=='7'&& a[1]==NULL)
    {
        delete_list(head);
    }
    else if (a[0]=='8'&& a[1]==NULL)
    {
        printf("Thanks for using our program.\nDesigned by :\n");
        printf("  _____  ______  __     __    _      __  __ \n");
        printf(" / ____||  ____| \\ \\   / /   / \\    |  \\/  |\n");
        printf("| (___  | |__     \\ \\_/ /   / _ \\   | \\  / |\n");
        printf(" \\___ \\ |  __|     \\   /   / ___ \\  | |\\/| |\n");
        printf(" ____) || |____     | |   / /   \\ \\ | |  | |\n");
        printf("|_____/ |______|    |_|  /_/     \\_\\|_|  |_|\n");
        printf("                                          \n");
        return;
    }
    else if ((a[0]=='h'||a[0]=='H'||a[0]=='?')&&a[1]==NULL)
    {
        printf("=========================================================================================\n");
        printf("1) add book to add the number of books you want each with a unique id and up to 50 books.\n");
        printf("Note that before you go to any function you must add one book at least in the library.\n");
        printf("2) delete book to delete any book from the library using only the id of it.\n");
        printf("3) View books to view the books you stored in the library.\n");
        printf("4) sort books to sort the books you stored in the library by alphabetical or in reverse.\n");
        printf("5) edit books to edit the data of any book you stored in the library and changing its id to a new one.\n");
        printf("6) search books to search for a specific book in the inventory.\n");
        printf("7) delete list to delete the whole library data.\n");
        printf("=========================================================================================\n");
        mode(head);
    }
    else
    {
        printf("Invalid input, please try again.\n");
        mode(head);
    }
}

void createfirst()
{

    head=(node*)malloc(sizeof(node));

    printf("Enter the book name : ");
    scanf(" %[^\n]s",&name);
    strcpy(head->book_name,name);
    printf("Enter the book author : ");
    scanf(" %[^\n]s",&author);
    strcpy(head->author_name,author);
jj:
    printf("Enter the book id : ");
    scanf(" %[^\n]s",&id);
    u8 lenn=strlen(id);
    for(u8 i=0; i<lenn ;i++){

        if (id[i]==' '){
            printf("please enter an id with no spaces.\n");
            goto jj;
        }
    }
    strcpy(head->id,id);
    pricee:
    printf("Enter the book price : ");
    f32 ch;
    u8 price_input[20]={0};
    u8 len;
    scanf("%s",&price_input);
    if((price_input[0]=='+'||price_input[0]=='-'||price_input[0]=='.')&& price_input[1] == NULL)
    {
        printf("\nInvalid input!\n");
        goto pricee;
    }

    for (len=0;len<20;len++){
        if((price_input[len]<48 || price_input[len]>57) && (price_input[len]!='\0') &&(price_input[len]!='+') && (price_input[len]!='-')&& (price_input[len]!='.')){
            printf("\nInvalid input!\n");
            goto pricee;
        }
    }
    ch=atof(price_input);
    if (ch < 0)
        ch=-ch;
    head->price=ch;

    head->time=time(NULL);
    head->next=NULL;

    count++;
    printf("Book saved successfully!\n");
    mode(head);


}

void create(node *head)
{
    node *ptr,*temp,*tmp2;
    ptr=head;
    tmp2=head;
    if (ptr==NULL)
    {
        printf("no memory\n");
        mode(head);
    }
    temp=(node*)malloc(sizeof(node));
    printf("Enter the book name : ");
    scanf(" %[^\n]s",&name);
    strcpy(temp->book_name,name);
    printf("Enter the book author : ");
    scanf(" %[^\n]s",&author);
    strcpy(temp->author_name,author);
    temp->next=NULL;
    /*linking the node to the list before scanning the id from the user
     to check for existing IDs in it*/
    while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    // end of linking
    u8 k=0;
    for (u32 u=0; u<sizeof(id)/sizeof(id[0]); u++)
    {
lol:
        if(k==5){
            printf("Try checking the library inventory!\n");
            temp->prev->next=NULL;
            free(temp);
            mode(head);
            return;
        }
        printf("Enter the book id : ");
        scanf(" %[^\n]s",&id);
        u8 lenn=strlen(id);

        for(u8 i=0; i<lenn ;i++){

            if (id[i]==' '){
                printf("please enter an id with no spaces.\n");
                goto lol;
            }
        }

        strcpy(temp->id,id);
        for (u32 i=0; u<count; u++)
        {
            //comparing user input id with already in ids
            result = strcmp(temp->id,tmp2->id);
            if (result==0)
            {
                printf("ID already exists.Please enter a unique ID.\n");
                k++;
                goto lol;
            }
            tmp2=tmp2->next;
        }

        break;
    }

    pricee:
    printf("Enter the book price : ");
    u32 ch;
    u8 price_input[20]={0};
    u8 len;
    scanf("%s",&price_input);
    if((price_input[0]=='+'||price_input[0]=='-'||price_input[0]=='.')&& price_input[1] == NULL)
    {
        printf("\nInvalid input!\n");
        goto pricee;
    }
    for (len=0;len<20;len++){
        if((price_input[len]<48 || price_input[len]>57) && (price_input[len]!='\0') &&(price_input[len]!=45) && (price_input[len]!=43)&& (price_input[len]!=46)){
            printf("\nInvalid input!\n");
            goto pricee;
        }
    }
    if (ch < 0)
        ch=-ch;
    temp->price=ch;
    temp->time = time(NULL);
    printf("Book saved successfully!\n");

    count++;
    mode(head);
    return;
}

void del (node*head)
{
    node *ptr2last,*temp,*temp2;
    ptr2last=head;
    temp=head;
    temp2=head;

    // if there is no books
    if (temp==NULL)
    {
        printf("No books added yet.Please add a book first. \n");
        mode(head);
        return;
    }

    //pointing to the last node
    while(ptr2last->next != NULL)
    {
        ptr2last=ptr2last->next;
    }

    while(1)
    {
        u32 x=0;
here:
        printf("Enter book ID you want to delete : ");
        scanf("%s",&id);

        result = strcmp(temp->id,id);
        result2 = strcmp(ptr2last->id,id);

        // if first book
        if (result==0)
        {
            temp_print(temp,x+1);
            temp_del(head,temp,0,x+1);
            return;

        }
        //if last book
        else if (result2==0)
        {
            temp_print(ptr2last,count);
            temp_del(ptr2last,temp,1,count);
            return;

        }
        //if not both

        else if (result !=0 && result2 !=0)
        {
            u32 u=1;
            while(temp2->next != NULL)
            {
                result = strcmp(temp2->id,id);
                if (result==0)
                {
                    temp_print(temp2,u);
                    temp_del(temp2,temp,2,u);
                    return;

                }
                temp2=temp2->next;
                u++;
            }
            temp2=head;

        }

        printf("Book not found.\n");
        mode(head);
        return;
    }
}

void print(node *head)
{
    u32 u=0;

    if (head==NULL)
    {
        printf("No Books saved yet.\nPlease add book first.\n");
        mode(head);
    }
    node *ptr=NULL;
    ptr = head;
    printf ("/*********************\\\n");
    printf ("|  Library Inventory  |\n");
    printf ("\\*********************/\n\n");
    printf ("The library contains %d book(s)\n",count);
    while(ptr!=NULL)
    {
        printf ("************\n");
        printf ("Book %d info\n",u+1);
        printf ("************\n");
        printf("book Name : %s\n",ptr->book_name);
        printf("book Author : %s\n",ptr->author_name);
        printf("book ID : %s\n",ptr->id);
        printf("book Price : %f\n",ptr->price);
        printf ("======================\n");
        ptr=ptr->next;
        u++;
    }
    mode(head);
    return;
}

void sort(node* head)
{
    u8 ttemp[50][20];
    f32 ttemp2;
    if (count==0)
    {
        printf("No Books saved yet.\nPlease add book first.\n");
        mode(head);
        return;
    }
    else if (count ==1)
    {
        printf("only one book added.Please add at least 2 books to sort.\n");
        mode(head);
        return;
    }
    else
    {
        node *ptr,*temp,*tempp;
        temp=head;
        tempp=head;
        ptr=head;
here:
        printf("Sort by :\n(1)Alphabetical\n(2)ID\n(3)Time Added\n(4)Reverse the list\n");
        scanf("%s",&question[0]);
        //bubble sorting
        if(question[0]=='1' && question[1]==NULL)
        {

            printf("Sort by :\n(1)Ascending\n(2)Descending\n");
            scanf("%s",&question[0]);
            if(question[0]=='1' && question[1]==NULL){

                for(temp=head; temp->next!=NULL; temp=temp->next)
                {
                    for(ptr=temp->next; ptr!=NULL; ptr=ptr->next)
                    {

                        if(strcmp(ptr->book_name,temp->book_name)<0)
                        {
                            temp_sort(temp,ptr);

                        }

                    }
                }
                printf("Done ! Book sorted alphabetically.\n");
                mode(head);
                return;

            }
            else if (question[0]=='2' && question[1]==NULL){
                for(temp=head; temp->next!=NULL; temp=temp->next)
                {
                    for(ptr=temp->next; ptr!=NULL; ptr=ptr->next)
                    {

                        if(strcmp(ptr->book_name,temp->book_name)>0)
                        {
                            temp_sort(temp,ptr);

                        }

                    }
                }
                 printf("Done ! Book sorted in Descending order.\n");
                mode(head);
                return;

            }
            else
            {
                printf("Invalid input.Please try again.\n");
                goto here;
            }

        }

        else if (question[0]=='2' && question[1]==NULL)
        {

            printf("Sort by :\n(1)Ascending\n(2)Descending\n");
            scanf("%s",&question[0]);
            if(question[0]=='1' && question[1]==NULL)
            {
                for(temp=head; temp->next!=NULL; temp=temp->next)
                {
                    for(ptr=temp->next; ptr!=NULL; ptr=ptr->next)
                    {

                        if(atoi(ptr->id)<atoi(temp->id))
                        {
                            temp_sort(temp,ptr);

                        }
                    }
                }
                printf("Done ! Book sorted by ID in Ascending order.\n");
                mode(head);
                return;

            }
            else if(question[0]=='2' && question[1]==NULL)
            {
                for(temp=head; temp->next!=NULL; temp=temp->next)
                {
                    for(ptr=temp->next; ptr!=NULL; ptr=ptr->next)
                    {

                        if(atoi(ptr->id)>atoi(temp->id))
                        {
                            temp_sort(temp,ptr);

                        }
                    }
                }
                printf("Done ! Book sorted by ID in Descending order.\n");
                mode(head);
                return;

            }
            else
            {
                printf("Invalid input.Please try again.\n");
                goto here;
            }


        }
        else if (question[0]=='3' && question[1]==NULL)
        {
            printf("Sort by :\n(1)Oldest\n(2)Latest\n");
            scanf("%s",&question[0]);
            if(question[0]=='1' && question[1]==NULL)
            {
                for(temp=head; temp->next!=NULL; temp=temp->next)
                {
                    for(ptr=temp->next; ptr!=NULL; ptr=ptr->next)
                    {

                        if(ptr->time<temp->time)
                        {
                            temp_sort(temp,ptr);

                        }

                    }
                }
                printf("Done ! Book sorted by Oldest time.\n");
                mode(head);
                return;

            }
            else if(question[0]=='2' && question[1]==NULL)
            {
                for(temp=head; temp->next!=NULL; temp=temp->next)
                {
                    for(ptr=temp->next; ptr!=NULL; ptr=ptr->next)
                    {

                        if(ptr->time>temp->time)
                        {
                            temp_sort(temp,ptr);

                        }

                    }
                }
                printf("Done ! Book sorted by Latest time.\n");
                mode(head);
                return;

            }
            else
            {
                printf("Invalid input.Please try again.\n");
                goto here;
            }




        }
        else if (question[0]=='4' && question[1]==NULL)
        {
            node *ptr1 ;
            node *ptr2 ;
            ptr1=head;
            ptr2=ptr1->next;
            ptr1->next=NULL;
            ptr1->prev=ptr2;
            while (ptr2 != NULL){
                ptr2->prev = ptr2->next;
                ptr2->next=ptr1;
                ptr1=ptr2;
                ptr2=ptr2->prev;

            }
            head=ptr1;

            printf("Done ! list reversed.\n");
            mode(head);
            return;
        }
        else
        {
            printf("Invalid input.Please try again.\n");
            goto here;
        }
    }
}

void search(node *head)
{
    node *ptr2last,*temp,*temp2;
    ptr2last=head;
    temp=head;
    temp2=head;

    // if there is no books
    if (temp==NULL)
    {
        printf("No books added yet.Please add a book first. \n");
        mode(head);
        return;
    }

    //pointing to the last node
    while(ptr2last->next != NULL)
    {
        ptr2last=ptr2last->next;
    }

    while(1)
    {
        u32 x=0;
heree:
        printf("Enter book ID you want to find : ");
        scanf("%s",&id);

        result = strcmp(temp->id,id);
        result2 = strcmp(ptr2last->id,id);

        // if first book
        if (result==0)
        {
            temp_print(temp,x+1);
            mode(head);
            return;

        }
        //if last book
        else if (result2==0)
        {
            temp_print(ptr2last,count);
            mode(head);
            return;

        }
        //if not both

        else if (result !=0 && result2 !=0)
        {
            u32 u=1;
            while(temp2->next != NULL)
            {
                result = strcmp(temp2->id,id);
                if (result==0)
                {
                    temp_print(temp2,u);
                    mode(head);
                    return;

                }
                temp2=temp2->next;
                u++;
            }
            temp2=head;

        }

        printf("ID doesn't exists.Please add another ID.\n");
        goto heree;
    }



}

void edit(node *head)
{
    node *ptr,*ptr2,*ptr3;
    u8 uid[50],p=0;
    u32 k=0;
    if (count==0)
    {
        printf("No books saved yet.please add book first.\n");
        mode(head);
        return;
    }
    else
    {
here:
        if (p==5){
            printf("Try checking the library inventory!\n");
            mode(head);
            return;
        }
        printf("Enter the id of the book you want to edit : ");
        for (u32 a=0;; a++)
        {
            scanf("%s",&id);
            for (ptr=head; ptr!=NULL; ptr=ptr->next)
            {
                result = strcmp(ptr->id,id);
                if (result==0)
                {
                    temp_print(ptr,k+1);
                    printf("Enter the Book name : ");
                    scanf(" %[^\n]s",&name);
                    strcpy(ptr->book_name,name);
                    printf("Enter the Author name : ");
                    scanf(" %[^\n]s",&author);
                    strcpy(ptr->author_name,author);
                    for(ptr2=head; ptr2->next!=NULL; ptr2=ptr2->next)
                    {
there :
                        printf("Enter the book ID : ");
                        scanf(" %[^\n]s",&uid);
                        u8 lenn=strlen(uid);
                        for(u8 i=0; i<lenn ;i++){
                            if (uid[i]==' '){
                                printf("please enter an id with no spaces.\n");
                                goto there;
                            }
                        }
                        for (ptr3=head; ptr3!=NULL; ptr3=ptr3->next)
                        {
                            result2 = strcmp (ptr3->id,uid);
                            if (result2 == 0 && strcmp(uid,id)!=0)
                            {
                                printf("The ID already exists,please enter a unique ID.\n");
                                goto there;
                                break;
                            }
                        }
                        if (result2!=0 || strcmp(uid,id)==0)
                        {
                            strcpy(ptr->id,uid);
                            break;
                        }
                        else {break;}

                    }
                    pricee:
                    printf("Enter the book price : ");
                    u32 ch;
                    u8 price_input[20]={0};
                    u8 len;
                    scanf("%s",&price_input);
                    for (len=0;len<20;len++){
                        if((price_input[len]<48 || price_input[len]>57) && (price_input[len]!='\0') &&(price_input[len]!=45) && (price_input[len]!=43)){
                            printf("\nInvalid input!\n");
                            goto pricee;
                        }
                    }
                    ch=atoi(price_input);
                    ptr->price=abs(ch);
                    printf("=>Book %d updated successfully.\n",k+1);
                    mode(head);
                    return;



                }
                k++;



            }
            printf("The ID doesn't exist.Please enter another ID\n");
            p++;
            k-=count;
            goto here;
            return;






        }

    }



}

void delete_list(node *head)
{
    if (count == 0){
        printf("No books saved yet.Please add book first.\n");
        mode(head);
        return;
    }
    else {
        printf ("Are you sure you want to delete the entire inventory ? (y/n)\n");
        scanf("%s",&question);
        if((question[0]=='Y'||question[0]=='y')&& question[1]==NULL){
            free(head);
            head=NULL;
            printf("Done ! List deleted successfully.\n");
            count=0;
            mode(head);
            return;
        }
        else if((question[0]=='n'||question[0]=='N')&& question[1]==NULL){
            mode(head);
            return;
        }
        else{
            printf("invalid input.\n");
            mode(head);
            return;
        }

    }



}

void temp_print(node *ptr,u32 x)
{
    // temporary printing for delete function
    printf ("************\n");
    printf ("Book %d info\n",x);
    printf ("************\n");
    printf ("Book name : %s\n",ptr->book_name);
    printf ("Author name : %s\n",ptr->author_name);
    printf ("Book ID : %s\n",ptr->id);
    printf ("Book Price : %d\n",ptr->price);
    printf ("======================\n");



}

void temp_del(node *ptr,node *temp,u8 i , u8 j)
{
    u8 q[20];
    for (;;)
    {
        printf ("Are you sure you want to delete this book ? (y/n)\n");
        scanf("%s",&q);
        if((q[0]=='Y'||q[0]=='y')&&q[1]==NULL)
        {
            //deleting
            if (i==0){
                // if head
                ptr = temp->next;
                free(temp);
                count--;
                printf("Done ! book %d deleted successfully.\n",j);
                head=ptr;
                return mode(head);


            }
            if (i==1){
                //if last
                ptr->prev->next=NULL;
                free(ptr);
                count--;
                printf("Done ! book %d deleted successfully.\n",j);
                return mode(head);

            }
            if (i==2){
                //if not both
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
                free(ptr);
                ptr=NULL;
                count--;
                printf("Done ! book %d deleted successfully.\n",j);
                return mode(head);
            }
        }
        else if ((q[0]=='N'||q[0]=='n')&&q[1]==NULL)
        {

            return mode(head);
        }
        else
        {
            printf("Invalid input.try again\n");
            return mode(head);
        }

    }



}

void temp_sort(node *temp , node *ptr)
{
    u8 ttemp[50][20];
    f32 ttemp2=0;u32 ttemp3=0;


    strcpy(ttemp,ptr->book_name);
    strcpy(ptr->book_name,temp->book_name);
    strcpy(temp->book_name,ttemp);

    strcpy(ttemp,ptr->author_name);
    strcpy(ptr->author_name,temp->author_name);
    strcpy(temp->author_name,ttemp);

    strcpy(ttemp,ptr->id);
    strcpy(ptr->id,temp->id);
    strcpy(temp->id,ttemp);

    ttemp2=ptr->price;
    ptr->price=temp->price;
    temp->price=ttemp2;
    ttemp2 =0;

    ttemp3=ptr->time;
    ptr->time=temp->time;
    temp->time=ttemp3;




}


