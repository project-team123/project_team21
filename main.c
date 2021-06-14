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
           "5 to display all student details\n"
           "6 to save data in file\n");
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
                display();
                break;
            case 6:
                save();
                break;
        }
    } while (choice != 0);
}