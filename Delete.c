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