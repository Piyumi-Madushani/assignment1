#include<stdio.h>
#include<string.h>
/**int gh();
int main(){
   int s;
   s = gh();
   FILE *newfile;
   char g[20];

   newfile = fopen("file.txt","w");
   fprintf(newfile,"__write it__,%d\n",s);
 //  fgets(g,20,newfile);
 //  fprintf("%s\n",g);

   fclose(newfile);
   return 0;
}

int gh(){
int b=4, c=5;
int sum;
sum = b+c;
  return("%d",sum);
}
**/
struct roomlist
{
    char hed[30];
    int  acroom1;
    int  rooms1;
};
int n,m,x=3;
int update();
int write();
void booking();
void book();
int main(){
write();
FILE *file_pointer;
char c;

printf("----read the entire file----\n");
//reset the pointer
file_pointer = fopen("file.txt", "r");
while ((c = getc(file_pointer)) != EOF)
printf("%c", c);
fclose(file_pointer);
booking();
return 0;
}
void booking(){
    int v;
    char bb[3]="yes";
    char bc[3];
    printf("Do you wanna book rooms/rooms?\nsay yes or no : ");
    scanf("%s",bc);
    v = strcmp(bc,bb);
    if(v==1){
        book();
    }
    else{
        printf("THANK YOU\n");
    }
}

void book(){
   char name;
   char nic[11];
   int n;
   printf("________Please enter your information____\n");
   printf("your name:");
   scanf("%s",&name);
   printf("\nNIC number:\n");
   scanf("%s",&nic);
   printf("how many rooms do you want?\n");
   scanf("%d",&n);
   if (n!=1){
    char s[]="no",ss[3];
    int f;
    printf("Do you want same type of %d rooms?",n);
    scanf("%s",ss);
    f = strcmp(s,ss);
    if(f == 0){
        printf("enter following numbers for rooms\nsingle -->  1 \ndouble -->  2\nTrible -->  3\nQuad ---->  4\n");
        while(n>0){
            int m;
            printf("enter number of room : ");
            scanf("%d",&m);
            update();
            n--;
    }
    }
    else{
        printf("fgd");
    }

  }
}
int write(){
FILE *file_pointer;
file_pointer = fopen("file.txt", "w");
struct roomlist s1 = {"single room",x,04};
fprintf(file_pointer,"%s %d %d\n",s1.hed,s1.acroom1,s1.rooms1);
fclose(file_pointer);
}

int update(){
    FILE *file_pointer;
    file_pointer = fopen("file.txt", "w");
    if (m = 1){
       x--;
       struct roomlist s1 = {"single room",x,04};
       fprintf (file_pointer,"%s %d %d\n",s1.hed,s1.acroom1,s1.rooms1);
       fclose(file_pointer);
    }
    }
