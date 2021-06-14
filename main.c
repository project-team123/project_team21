#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Student
{
    int id;
    char name[100];
    float degree;
    struct Student *next;

}*head;
void insert(int id, char *name, float degree)
{
    struct Student *current= head;
    struct Student *pervious=NULL;
    struct Student *student = (struct Student *) malloc(sizeof(struct Student));
    student->id = id;
    strcpy(student->name,name);
    student->degree= degree;
    student->next = NULL;
    while(current!=NULL&&id>current->id)
    {
        pervious=current;
        current=current->next;
    }
    if(pervious==NULL){
        student->next=head;
        head=student;
    }
    else{
        pervious->next = student;
        student->next=current;
    }
}
void search(int id)
{
    struct Student *current= head;
    while(current!=NULL){
        if(current->id==id){
            printf("ID Number: %d\n", current->id);
            printf("Name: %s\n", current->name);
            printf("degree: %f\n", current->degree);
            return;
        }
        current= current->next;
    }
    printf("Student with ID number %d is not found !!!\n",id);
}
void update(int id)
{

    struct Student *current= head;
    while(current!=NULL){

        if(current->id==id){
            printf("Record with ID number %d Found !!!\n",id);
            printf("Enter new name: ");
            scanf("%s", current->name);
            printf("Enter new degree: ");
            scanf("%f",&current->degree);
            printf("Data has been updated successfully!!!!\n");
            return;
        }
        current= current->next;

    }
    printf("Student with ID number %d is not found !!!\n",id);
}
void Delete(int id)
{
    struct Student *first = head;
    struct Student *seconed = head;
    while(first!=NULL){

        if(first->id==id){

            printf("Record with ID number %d Found !!!\n",id);

            if(first==seconed){
                head = head->next;
                free(first);
            }
            else{
                seconed->next = first->next;
                free(first);
            }
            printf("Data has been delted successfully!!!\n");
            return;

        }
        seconed = first;
        first = first->next;
    }
    printf("Student with ID number %d is not found !!!\n",id);
}
void display()
{
    char c;
    FILE *ptr;
    ptr=fopen("data.txt","r");
    while( (c=getc(ptr))!=EOF){
       printf("%c",c);
    }
    fclose(ptr);
}
void save()
{
    struct Student *current = head;
    FILE *ptr;
    ptr=fopen("data.txt","w");
    while(current!=NULL){
        fprintf(ptr,"%d\t\t%s\t\t%f\n",current->id,current->name,current->degree);
        current = current->next;
    }
    fclose(ptr);
}
int main()
{
    FILE *ptr;
    ptr=fopen("data.txt","a");
    fclose(ptr);
    head = NULL;
    int choice;
    char name[100];
    int id;
    float degree;
    printf("1 to insert student details\n"
           "2 to search for student details\n"
           "3 to delete student details\n"
           "4 to update student details\n"
           "5 to save data in file\n"
           "6 to display all student details\n");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter ID number: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                fflush(stdin);
                printf("Enter degree: ");
                scanf("%f", &degree);
                insert(id, name,degree);
                break;
            case 2:
                printf("Enter ID number to search: ");
                scanf("%d", &id);
                search(id);
                break;
            case 3:
                printf("Enter ID number to delete: ");
                scanf("%d",&id);
                Delete(id);
                break;
            case 4:
                printf("Enter ID number to update: ");
                scanf("%d",&id);
                update(id);
                break;
            case 5:
                save();
                break;
            case 6:
                display();
                break;
        }
    } while (choice != 0);
}
