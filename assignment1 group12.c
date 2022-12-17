#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,m,m1,m2,m3,m4,m5,m6;
int n,m,p=1;;
int n1=5,n2=5,n3=5,n4=5,n5=5,n6=5;
int day,mon,year,day1,day2,mon1,mon2,year1,year2,year_diff,mon_diff,day_diff;
struct contact_details
{
    char name[50];
    int  contact_number;
    char  Address[50];
    int d1,d2,m1,m2,y1,y2;
    char NIC[11];
    

};
int valid_date(int day, int mon, int year);
void difference ();
void receipt(int year_diff, int mon_diff, int day_diff);
void details();
void booking();
void Room_datails();

int main(){
    char a[3]="yes",b[3];
    int c;
    Room_datails();
    printf("\n Do you wanna book rooms (Yes/No)=");
    scanf("%s",b);
    c=strcmp(a,b);
    if(c>0){
        printf("\n~~~~~~ Thank you ~~~~~");
    }
    else{
       booking();
       valid_date(day,mon,year);
       difference();
       receipt(year_diff,mon_diff,year_diff);
    }
    return 0;

}
void Room_datails(){
 printf("\n                            ******************************************************                                \n                            *              WELCOME TO ABC HOTEL                  *\n                            *                                                    *\n                            ******************************************************                                  ");
 printf(" \n\n          ~~~~~~~~~*   ROOMS DETAILS   *~~~~~~~~~ \n ");
 printf("__________________________________________________________\n|Room ID |   Room      |      A/C       | Cost for a nigth |\n __________________________________________________________\n|   01   |  Single     |     with       |      RS.5000     |\n------------------------------------------------------------\n|   02   |  Single     |     without    |      RS.3000     |\n------------------------------------------------------------\n|   02   |  Double     |     with       |      RS.8000     |\n------------------------------------------------------------\n|   04   |  Double     |     without    |      RS.5000     |\n------------------------------------------------------------\n|   05   |  Quad       |     with       |      RS.10000    |\n------------------------------------------------------------\n|   06   |  Quad       |     without    |      RS.9000     |\n------------------------------------------------------------");

}
void booking(){
int n,m,p=1;;
    int n1=5,n2=5,n3=5,n4=5,n5=5,n6=5;
    printf("\nEnter the following details;\n");
    FILE *fr,*gr;
    fr = fopen("flr.txt","a");
    gr =fopen("fdr.txt","w+");

    struct contact_details s1 = {};
    printf("enter the number of rooms you wanna book:");
    scanf("%d",&n);
  
    printf("enter the relevent %d number(s) of room(s): \n",n);
    fprintf(fr,"\n________________________________________________________________________________________________________________________________________________________________________________________\nThis costumer have booked following %d rooms.\n",n);
    

    while(p<=n){
       printf("enter room number: ");
       scanf("%d",&m);
       if (m==1){
        n1--;
       fprintf(fr,"%d.ac/Single room\n",p);
        }
       else if(m==2){
        n2--;
       fprintf(fr,"%d.non-ac/Single room\n",p);
      }
       else if(m==3){
        n3--;
       fprintf(fr,"%d.ac/Double room\n",p);
        }
       else if(m==4){
        n4--;
       fprintf(fr,"%d.non-ac/Double room\n",p);
        }
       else if(m==5){
        n5--;
       fprintf(fr,"%d.ac/Quad room\n",p);
        }
       else if(m==6){
        n6--;
       fprintf(fr,"%d.non-ac/Quad room\n",p);
        }
      
       else{
         printf("Sorry, wrong input/n");
         p--;}

       p++;
 
    } 

   fprintf(gr,"\t\t\tAvailabilities after booking \nNo.rooms | Room Name \n   %d     |ac/Single room\n   %d     |non-ac/Single room\n   %d     |ac/Double room\n   %d     |non-ac/Double room\n   %d     |ac/Quat room\n   %d     |non-ac/Quat room\n",n1,n2,n3,n4,n5,n6);

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
   
    fclose(fr);
    fclose(gr);
    }
   void difference(){
   struct contact_details s1={};
    int day_diff, mon_diff, year_diff;
    FILE *fr;
    fr = fopen("flr.txt","a");
    fprintf(fr,"\nCheck in/out Details..,\n");
    printf("\nCheck-in(mm/dd/yyyy):");
    scanf("%d/%d/%d",&s1.m1,&s1.d1,&s1.y1);
    printf("Check-out(mm/dd/yyyy):");
    scanf("%d/%d/%d",&s1.m2,&s1.d2,&s1.y2);

    if(!valid_date(s1.d1, s1.m1, s1.y1))
    {
        printf("First date is invalid.\n");
    }

    if(!valid_date(s1.d2, s1.m2, s1.y2))
    {
        printf("Second date is invalid.\n");
        exit(0);
    }

    if(s1.d2 < s1.d1)
    {
        // borrow days from february
        if (s1.m2 == 3)
        {
            //  check whether year is a leap year
            if ((s1.y2 % 4 == 0 && s1.y2 % 100 != 0) || (s1.y2 % 400 == 0))
            {
                s1.d2 += 29;
            }

            else
            {
                s1.d2 += 28;
            }
        }

        // borrow days from April or June or September or November
        else if (s1.d2 == 5 || s1.m2 == 7 || s1.m2 == 10 || s1.m2 == 12)
        {
           s1.d2 += 30;
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
           s1.d2 += 31;
        }

        s1.m2 = s1.m2 - 1;
    }

    if (s1.m2 < s1.m1)
    {
        s1.m2 += 12;
        s1.y2 -= 1;
    }

    day_diff = s1.d2 - s1.d1;
    mon_diff = s1.m2 - s1.m1;
    year_diff = s1.y2 - s1.y1;

    printf("Difference: %d years %02d months and %02d days.", year_diff, mon_diff, day_diff);

    fprintf(fr,"check-in:%d/%d/%d\ncheck-out:%d/%d/%d\n____________________________________________________________________________________________________________________________________________________________________________________________________________________________\n",s1.m1,s1.d1,s1.y1,s1.m2,s1.d2,s1.y2);
    fclose(fr);

}

