#define _CRT_SECURE_NO_WARNINGS 1
//打印菜单
#include"test.h"
void menu()
{
	printf("**************************\n");
	printf("*****1:add      2:del ****\n");
	printf("*****3:modtify  4:show ***\n");
	printf("*****5:sort     6:find ***\n");
	printf("********* 0:exit *********\n");
	printf("**************************\n");
}
int main()
{
	int input = 0;
	contact con;
	init_con(&con);
	do
	{
		menu();
		scanf("%d", &input);
		void (*Ctact[7])(contact * con) = {exit_num,add_num,del_num,modi_num,show_num,sort_num,find_num };
		if (input >0 && input <= 6)
		{
			Ctact[input](&con);
		}
		else if(input==0)
		{
			Ctact[input](&con);
			break;
		}
		else
		{
			printf("输入错误信息，将退出\n");
			break;
		}
		
	} while (1);

	return 0;
}