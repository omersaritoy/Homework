#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void foundations(char totalname[]);
bool Check(int x, char totalname[], char service[]);
void calculationBill(int min, int SMS, int internet, int addMin, int addSMS, int addinternet, char totalname[]);
void Text(double totalcost, char totalname[]);

int main()
{
    char totalname1[100];

    printf("Please enter your name and last name:");
    gets(totalname1);

    foundations(totalname1);

    printf("\n\n");

    char totalname2[100];

    printf("Please enter your name and last name:");
    scanf("%s",&totalname2);

    foundations(totalname2);

    return 0;
}
void foundations(char totalname[])
{

    int minute, SMS, internet, addMinute, addSMS, addinternet;
    printf("%s,please enter how many minutes you used this month:", totalname);
    scanf("%d", &minute);
    if (Check(minute, totalname, "number of minutes"))
    {
        printf("%s,please enter how many SMSs you sent this month:", totalname);
        scanf("%d", &SMS);

        if (Check(SMS, totalname, "number of SMSs"))
        {
            printf("%s,please enter how many internets you spend this month:", totalname);
            scanf("%d", &internet);
            if (Check(internet, totalname, "internet usage"))
            {
                printf("%s, please specify how many additional packages you bought for calls, SMS and internet in this order:", totalname);
                scanf("%d %d %d", &addMinute, &addSMS, &addinternet);
                calculationBill(minute,SMS,internet,addMinute,addSMS,addinternet,totalname);
            }
        }
    }
}

bool Check(int x, char totalname[], char service[])
{

    if (x >= 0)
    {
        return true;
    }
    else if (x < 0)
    {
        printf("%s,cannot be smaller than 0.");
        return false;
    }
}

void calculationBill(int min, int SMS, int internet, int addMin, int addSMS, int addinternet, char totalname[])
{
    int basecost = 49;
    double totalcost, totalmin, totalSMS, totalint;

    if (min > 500 + (addMin * 250))
    {
        totalmin = (min - 500 - (addMin)*250) * (0.66) + (addMin * 12);
    }
    else if (min <= 500 + (addMin * 250))
    {
        totalmin = addMin * 12;
    }

    if (SMS > 1000 + (addSMS * 250))
    {
        totalSMS = (SMS - 1000 - (addSMS * 250)) * 0.55 + (addSMS * 12);
    }
    else if (SMS <= 1000 + (addSMS * 250))
    {
        totalSMS = addSMS * 12;
    }

    if (internet > 3072 + (addinternet * 1024))
    {
        totalint = (internet - 3072 - (addinternet * 1024)) * (0.0125) + (addinternet * 12);
    }
    else if (internet <= 3072 + (addinternet * 1024))
    {
        totalint = 12 * addinternet;
    }

    totalcost = basecost + totalint + totalmin + totalSMS;
    Text(totalcost,totalname);
}
void Text(double totalcost, char totalname[])
{
    if (totalcost <= 49)
    {
        printf("%s, total cost of your phone usage is %.2f TL. You did not exceed your base package.", totalname, totalcost);
    }
    else if (totalcost > 49 && totalcost < 100)
    {
        printf("%s,total cost of your phone usage is %.2f TL. You exceeded your base package.", totalname, totalcost);
    }
    else if(totalcost>=100)
    {
        printf("%s, total cost of your phone usage is %.2f TL. You exceeded your base package too much. We suggest you to change your base package.",totalname,totalcost);
    }

}
