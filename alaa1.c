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