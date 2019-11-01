/*This program is made by :-
Name             : Nimesh Srivastava
Registration No. : 19BAI10026
Slot		 : D11+D12+D13
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>

int main()
{
	int date=0,month=0,year=0,n_day=0,n_mon=0,n_year=0,leap=0,i;
	char name[50],addr[50],app[100];
	time_t t=time(NULL);
	struct tm tm=*localtime(&t);
	clrscr();
	printf("\n\tEnter your name : ");
	gets(name);
	clrscr();
	printf("\n\tHello %s, greetings!!!",name);
	printf("\n\n\tPlease enter your date of birth as follows :-");
	printf("\n\n\tDay (in digits)   : ");
	scanf("%d",&date);
	printf("\n\tMonth (in digits) : ");
	scanf("%d",&month);
	printf("\n\tYear (4 digits)   : ");
	scanf("%d",&year);
	for(i=0;i<tm.tm_year+1900-2000;i++)
	{
		n_mon--;
		n_year--;
	}
	if((tm.tm_year+1900+1)%4==0)
	{
		leap=1;
	}
	if(date==29 && month==2)
	{
		if((tm.tm_year+1900)%4==0 && tm.tm_mon<1)
		{
			n_mon=month-(tm.tm_mon+1);
			n_mon--;
			n_day=31-tm.tm_mday+29;
		}
		else if((tm.tm_year+1900)%4==0 && tm.tm_mon==1)
		{
			n_mon=0;
			n_day=29-tm.tm_mday;
		}
		else if((tm.tm_year+1900)%4==0 && tm.tm_mon>1)
		{
			n_year=3;
			n_mon=11-tm.tm_mon;
			if((tm.tm_mon%2==0 && tm.tm_mon<=6) || (tm.tm_mon%2!=0 && tm.tm_mon>6))
			{
				n_day=31-tm.tm_mday;
				n_day+=date-1;
			}
			else if((tm.tm_mon%2!=0 && tm.tm_mon<=6) || (tm.tm_mon%2==0 && tm.tm_mon>6))
			{
				n_day=30-tm.tm_mday;
				n_day+=date-1;
			}
		}
		else if((tm.tm_year+1900)%4!=0)
		{
			for(i=0;i<4;i++)
			{
				if((tm.tm_year+1900+i)%4==0)
				{
					n_year=i-1;
				}
			}
			if(tm.tm_mon<1)
			{
				n_mon=month-(tm.tm_mon+1);
				n_mon--;
				n_day=31-tm.tm_mday+28;
			}
			else if(tm.tm_mon==1)
			{
				n_mon=0;
				n_day=28-tm.tm_mday;
			}
			else if(tm.tm_mon>1)
			{
				if((tm.tm_mon%2==0 && tm.tm_mon<=6) || (tm.tm_mon%2!=0 && tm.tm_mon>6))
				{
					n_day=31-tm.tm_mday;
					n_day+=date-1;
				}
				else if((tm.tm_mon%2!=0 && tm.tm_mon<=6) || (tm.tm_mon%2==0 && tm.tm_mon>6))
				{
					n_day=30-tm.tm_mday;
					n_day+=date-1;
				}
			}
		}
	}
	else if(month>tm.tm_mon && tm.tm_mon<=1 && month>2)
	{
		n_mon=month-(tm.tm_mon+1);
		n_mon--;
		if((tm.tm_mon%2==0 && tm.tm_mon<=6) || (tm.tm_mon%2!=0 && tm.tm_mon>6))
		{
			n_day=31-tm.tm_mday;
			n_day+=date-1;
		}
		else if((tm.tm_mon%2!=0 && tm.tm_mon<=6) || (tm.tm_mon%2==0 && tm.tm_mon>6))
		{
			n_day=30-tm.tm_mday;
			n_day+=date-1;
		}
		if((tm.tm_year+1900)%4==0)
		{
			n_day++;
		}
	}
	else if(month>tm.tm_mon && tm.tm_mon>1)
	{
		n_mon=month-(tm.tm_mon+1);
		n_mon--;
		if((tm.tm_mon%2==0 && tm.tm_mon<=6) || (tm.tm_mon%2!=0 && tm.tm_mon>6))
		{
			n_day=31-tm.tm_mday;
			n_day+=date-1;
		}
		else if((tm.tm_mon%2!=0 && tm.tm_mon<=6) || (tm.tm_mon%2==0 && tm.tm_mon>6))
		{
			n_day=30-tm.tm_mday;
			n_day+=date-1;
		}
	}
	else if(tm.tm_mon>=month)
	{
		n_mon=12-(tm.tm_mon+1);
		n_mon--;
		n_mon+=month;
		if((tm.tm_mon%2==0 && tm.tm_mon<=6) || (tm.tm_mon%2!=0 && tm.tm_mon>6))
		{
			n_day=31-tm.tm_mday;
			n_day+=date-1;
			if(leap==1)
			{
				n_day++;
			}
		}
		else if((tm.tm_mon%2!=0 && tm.tm_mon<=6) || (tm.tm_mon%2==0 && tm.tm_mon>6))
		{
			if(tm.tm_mon==1)
			{
				n_day=28-tm.tm_mday;
				n_day+=date-1;
				if(leap==1)
				{
					n_day++;
				}
			}
			else
			{
				n_day=30-tm.tm_mday;
				n_day+=date-1;
				if(leap==1)
				{
					n_day++;
				}
			}
		}
	}
	else if(month==tm.tm_mon+1)
	{
		n_mon=0;
		if(tm.tm_mday>date)
		{
			n_mon=11;
			if(tm.tm_mon==1)
			{
				n_day=28-tm.tm_mday;
				n_day+=date-1;
				if((tm.tm_year+1900)%4==0)
				{
					n_day++;
				}
			}
			else if(month<=7 && month%2==0)
			{
				n_day=30-tm.tm_mday;
				n_day+=date-1;
				if(leap==1 && month>2)
				{
					n_day++;
				}
			}
			else if(month<=7 && month%2!=0)
			{
				n_day=31-tm.tm_mday;
				n_day+=date-1;
				if((leap==1 && month>2) || ((tm.tm_year+1900)%4==0 && month==1))
				{
					n_day++;
				}
			}
			else if(month>7 && month%2==0)
			{
				n_day=31-tm.tm_mday;
				n_day+=date-1;
				if(leap==1)
				{
					n_day++;
				}
			}
			else if(month>7 && month%2!=0)
			{
				n_day=30-tm.tm_mday;
				n_day+=date-1;
				if(leap==1)
				{
					n_day++;
				}
			}
		}
		else
		{
			n_day=date-tm.tm_mday;
		}
	}
	clrscr();
	printf("\n\tThat is great %s, now let us know where you live :-",name);
	gets(addr);  //disregarding one gets() function to clear input buffer
	printf("\n\n\tAddress line 1 (initial) : ");
	gets(addr);
	strcpy(app,addr);
	printf("\n\tAddress line 2 (final)\t : ");
	gets(addr);
	strcat(app,", ");
	strcat(app,addr);
	clrscr();
	printf("\n\n\tYour information :- \n");
	printf("\n\n\tName\t\t\t\t : %s",name);
	printf("\n\n\tDate of birth\t\t\t : %d-%d-%d",date,month,year);
	printf("\n\n\tAge\t\t\t\t : %d years and %d months",tm.tm_year+1900-year-1,11-n_mon);
	if(date==29 && month==2)
	{
		if(n_day>=30)
		{
			n_mon=n_mon+1;
			n_day=date-tm.tm_mday;
		}
		printf("\n\n\tTime till your next birthday\t : %d years, %d month(s), %d day(s)",n_year,n_mon,n_day);
	}
	else
	{
		if(n_day>=30)
		{
			n_mon=n_mon+1;
			n_day=date-tm.tm_mday;
		}
		printf("\n\n\tTime till your next birthday\t : %d month(s), %d day(s)",n_mon,n_day);
	}
	printf("\n\n\tAddress\t\t\t\t : %s",app);
	getch();
	return 0;
}