struct database{
	char bookName[20];
	int bookCode;
	char genre[20];
	char authorName[20];
	char bookRow;
	int bookCol;
	char bookTakerName[20];
	char bookTakerContact[12];
	char avaiCheck;
	char yes;
	char no;
	struct takerTime{
		char month[20];
		int day;
	}tt;
};

//ADD DATA
int data()
{
	int n;
	system("CLS");
	printf("\n\n\n");
	printf("\n\tHow many books are to be listed?");
	scanf("%d",&n);
	struct database d[n];
	int i;
	
	FILE *fp;
	fp=fopen("bookDatabase.txt","a");

	for(i=0;i<n;i++)
	{
		d[i].yes='Y';
		d[i].no='N';
		system("CLS");
		printf("\n\n\n");
		printf("\n\t\tNO. %d",i+1);
			fflush(stdin);
		printf("\n\tBook Name:");
		scanf("%[^\n]s",d[i].bookName);
			fflush(stdin);
		printf("\n\tBook Code:");
		scanf("%d%*c",&d[i].bookCode);
			fflush(stdin);
		printf("\n\tBook Genre:");
		scanf("%[^\n]s",d[i].genre);
			fflush(stdin);
		printf("\n\tAuthor Name:");
		scanf("%[^\n]s",d[i].authorName);
			fflush(stdin);
					printf("\n\tIs the book Available in the library?(Y/N)");
					scanf("%c",&d[i].avaiCheck);
					fflush(stdin);
					if(d[i].avaiCheck==d[i].yes)
					{
						fflush(stdin);
						printf("\n\t Book Row:");
						scanf("%c",&d[i].bookRow);
						fflush(stdin);
						printf("\n\tBook Column:");
						scanf("%d",&d[i].bookCol);
						fflush(stdin);
					}
					else if(d[i].avaiCheck==d[i].no)
					{
						printf("\n\tBook Taker Details:");
						printf("\n\tName:");
							fflush(stdin);
						scanf("%[^\n]",d[i].bookTakerName);
							fflush(stdin);
						printf("\n\tContact:");
						scanf("%[^\n]",d[i].bookTakerContact);
							fflush(stdin);
						printf("\n\tDate Book was Taken:");
						printf("\n\tMonth:");
						scanf("%s",d[i].tt.month);
						fflush(stdin);
						printf("\n\tDay:");
						scanf("%d",&d[i].tt.day);
							fflush(stdin);
					}					
			fwrite(&d[i],sizeof(struct database),1,fp);
	}
	fclose(fp);
	
}

//SEARCH DATA
int search()
{
	
	system("CLS");
	struct database d2;
	
	d2.yes='Y';
	d2.no='N';
	int check;
	printf("\n\n\n");
	printf("\n\tEnter a book code for searching:");
	scanf("%d",&check);
	FILE *fp;
	int found=0;
	int i=0;
	fp=fopen("bookdatabase.txt","r");
	while(fread(&d2,sizeof(struct database),1,fp))
	{
		if(check==d2.bookCode)
		{
			i++;
			found=1;
			char n[5]="NAME",c[5]="CODE",g[6]="GENRE",a[7]="AUTHOR";
			printf("\n\t\tS.N | %-20s | %-10s | %-10s | %-20s |",n,c,g,a);
			int pattern;
			printf("\n\t\t");
			for(pattern=0;pattern<39;pattern++)
			{
				printf("==");
			}
			printf("\n\t\t%-3d | %-20s | %-10d | %-10s | %-20s |",i,d2.bookName,d2.bookCode,d2.genre,d2.authorName);
			if(d2.avaiCheck==d2.yes)
			{
				printf("\n\n\n\t\tCan be found in %c row and %dth column of the library",d2.bookRow,d2.bookCol);
				
			}
			else
			{
				printf("\n\n\n\t\tSorry! Unfortunately, the book is not available at the moment.");
				
				printf("\n\t\tTaker Name:%s \n\t\tTaker Contact:%s",d2.bookTakerName,d2.bookTakerContact);
				printf("\n\t\tDate Taken: %s %d",d2.tt.month,d2.tt.day);
			}
			getch();
		}
		
	}
	if(!found)
	{
		printf("\n\tBOOK NOT FOUND");
		getch();
	}
	fclose(fp);
}

