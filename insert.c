void insert(int id, char *name, float degree)
{
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->id = id;
    strcpy(student->name,name);
    student->degree= degree;
    student->next = NULL;
    if(head==NULL){
        head = student;
    }
    else{
        student->next = head;
        head = student;
    }
}