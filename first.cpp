#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
FILE *fp;  //ȫ�ֵ��ļ�ָ��  ָ������Ҫͳ�Ƶ��ļ� 

int statisticword(char a2[80])		//ͳ�Ƶ����� 
{
	char temp;
	int words = 0;
	fp = fopen(a2,"r");
	while(!feof(fp))
	{
		temp = fgetc(fp) ;
		if(temp == ' '||temp == ';'||temp =='\n'||temp=='\t'||temp == '='||temp == ','||temp == '!'||temp=='.')
			words++;
	}
	printf("WORDS are %d in total",words);
	fclose(fp);
	return 1;
}

int statisticline(char a2[80])		//ͳ������ 
{
	char temp;
	int lines = 0;
	fp = fopen(a2,"r");
	while(!feof(fp))
	{
		temp = fgetc(fp);
		if(temp == '\n')
			lines++;
		
	}
	printf("LINES are %d in total",lines);
	fclose(fp);
	return 1;	
}

int statisticch(char a2[80])    //ͳ���ַ��� 
{
	char temp;
	int chara = 0;
	fp = fopen(a2,"r");
	while(!feof(fp))
	{
		temp = fgetc(fp);
		if (temp !=' '||temp !='\n'||temp !='\t')
			chara++;
			
	}
	chara--;
	printf("CHARACTERS are %d in total",chara);
	fclose(fp);
	return 1;
}	

int main(int argc,char *argv[])			//main���������ⲿ����  
{
	char a1[80],a2[80];
	FILE *p;
	if(argc == 3)
	{
		p = fopen(argv[2],"r");
		if(p == NULL)
		{
			printf("Reading ERROR\n");
			printf("�밴enter����");
			_getch();
			exit(0);
		}
		strcpy(a2,argv[2]);
		strlen(argv[1]);
		strcpy(a1,argv[1]);         
		if(!strcmp(argv[1],"-l"))
			statisticline(a2);
		else if(!strcmp(argv[1],"-c"))
			statisticch(a2);
		else if(!strcmp(argv[1],"-w"))
			statisticword(a2);
	}	
	else
		printf("Warning:Please input three parameters");
	return 0; 
}




	
	
	
	

