#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int countWords(char* fileName){
	// N 尽量设置大一点，不考虑溢出情况 
	const int N = 9999;
	char str[N + 1] = {0}; 
	char line[N + 1] = {0};
	
	FILE *fp = fopen(fileName, "r");
	
	if (!fp){
		printf("文件打开失败！");
		exit(1);
	}
	
	while (!feof(fp))
	{
		// 取得每一行内容，然后拼接成整个文本 
		fgets(line, N, fp);
		strcat(str, line);
	}
	
	int len = strlen(str);
	int lastIndex = -1;	// 标记上次分词符号(','或' ')的位置 
	int count = 0;
	
	for (int i=0; i<len; i++){
		if (str[i] == ',' || str[i] == ' '){
			// 如果分词符号不是相邻的，则计一个单词数 
			if (i != lastIndex + 1){
				count++;
			}
			// 更新分词符号的位置 
			lastIndex = i; 
		}
	} 
	
	// 如果不是以空格或逗号结尾，则会少计一个单词 
	if (str[len-1] != ' ' && str[len-1] != ',')
	{
		count++;
	}

	fclose(fp);
	
	return count;
}


int countCharacters(char* fileName){
	char ch;
	int count = 0;
	
	FILE *fp = fopen(fileName, "r");
	
	if (!fp){
		printf("文件打开失败！");
		exit(1);
	}
	
	while((ch=fgetc(fp)) != EOF)
	{
		count++;
	}
	
	fclose(fp);
	
	return count; 
}

int main(int argc, char** argv)
{
	int count; 
	
	if (argc != 3){
		printf("输入不合法");
		return 0;
	}
	
	if (!strcmp("-c", argv[1]))
	{
		count = countCharacters(argv[2]); 
		printf("字符数：%d", count);
		
		return 0;
	}
	
	if (!strcmp("-w", argv[1]))
	{
		count = countWords(argv[2]);
		printf("单词数：%d", count);
		
		return 0;
	}
}
