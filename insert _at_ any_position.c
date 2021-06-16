void insert_at_any_position(int id, char *name, float degree,int pos)
{
    struct Student *pervious=head;
    struct Student *newnode = (struct Student *) malloc(sizeof(struct Student));
    newnode->id=id;
    strcpy(newnode->name,name);
    newnode->degree=degree;
    newnode->next=NULL;
    if(pos==0)
    {
        newnode->next=head;
        head=newnode;
        return;
    }
    for(int i=0;i<pos-1;i++)
    {
        pervious=pervious->next;
    }
    newnode->next=pervious->next;
    pervious->next=newnode;
}