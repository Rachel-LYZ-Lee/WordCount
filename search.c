#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *Fpoint;

void Charnumber(char *Filename)
{
	int Charnumber=0;
	char ch;
	if((Fpoint =fopen(Filename,"rb"))==NULL)
	{
		printf("Can't open!\n");
		exit(0);
	}
	while (!feof(Fpoint))
	{
		ch=fgetc(Fpoint);
		if(ch!='\n' && ch!='\t' && ch!=' ' && ch!=',' && ch!='.')
			Charnumber++;
	}
	fclose(Fpoint);
	printf("×Ö·ûÊý£º%d\n",Charnumber);
}

void Wordnumber(char *Filename)
{
	int Wordnumber=0;
	char c;
	int flag =0;
	if((Fpoint =fopen(Filename,"rb"))==NULL)
	{
		printf("Can't open!\n");
		exit(0);
	}
	while (!feof(Fpoint))
	{
		c=fgetc(Fpoint);
		if((c>='A'&&c<='Z') || (c>='a'&&c<='z'))
			flag=1;
		else if(flag)
		{
			Wordnumber++;
			flag=0;
		}
	}
	fclose(Fpoint);
	printf("µ¥´ÊÊý£º%d\n",Wordnumber);
}

int main(int argc,char *argv[])
{
	if(!strcmp(argv[1],"-w"))
		Wordnumber(argv[2]);
	else if(!strcmp(argv[1],"-c"))
		Charnumber(argv[2]);
	return 0;
}
