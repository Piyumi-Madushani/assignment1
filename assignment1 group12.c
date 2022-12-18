#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,m,m1,m2,m3,m4,m5,m6,s,x;
int p=1,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0;
int n1=5,n2=5,n3=5,n4=5,n5=5,n6=5;
int w1,w2,w3,w4,w5,w6;
int day,mon,year,day1,day2,mon1,mon2,year1,year2,year_diff,mon_diff,day_diff,total;
char str1[]="AC/Single Room",str2[]="Non-AC/Single Rooms",str3[]="AC/Double Rooms",str4[]="Non-AC/Double Rooms",str5[]="AC/Quad Rooms",str6[]="Non-AC/Quad Rooms";
struct contact_details
{
    char name[50];
    int  contact_number;
    char  Address[50];
    int d1,d2,m1,m2,y1,y2;
    char NIC[11];
    char Room[23];


};
int valid_date(int day, int mon, int year);
void difference ();
void receipt(int year_diff, int mon_diff, int day_diff);
void details();
void booking();
void Room_details();

int main(){
    char a[3]="yes",b[3];
    int c;
    Room_details();
    printf("\n Do you wanna book rooms (Yes/No)=");
    scanf("%s",b);
    c=strcmp(a,b);
    if(c>0){
        printf("\n~~~~~~ Thank you ~~~~~");
    }
    else{
       booking();
       valid_date(day,mon,year);
       //difference();
       //receipt();
    }
    return 0;
}
void Room_details(){
 printf("\n                            ******************************************************                                \n                            *              WELCOME TO ABC HOTEL                  *\n                            *                                                    *\n                            ******************************************************                                  ");
 printf(" \n\n          ~~~~~~~~~*   ROOMS DETAILS   *~~~~~~~~~ \n ");
 printf("__________________________________________________________\n|Room ID |   Room      |      A/C       | Cost for a nigth |\n __________________________________________________________\n|   01   |  Single     |     with       |      RS.5000     |\n------------------------------------------------------------\n|   02   |  Single     |     without    |      RS.3000     |\n------------------------------------------------------------\n|   03   |  Double     |     with       |      RS.8000     |\n------------------------------------------------------------\n|   04   |  Double     |     without    |      RS.5000     |\n------------------------------------------------------------\n|   05   |  Quad       |     with       |      RS.10000    |\n------------------------------------------------------------\n|   06   |  Quad       |     without    |      RS.9000     |\n------------------------------------------------------------");

}
void booking(){

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
        m1++;
        if(m1>=1){
              p1=1;}
        fprintf(fr,"%d.ac/Single room\n",p);
        }
       else if(m==2){
        n2--;
        m2++;                                                       //m1,m2,m3,m4,m5 are used to calculate the number of rooms in each types.
        if(m2>=1){                                                 //n1,n2,n3,n4,n5,n6 are used to update the Availabilities file.
              p2=1;}
       fprintf(fr,"%d.non-ac/Single room\n",p);                    //by p1,p2,p3,p4,p5 use to calculate how many types of rooms are booked by user.
      }                                                            // ex: if p1=1 means ; this user have got one or more Ac/Single rooms.
       else if(m==3){
        n3--;
        m3++;
        if(m3>=1){
              p3=1;}

        fprintf(fr,"%d.ac/Double room\n",p);
         }
       else if(m==4){
        n4--;
        m4++;
        if(m4>=1){
              p4=1;}
        fprintf(fr,"%d.non-ac/Double room\n",p);
        }
       else if(m==5){
        n5--;
        m5++;
        if(m5>=1){
              p5=1;}
        fprintf(fr,"%d.ac/Quad room\n",p);
        }
       else if(m==6){
        n6--;
        m6++;
        if(m6>=1){
              p6=1;}
        fprintf(fr,"%d.non-ac/Quad room\n",p);
        }

       else{
         printf("Sorry, wrong input/n");
         p--;}

       p++;
       x=(p1+p2+p3+p4+p5+p6);         //x: number of types of rooms that customer booked.
       s= x;                         // s:to print types of rooms in slip
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
    fclose(gr);


   // find difference of check in-out
    int day_diff, mon_diff, year_diff;
    fprintf(fr,"\nCheck in/out Details..,\n");
    printf("\nCheck-in(mm/dd/yyyy):");
    scanf("%d/%d/%d",&s1.m1,&s1.d1,&s1.y1);
    printf("Check-out(mm/dd/yyyy):");
    scanf("%d/%d/%d",&s1.m2,&s1.d2,&s1.y2);
    fprintf(fr,"check-in:%d/%d/%d\ncheck-out:%d/%d/%d\n____________________________________________________________________________________________________________________________________________________________________________________________________________________________\n",s1.m1,s1.d1,s1.y1,s1.m2,s1.d2,s1.y2);
    fclose(fr);

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


      // print slip

    int dates = year_diff *365 + mon_diff * 30 + day_diff;
    while(x>0){

    if(m1!=0){
        if (w1>0){
            goto b;}                                        // m1,m2,m3,m4,m5,m6 : number of rooms that costumer want in this type
        else{                                               //w1,w2,w3,w4,w5 : this variable is used to limit the times total count
        total =total + (dates * m1*5000);}                  // by w1,if w1 is count once will not count again & statement will pass to b label statement.
      w1++;
}                                                           //b,b1,b2,b3,b4 - labels

    b:
    if (m2!=0){
        if (w2>0){
            goto b1;}
        else{
        total =total + (dates * m2*3000);
        w2++;}}

    b1:
    if (m3!=0){
        if (w3>0){
          goto b2;}
        else{
        total =total + (dates * m3*8000);
        w3++;}}

    b2:
    if (m4!=0){
        if (w4>0){
            goto b3;}
        else{
        total =total + (dates* m4*5000);
        w4++;}}

    b3:
    if (m5!=0){
      if (w5>0){
        goto b4;}
      else{
        total =total + (dates* m5*10000);
      w5++;}}

    b4:
    if (m6!=0){
      while(p6>0){
        total =total + (dates* m6*9000);
     p6--;}}
x--;
}

    printf("\n\n\n\t\t\t HOTEL RECEIPT\n");
    printf("Customer name :%s\n", s1.name);
    printf("Total days    : %02d \n", dates);
    printf("Total amount for %d rooms for %d days:Rs.%d.00\n",n,dates,total);

    while(s>0){
        if (p1!=0){
            strcpy(str1,s1.Room);
           // printf("%s\n",s1.Room);
        }else if (p2!=0){
            strcpy(s1.Room,str2);
        }else if (p3!=0){
            strcpy(s1.Room,str3);
        }else if (p4!=0){
            strcpy(s1.Room,str4);
        }else if (p5!=0){
            strcpy(s1.Room,str5);
        }else{
           strcpy(s1.Room,str6);}

     s--;
    }
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
