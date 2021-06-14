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