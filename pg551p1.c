#include <stdio.h>
#include <stdlib.h>

char * ReadRow(void)
{
	char * row = (char *)malloc(sizeof(char)*30);
	fgets(row, 30, stdin);
	
	return row;
}

char * change(char* row)
{
	int k = 0;
	int stack = 0;
	int i = 30;
	int j;
	char * temp = (char *)malloc(sizeof(char)*i);

	// 배열 끝 부분 빈칸 체크
	while(1){
		if(row[i - 1] != ' '){
			printf("%d번째 드디어 빈칸이 아닙니다! \n", i-1);
			break;
		}
		
		i--;	
	}

	// 끝 부분 부터 변경
	
        //for(j = i ; j >= 0 ; j--){
		
	j = i;

	while(1){
		stack = j;
		while(row[stack] != ' '){
			temp[k] = row[stack];
			k++;
			stack--;
		}

		temp[k] = ' ';
		k++;
		j = stack;
		j--;

		if(j < 0){
			break;
		}
	}	
	

/* 	I am a boy만 변경 가능하게 하는 코드
 *
	temp[10] = '\0';

	for(int i = 9; i >= 0 ; i--){
		
		if(row[i] == ' '){
			
			for(j = i+1; j < i + stack + 1 ; j++){
				
				if(row[j] == ' '){
					break;
				}

				temp[k] = row[j];
				printf("temp[k]: %c, k :%d, row[j]: %c, j :%d in for\n", temp[k], k, row[j], j);
				k++;		
			}

			temp[k] = ' ';
			k++;
			stack = 0;

			printf("%s \n", temp);
		}
		
		stack++;	
		printf("%c ", row[i]);	
		printf("%d \n", stack);
	}

	temp[k] = row[0];
	printf("temp[k]: %c, k :%d, row[j]: %c, j :%d in for\n", temp[k], k, row[j], j);
*/	
	return temp;
}

int main(void)
{
	char * row;
	row = ReadRow();
	printf("처음 : %s \n", row);
	
	row = change(row);
	printf("변경 후 : %s \n", row);

	return 0;
}
