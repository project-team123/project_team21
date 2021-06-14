void displaylist() {

    struct Student *n = head;
   printf("Id\t name \t degree \n");

   while(n!= NULL) {
        printf("%d\t %s\t %f\n",n->id,n->name,n->degree);
        n = n->next;
   }
}