#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bookData.h"
#include"bookList.h"
#include"switchCaseSelect.h"
void options();
int main()
{
	system("Color F0");
	char userN2[6]="ADMIN",passW2[8]="Sxc@123",userN1[6],passW1[8];
	system("CLS");
	printf("\n\n\n");
	printf("\t\t\tUSERNAME:  ");
	gets(userN1);
	printf("\t\t\tPASSWORD:  ");
	scanf("%[^\n]%*c",passW1);
	strupr(userN1);
	if(strcmp(userN1,userN2)==0 && strcmp(passW1,passW2)==0)
	{
		options();
	}
	else
	{
		printf("\n\n\n\tIncorrect Password or Username!");
		getch();
		do
		{
			system("CLS");
			printf("\n\n\n");
			printf("\t\t\tUSERNAME:\t");
			gets(userN1);
			printf("\t\t\tPASSWORD:\t");
			scanf("%[^\n]%*c",passW1);
			strupr(userN1);
			if(strcmp(userN1,userN2)==0 && strcmp(passW1,passW2)==0)
			{
				options();
			}
			else
			{
				printf("\n\n\n\tIncorrect Password or Username!");
				getch();
				main();
			}
		
		}while(strcmp(userN1,userN2)!=0 && strcmp(passW1,passW2)!=0);
		}
	return 0;

}


void options()
{
	char opt[2];
	char exit[2]="0";
	do
	{
		system("CLS");
		printf("\n\n\n");
		printf("\t\t\tWELCOME");
		printf("\n\n\t Hope you find what you're searching for!");
		printf("\n\t1. DISPLAY LIST OF BOOKS");
		printf("\n\t2. ADD TO THE LIST OF BOOKS");
		printf("\n\t3. SEARCH A BOOK");
		printf("\n\t4. UPDATE A DETAIL");
		printf("\n\t5. DELETE A BOOK");
		printf("\n\t0. EXIT\n\t");
		fflush(stdin);
		scanf("%[^\n]s",&opt);
		fflush(stdin);
		select(opt);
		
	}while(strcmp(opt,exit)!=0);
}


