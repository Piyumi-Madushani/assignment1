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
int main(){
booking();
}
void booking(){
int n,m;
    int n1,n2,n3,n4,n5,n6,n7,n8;
    printf("\nEnter the following details;\n");
    FILE *fr;
    fr = fopen("flr.txt","a");

    struct contact_details s1 = {};
    printf("enter the number of rooms you wanna book:");
    scanf("%d",&n);
    printf("enter the relevent %d number(s) of room(s): \n",n);
    fprintf(fr,"\n________________________________________________________________________________________________________________________________________________________________________________________\nThis costumer have booked following %d rooms.\n",n);
    while(n>0){
       printf("enter room number: ");
       scanf("%d",&m);
       if (m==1){
        n1++;
        fprintf(fr,"%d|ac/Single room/n",n1);
        }
       else if(m==2){
        n2++;
        fprintf(fr,"%d|non-ac/Single room",n2);
      }
       else if(m==3){
        n3++;
        fprintf(fr,"%d|ac/Double room",n3); 
        }
       else if(m==4){
        n4++;
        fprintf(fr,"%d|non-ac/Double room",n4);
        }
       else if(m==5){
        n5++;
        fprintf(fr,"%d|ac/Triple room",n5);
        }
       else if(m==6){
        n6++;
        fprintf(fr,"%d|non-ac/Triple room",n6); 
        }
       else if(m==7){
        n7++;
        fprintf(fr,"%d|ac/Quat room",n7);
        }
       else if(m==8){
        n8++;
        fprintf(fr,"%d|non-ac/Quat room",n8);
       }
       else{
         printf("\nSorry, wrong input"); 
         break;}
       
       n--;
    }
    fprintf(fr,"\nCostumer Details..,\n\n ");
    printf("your name :");
    scanf("%s",&s1.name);
    printf("NIC NO :");
    scanf("%s",&s1.NIC);
    printf("contact number :");
    scanf("%d",&s1.contact_number);
    printf("address :");
    scanf("%s",s1.Address);
    fprintf (fr,"| %s \n  %s  \n  %d\n   %s  \n  |\n___________________________________________________________________________________________________________________________________________________________________________________________________________________\n\n",s1.name,s1.NIC,s1.contact_number,s1.Address);
    
    fprintf(fr,"\nCheck in/out Details..,\n");
    printf("\nCheck-in(mm/dd/yyyy):");
    scanf("%s",&s1.checkin);
    printf("Check-out(mm/dd/yyyy):");
    scanf("%s",&s1.checkout);
    fprintf(fr,"check-in:%s\ncheck-out:%s\n",s1.checkin,s1.checkout); 
    fclose(fr);

}
