#include<stdio.h>
#include<string.h>

struct contact_details
{
    char name[50];
    int  contact_number;
    char  Address[50];
    int d1,d2,m1,m2,y1,y2;
    char NIC[11];
    char room[20];
    char checkin[10];
    char checkout[10];
    int n1,n2,n3,n4,n5,n6,n7,n8;

};
void booking();
void Room_datails();
int main(){
    //int uname=25,pword=2020,u,p;
    //printf("Enter the username: ");
    //scanf("%d",&u);
    //printf("Enter the password: ");
    //scanf("%d",&p);
    //if(u==uname){
        //if(p==pword){
        //printf("Successful\n\n");
        //booking();}
        //else{
        //printf("Wrong input try again\n\n");main();}}
    //else{
        //printf("Wrong input try again\n\n");main();}

    char a[3]="yes",b[3];
    int c;

    Room_datails();
    printf("\n Do you wanna book rooms (Yes/No)=");
    scanf("%s",&b);
    c=strcmp(a,b);
    if(c>0){
        printf("\n~~~~~~ Thank you ~~~~~");
    }
    else{
       booking(); 
    }
    return 0;

}
void Room_datails(){
 printf("\n                            ******************************************************                                \n                            *              WELCOME TO ABC HOTEL                  *\n                            *                                                    *\n                            ******************************************************                                  ");
 printf(" \n\n          ~~~~~~~~~*   ROOMS DETAILS   *~~~~~~~~~ \n ");
 printf("__________________________________________________________\n|Room ID |   Room      |      A/C       | Cost for a nigth |\n __________________________________________________________\n|   01   |  Single     |     with       |      RS.5000     |\n------------------------------------------------------------\n|   02   |  Single     |     without    |      RS.3000     |\n------------------------------------------------------------\n|   02   |  Double     |     with       |      RS.8000     |\n------------------------------------------------------------\n|   04   |  Double     |     without    |      RS.5000     |\n------------------------------------------------------------\n|   05   |  Quad       |     with       |      RS.10000    |\n------------------------------------------------------------\n|   06   |  Quad       |     without    |      RS.9000     |\n------------------------------------------------------------");

}
void booking(){
int n,m;
    int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0;
    printf("\nEnter the following details;\n");
    FILE *fr,*gr;
    fr = fopen("flr.txt","a");
    gr =fopen("fdr.txt","a");

    struct contact_details s1 = {};
    printf("enter the number of rooms you wanna book:");
    scanf("%d",&n);
  
    printf("enter the relevent %d number(s) of room(s): \n",n);
    fprintf(fr,"\n________________________________________________________________________________________________________________________________________________________________________________________\nThis costumer have booked following %d rooms.\n",n);
    int p=1;
    while(p<=n){
       printf("enter room number: ");
       scanf("%d",&m);
       if (m==1){
        n1++;
      fprintf(fr,"%d.ac/Single room\n",p);
        }
       else if(m==2){
        n2++;
       fprintf(fr,"%d.non-ac/Single room\n",p);
      }
       else if(m==3){
        n3++;
       fprintf(fr,"%d.ac/Double room\n",p);
        }
       else if(m==4){
        n4++;
       fprintf(fr,"%d.non-ac/Double room\n",p);
        }
       else if(m==5){
        n5++;
       fprintf(fr,"%d.ac/Quad room\n",p);
        }
       else if(m==6){
        n6++;
       fprintf(fr,"%d.non-ac/Quad room\n",p);
        }
      
       else{
         printf("Sorry, wrong input/n");
         p--;}

       p++;
    } 
  
    fprintf(gr,"\n");
    fprintf(gr,"\n%d|ac/Single room\n%d|non-ac/Single room\n%d|ac/Double room\n%d|non-ac/Double room\n%d|ac/Triple room\n%d|non-ac/Triple room\n%d|ac/Quat room\n%d|non-ac/Quat room\n",n1,n2,n3,n4,n5,n6);

    fprintf(fr,"\nCostumer Details.., ");
    printf("your name :");
    scanf("%s",s1.name);
    printf("NIC NO :");
    scanf("%s",s1.NIC);
    printf("contact number :");
    scanf("%d",&s1.contact_number);
    printf("address :");
    scanf("%s",s1.Address);
    fprintf (fr,"\nName: %s \nNIC: %s  \nContact Number: %d\nAddress: %s  \n  \n",s1.name,s1.NIC,s1.contact_number,s1.Address);

    fprintf(fr,"\nCheck in/out Details..,\n");
    printf("\nCheck-in(mm/dd/yyyy):");
    scanf("%s",s1.checkin);
    printf("Check-out(mm/dd/yyyy):");
    scanf("%s",s1.checkout);
    fprintf(fr,"check-in:%s\ncheck-out:%s\n____________________________________________________________________________________________________________________________________________________________________________________________________________________________\n",s1.checkin,s1.checkout);
    fclose(fr);
    }
