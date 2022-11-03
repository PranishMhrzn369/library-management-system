int list()
{
	system("CLS");
	printf("\n\n\n");
	int i;
	int j;
	char n[5]="NAME",c[5]="CODE",g[6]="GENRE",a[7]="AUTHOR";
	printf("\n\tS.N | %-20s | %-10s | %-10s | %-20s |",n,c,g,a);
	
	FILE *fp;
	int pattern;
	printf("\n\t");
	for(pattern=0;pattern<39;pattern++)
	{
		printf("==");
	}
	
	fp=fopen("bookDatabase.txt","r");
	fseek(fp,0,SEEK_END);
	int max=ftell(fp)/sizeof(struct database);
	struct database d[max],d1;
	rewind(fp);
	
	for(i=0;i<max;i++)
		fread(&d[i],sizeof(struct database),1,fp);
	for(i=0;i<max;i++)
	{
		for(j=i+1;j<max;j++)
		{
			if(d[i].bookCode>d[j].bookCode)
			{
				d1=d[i];
				d[i]=d[j];
				d[j]=d1;
			}
		}
	}
	for(i=0;i<max;i++)
	{
		printf("\n\t%-3d | %-20s | %-10d | %-10s | %-20s |",i+1,d[i].bookName,d[i].bookCode,d[i].genre,d[i].autherName);
	}
	
	
	
	fclose(fp);
	getch();
}
