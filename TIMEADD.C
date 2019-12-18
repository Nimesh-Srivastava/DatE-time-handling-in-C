#include<stdio.h>
#include<conio.h>

struct time
{
	int h,m,s,a_h,a_m,a_s;
};

int main()
{
	int i,count=0;
	struct time t[2],a;
	for(i=0;i<2;i++)
	{
		t[i].h=0;
		t[i].m=0;
		t[i].s=0;
		t[i].a_h=0;
		t[i].a_m=0;
		t[i].a_s=0;
	}
	a.h=0;
	a.m=0;
	a.s=0;
	a.a_h=0;
	a.a_m=0;
	a.a_s=0;
	clrscr();
	for(i=0;i<2;i++)
	{
		printf("\n\nEnter time %d :-",i+1);
		printf("\n\nEnter hours   : ");
		scanf("%d",&t[i].h);
		printf("\nEnter minutes : ");
		scanf("%d",&t[i].m);
		if(t[i].m>59)
		{
			printf("\n\nInvalid input. Press any key to exit");
			getch();
			exit(0);
		}
		printf("\nEnter seconds : ");
		scanf("%d",&t[i].s);
		if(t[i].s>59)
		{
			printf("\n\nInvalid input. Press any key to exit");
			getch();
			exit(0);
		}
	}
	a.a_s = t[0].s+t[1].s;
	while(a.a_s>=60)
	{
		a.a_s = a.a_s-60;
		count++;
	}
	a.a_m+=count;
	a.a_m+=t[0].m+t[1].m;
	count=0;
	while(a.a_m>=60)
	{
		a.a_m = a.a_m-60;
		count++;
	}
	a.a_h+=count;
	a.a_h+=t[0].h+t[1].h;
	printf("\n\nAddition of given times :-");
	printf("\n\n\t%d : %d : %d",a.a_h,a.a_m,a.a_s);
	getch();
	return 0;
}