//UPDATE DATA
int update()
{
	
	
	system("CLS");
	int check;
	int found=0;
	printf("\n\n\n");
	printf("\n\tEnter a book code to update details for that book:");
	scanf("%d",&check);
	FILE *fp,*f;
	fp=fopen("bookDatabase.txt","r");
	f=fopen("updateData.txt","w");
	struct database d;
	d.yes='Y';
	d.no='N';
	while(fread(&d,sizeof(struct database),1,fp))
	{
		if(check==d.bookCode)
		{
			found=1;
			fflush(stdin);
		printf("\n\tBook New Name:");
		scanf("%[^\n]s",d.bookName);
			fflush(stdin);
		printf("\n\tBook New Code:");
		scanf("%d%*c",&d.bookCode);
			fflush(stdin);
		printf("\n\tBook New Genre:");
		scanf("%[^\n]s",d.genre);
			fflush(stdin);
		printf("\n\tAuthor New Name:");
		scanf("%[^\n]s",d.authorName);
			fflush(stdin);
					printf("\n\tIs the book Available in the library?(Y/N)");
					scanf("%c",&d.avaiCheck);
					fflush(stdin);
					if(d.avaiCheck==d.yes)
					{
						fflush(stdin);
						printf("\n\t Book Row:");
						scanf("%c",&d.bookRow);
						fflush(stdin);
						printf("\n\tBook Column:");
						scanf("%d",&d.bookCol);
						fflush(stdin);
					}
					else if(d.avaiCheck==d.no)
					{
						printf("\n\tBook Taker Details:");
						printf("\n\tName:");
						fflush(stdin);
						scanf("%[^\n]",d.bookTakerName);
						fflush(stdin);
						printf("\n\tContact:");
						scanf("%[^\n]",d.bookTakerContact);
						fflush(stdin);
						printf("\n\tDate Book was Taken:");
						printf("\n\tMonth:");
						scanf("%s",d.tt.month);
						fflush(stdin);
						printf("\n\tDay:");
						scanf("%d",&d.tt.day);
						fflush(stdin);
					}				
		}
		fwrite(&d,sizeof(struct database),1,f);
	}
	fclose(fp);
	fclose(f);
	if(found)
	{
		fp=fopen("bookDatabase.txt","w");
		f=fopen("updateData.txt","r");
		while(fread(&d,sizeof(struct database),1,f))
		{
			fwrite(&d,sizeof(struct database),1,fp);
		}
		fclose(fp);
		fclose(f);
	}
	else
	{
		printf("\n\tBOOK NOT FOUND!");
		getch();
	}
}

//DELETE DATA
int del()
{
	system("CLS");
	int check;
	int found=0;
	printf("\n\n\n");
	printf("\n\tEnter a book code to delete that book records: ");
	scanf("%d",&check);
	FILE *fp,*f;
	fp=fopen("bookDatabase.txt","r");
	f=fopen("updateData.txt","w");
	struct database d;
	while(fread(&d,sizeof(struct database),1,fp))
	{
		if(check==d.bookCode)
		{
			found=1;
			
		}
		else
		fwrite(&d,sizeof(struct database),1,f);
		
	}
	fclose(fp);
	fclose(f);
	if(found)
	{
		fp=fopen("bookDatabase.txt","w");
		f=fopen("updateData.txt","r");
		while(fread(&d,sizeof(struct database),1,f))
		{
			fwrite(&d,sizeof(struct database),1,fp);
		}
		fclose(fp);
		fclose(f);
		printf("\n\n\tRECORD DELETED!");
		getch();
	}
	else
	{
		printf("\n\tBOOK NOT FOUND!");
		getch();
	}
}


