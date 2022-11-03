int select(char op[2])
{
	char option1[2]="1";
	char option2[2]="2";
	char option3[2]="3";
	char option4[2]="4";
	char option5[2]="5";
	char option6[2]="0";
	if(strcmp(op,option1)==0)
	{
		list();
	}
	else if(strcmp(op,option2)==0)
	{
		data();
	}
	else if(strcmp(op,option3)==0)
	{
		search();
	}
	else if(strcmp(op,option4)==0)
	{
		update();
	}
	else if(strcmp(op,option5)==0)
	{
		del();
	}
	else if(strcmp(op,option6)==0)
	{
		exit(0);
	}
	else
	{
		printf("Wrong Input!(1-5)");
		getch();
	}
}
