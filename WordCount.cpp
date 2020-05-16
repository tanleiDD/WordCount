#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int countWords(char* fileName){
	// N �������ô�һ�㣬������������ 
	const int N = 9999;
	char str[N + 1] = {0}; 
	char line[N + 1] = {0};
	
	FILE *fp = fopen(fileName, "r");
	
	if (!fp){
		printf("�ļ���ʧ�ܣ�");
		exit(1);
	}
	
	while (!feof(fp))
	{
		// ȡ��ÿһ�����ݣ�Ȼ��ƴ�ӳ������ı� 
		fgets(line, N, fp);
		strcat(str, line);
	}
	
	int len = strlen(str);
	int lastIndex = -1;	// ����ϴηִʷ���(','��' ')��λ�� 
	int count = 0;
	
	for (int i=0; i<len; i++){
		if (str[i] == ',' || str[i] == ' '){
			// ����ִʷ��Ų������ڵģ����һ�������� 
			if (i != lastIndex + 1){
				count++;
			}
			// ���·ִʷ��ŵ�λ�� 
			lastIndex = i; 
		}
	} 
	
	// ��������Կո�򶺺Ž�β������ټ�һ������ 
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
		printf("�ļ���ʧ�ܣ�");
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
		printf("���벻�Ϸ�");
		return 0;
	}
	
	if (!strcmp("-c", argv[1]))
	{
		count = countCharacters(argv[2]); 
		printf("�ַ�����%d", count);
		
		return 0;
	}
	
	if (!strcmp("-w", argv[1]))
	{
		count = countWords(argv[2]);
		printf("��������%d", count);
		
		return 0;
	}
}
