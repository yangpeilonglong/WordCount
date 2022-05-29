#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 300
#define IN 1 
#define OUT 0 
int main(void)
{
	int i,sum=0;
	char a[MAX_LINE]={'\0'};
	char file[30]={" "};
	char sym[2]={" "};
	scanf("%s %s",&sym,&file);
	FILE *fp = fopen(file,"r");
	if(fp == NULL)
	{
		printf("文件读取无效.\n");
		return -1;
	}
	for(i = 0; !feof(fp); i++){
		fscanf(fp, "%c", &a[i]);
		sum++;
	}
	fclose(fp);
	/*for(i=0; i < sum; i++)
	printf("%c", a[i]);
	printf("\n");*/
	
	if(strcmp(sym,"-c")==0){
	printf("字符数：%d\n", sum-1);
	return 0;
	}
	else if(strcmp(sym,"-w")==0){
	char c;
    int nw, state;
    state = OUT;
    nw = 0;
    for(i=0;i<sum;i++) {
    	c = a[i];
        if(c == ' ' || c == '\n' || c == '\t') state = OUT;
        else if(state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("单词数：%d", nw);
    return 0;
	}
}