int valid_date(int day, int mon, int year)
{
    int is_valid = 1, is_leap = 0;

    if (year >= 1800 && year <= 9999)
    {

        //  check whether year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            is_leap = 1;
        }

        // check whether mon is between 1 and 12
        if(mon >= 1 && mon <= 12)
        {
            // check for days in feb
            if (mon == 2)
            {
                if (is_leap && day == 29)
                {
                    is_valid = 1;
                }
                else if(day > 28)
                {
                    is_valid = 0;
                }
            }

            // check for days in April, June, September and November
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
            {
                if (day > 30)
                {
                    is_valid = 0;
                }
            }

            // check for days in rest of the months
            // i.e Jan, Mar, May, July, Aug, Oct, Dec
            else if(day > 31)
            {
                is_valid = 0;
            }
        }

        else
        {
            is_valid = 0;
        }

    }
    else
    {
        is_valid = 0;
    }

    return is_valid;
    
}
struct contact_details s1={};
void receipt(int year_diff, int mon_diff, int day_diff){
   int m1,m2,m3,m4,m5,m6;
    int dates = 0 ;
    int total = 0;
    dates = year_diff *365 + mon_diff * 30 + day_diff;
    printf("\t\t\t HOTEL RECEIPT\n");
    printf("Customer name :\n\t\t%s\n", s1.name);

    printf("Total days = %02d \n", day_diff);
    if (m==1){
        printf("Cost per night = \n \t\t%d\n", m1);
        total = dates * m1;
        printf("Total amount =\n \t\t%d\t*\t%d = \t%d", dates,m1,total);


    }
    else if (m==2){
        printf("Cost per night = \n \t\t%d\n", m2);
        total = dates * m2;
        printf("Total amount =\n \t\t%d\t*\t%d = \t%d", dates,m2,total);


    }
    else if (m==3){
        printf("Cost per night = \n \t\t%d\n", m3);
        total = dates * m3;
        printf("Total amount =\n \t\t%d\t*\t%d = \t%d", dates,m3,total);


    }
    else if(m==4){
        printf("Cost per night = \n \t\t%d\n", m4);
        total = dates * m4;
        printf("Total amount =\n \t\t%d\t*\t%d = \t%d", dates,m4,total);


    }
    else if(m==5){
        printf("Cost per night = \n \t\t%d\n", m5);
        total = dates * m5;
        printf("Total amount =\n \t\t%d\t*\t%d = \t%d", dates,m5,total);


    }
    else {
        printf("Cost per night = \n \t\t%d\n", m6);
        total = dates * m6;
        printf("Total amount =\n \t\t%d\t*\t%d = \t%d", dates,m6,total);
}
}