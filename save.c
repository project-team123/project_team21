void save()
{
    struct Student *current = head;
    FILE *ptr;
    ptr=fopen("data.txt","a");
    while(current!=NULL){
        fprintf(ptr,"%d\t\t%s\t\t%f\n",current->id,current->name,current->degree);
        current = current->next;
    }
    fclose(ptr);
}