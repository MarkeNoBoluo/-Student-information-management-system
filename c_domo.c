#include<stdio.h>
#include<string.h>
#define LEN 20
int input_score();
int average_score();
int max_score();
#define N 5

struct student					//定义结构体
{
	int id;
	char name[LEN+1];
	float average;
	float score[3];
}students[N];

int main()						//主函数
{
	
	input_score();
	average_score();
	max_score();
	return 0;
}


int input_score()				//input函数
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("请输入第%d学生的数据：\n",i+1);
		printf("\n学号:");
		scanf("%d", &students[i].id);
		printf("姓名:");
		scanf("%s", &students[i].name);
		printf("1成绩:");
		scanf("%f", &students[i].score[0]);
		printf("2成绩:");
		scanf("%f", &students[i].score[1]);
		printf("3成绩:");
		scanf("%f", &students[i].score[2]);
	}
	return 0;
}



int average_score()				//average函数
{
	int i,j;
	float sum = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum = sum + students[i].score[j];
		}
		students[i].average = sum / 3;

		sum = 0;
		printf("输出第%d位学生的平均分：", i + 1);
		printf("%f\n",students[i].average);
	}

}

		


int max_score()				//max函数
{
	float max;
	int flag = 0;
	int i;
	max = students[0].average;
	for (i = 0; i < N; i++)
	{
		if (max < students[i].average)
		{
			max = students[i].average;
			flag = i;
		}
	}
		
	printf("最高分的学生的数据：\n");
	printf("学号：%d\n", students[flag].id);
	printf("姓名：%s\n", students[flag].name);
	printf("1成绩：%f\n", students[flag].score[0]);
	printf("2成绩：%f\n", students[flag].score[1]);
	printf("3成绩：%f\n", students[flag].score[2]);
	
}
