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