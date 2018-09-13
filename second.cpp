#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
FILE *fp;  //全局的文件指针  指向我所要统计的文件 

int statisticline(char a2[80])	//统计行数 
{
	char temp;
	int lines = 0;
	fp = fopen(a2,"r");
	temp = fgetc(fp);
	while(temp != EOF)
	{
		
		if(temp == '\n')									//遇到换行符行数+1 
			lines++;
		temp = fgetc(fp);
		
    }
    lines++; 
	printf("LINES are %d in total",lines);
	fclose(fp);
	return 1;	
}


int statisticword(char a2[80])											//统计单词数 
{
	char temp;
	int words = 0;
	fp = fopen(a2,"r");
	temp = fgetc(fp);
	while (temp != EOF)
    {
        if ((temp >= 'a'&&temp <= 'z') || (temp >= 'A'&&temp <= 'Z') || (temp >= '0'&&temp <= '9'))
        {
            while ((temp >= 'a'&&temp <= 'z') || (temp >= 'A'&&temp <= 'Z') || (temp >= '0'&&temp <= '9') || temp == '_')
            {
                temp = fgetc(fp);	
            }
            words++;
            temp = fgetc(fp);
        }
        else
            temp = fgetc(fp);
	}
	printf("WORDS are %d in total",words);
	fclose(fp);
	return 1;
}

int statisticch(char a2[80])    									//统计字符数 
{
	char temp;
	int chara = 0;
	fp = fopen(a2,"r");
	temp = fgetc(fp);
	while(temp != EOF)
	{
		
		chara++;
		temp = fgetc(fp);
			
	}
	printf("CHARACTERS are %d in total",chara);
	fclose(fp);
	return 1;
}	

int Muiltiple(char a2[80])  								//综合统计函数，包括代码行，空行，注释行
{
    char temp;
    char *a3 = a2;
    int k = strlen(a2);
    fp = fopen(a2, "r");
    *(a3 + k - 1) = '\0';
    int c = 0, e = 0, n = 0;
    if ( fp== NULL)											//判空，读入文件失败 
    {
	    printf("file read failure.");
        exit(0);
    }														//fgetc()会返回读取到的字符，若返回EOF则表示到了文件尾，或出现了错误。
    temp = fgetc(fp);
    while (temp != EOF)
    {
    	if(temp == '\''||temp == '\"')						//过滤掉单引号和双引号之间的内容 ，以免对判断造成干扰 
    	{
    		temp = fgetc(fp);
    		while(temp != '\''||temp != '\"')
    		{
    			temp = fgetc(fp);
			} 
		}
		
        if (temp == '{' || temp == '}')							//空行判断 
        {
            temp = fgetc(fp);
            if(temp == '\n')
            {
            	e++;
            	temp = fgetc(fp);
			}	
        
        }
        
        else if (temp == '\n')
        {
            temp = fgetc(fp);
            while (temp == '\n')
            {
                e++;
                temp = fgetc(fp);
            }
        }
         
         else if (temp == '/')										//注释行判断有行注释和块注释 
        {
            temp = fgetc(fp);
            if (temp == '/')
            {
            	while (temp != '\n')
            	{
                	temp = fgetc(fp);
            	}
            	n++;
            	temp = fgetc(fp);
			}
			
			if(temp == '*')
			{
				temp = fgetc(fp);
				while(temp != '*')
				{
					temp = fgetc(fp);
					if(temp = '\n')
						n++;
				}
				n++;	
			}
            
        }
         else														//代码行判断 
         {
             c++;
             while (temp != '{'&&temp != '}'&&temp != '\n'&&temp != '/'&&temp != EOF)
             {
                 temp = fgetc(fp);
             }
        }
 
     }
     printf("code line count is ：%d.\n", c);
     printf("empt line count is ：%d.\n", e);
     printf("note line count is ：%d.\n", n);
     fclose(fp);
     return 1;
 }

int main(int argc,char *argv[])			//main函数接受外部参数  
{
	char a1[80],a2[80];
	int i;
	FILE *p;
	if(argc == 3)
	{
		p = fopen(argv[2],"r");
		if(p == NULL)
		{
			printf("Reading ERROR\n");
			printf("请按enter继续");
			_getch();
			exit(0);
		}
		strcpy(a2,argv[2]);
		strcpy(a1,argv[1]);
		for(i = 0;a1[i]!='\0';i++)
		{		 
			if(a1[i] == 'l')
				statisticline(a2);
			else if(a1[i] == 'a')
				Muiltiple(a2);
		    else if(a1[i] == 'c')
				statisticch(a2);
		    else if(a1[i] == 'w')
				statisticword(a2);
			else
				continue;    
		}           
	}	
	else
		printf("Warning:Please input three parameters");
	return 0; 
}


	
	
	
	

