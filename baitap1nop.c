//excersise1: write a program to calculate age.
#include<stdio.h>
int day, cday, month, cmonth, year, cyear, age;
void inputcurrentday()
{
    printf("input current day: ");      scanf("%d",&cday); 
    printf("input current month: ");    scanf("%d",&cmonth);
    printf("input current year: ");     scanf("%d",&cyear);
}

void inputdateofbrith()
{   
    printf("input your birthday: ");     scanf("%d",&day);
    printf("input your birthmoth: ");    scanf("%d",&month);
    printf("input your birthyear: ");    scanf("%d",&year);
}
int checky(int y)
{
    if (((y % 4 == 0) && (y % 100!= 0)) || (y % 400 == 0))
    {
        return 1;
    }
    else return 0;
}
int checkd(int d, int m, int y)
{   checky(y);
    if (checky(y) == 1)
    {
        if(((m%2 == 0) && (m <= 6)) || (m == 9) || (m = 11))
        {
            if (m == 2) 
            {
                if (d > 29) return 0;
                else return 1;
            }
            else 
            {
                if (d > 30) return 0;
                else return 1;
            }
        }
        else 
        {
            if (d > 31) return 0;
            else return 1;
        }
    }
    else
    {
        if(((m%2 == 0) && (m <= 6)) || (m == 9) || (m = 11))
        {
            if (m = 2) 
            {
                if (d > 28) return 0;
                else return 1;
            }
            else 
            {
                if (d > 30) return 0;
                else return 1;
            }
        }
        else 
        {
            if (d > 31) return 0;
            else return 1;
        }
    }
}
int checkall(int d, int m, int y)
{
    if ((m < 1 || m > 12)||(y < 0)||(checkd(d,m,y)==0)) return 0;
    else return 1;
}


int calage()
{   
        if(month == cmonth)
        {
            if(day>cday) age = cyear - (year+1);
            else    age = cyear - year;
        }
        else if(month > cmonth) age = cyear - (year+1);
        else age = cyear - year;
}
int main()
{
    inputcurrentday();
    inputdateofbrith();
    while (checkall(cday,cmonth,cyear) == 0)
    {   
        if(checkall(cday,cmonth,cyear)==0)  
            {
                printf("This currentdate doesn't exist, please retype\n");
                inputcurrentday();
            }
        else
        {
            printf("Current date: %d/%d/%d\n",cday,cmonth,cyear);
        }
    }
    if (year < cyear)
    {
        while (checkall(day,month,year) == 0)
        { 
            if (checkall(day,month,year)==0)  
                {
                    printf("This birhtdate doesn't exist, please retype\n");
                    inputdateofbrith();
                }
            else
            {
                printf("Your birthdate: %d/%d/%d\n",day,month,year);
            }
        }
    }
    else if (year > cyear)
    {   
        while (year > cyear)
        {
            printf("you are come from the future, please retype\n");
            inputdateofbrith();
            while (checkall(day,month,year) == 0)
            {  
                if (checkall(day,month,year)==0)  
                    {
                        printf("This birthdate doesn't exist, please retype\n");
                        inputdateofbrith();
                    }
                else
                {
                    printf("Your birthdate: %d/%d/%d\n",day,month,year);
                }
            }
        }
    }
    calage(); ////////con truong hop la baby nua chua code :(( nhung thoi gian khong cho phep nen em chua lam
    printf("Your age: %d",age);  
}