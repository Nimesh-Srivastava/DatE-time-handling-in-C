#include<stdio.h>
#include<conio.h>

void main()
{
	int i,h[2],m[2],s[2],a_h=0,a_m=0,a_s=0,count=0;
	clrscr();
	for(i=0;i<2;i++)
	{
		printf("\n\nEnter time %d :-",i+1);
		printf("\n\nEnter hours   : ");
		scanf("%d",&h[i]);
		printf("\nEnter minutes : ");
		scanf("%d",&m[i]);
		if(m[i]>59)
		{
			printf("\n\nInvalid input. Press any key to exit");
			getch();
			exit(0);
		}
		printf("\nEnter seconds : ");
		scanf("%d",&s[i]);
		if(s[i]>59)
		{
			printf("\n\nInvalid input. Press any key to exit");
			getch();
			exit(0);
		}
	}
	a_s = s[0]+s[1];
	while(a_s>60)
	{
		a_s = a_s-60;
		count++;
	}
	a_m+=count;
	a_m+=m[0]+m[1];
	count=0;
	while(a_m>60)
	{
		a_m = a_m-60;
		count++;
	}
	a_h+=count;
	a_h+=h[0]+h[1];
	printf("\n\nAddition of given times :-");
	printf("\n\n\t%d : %d : %d",a_h,a_m,a_s);
	getch();
}