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
