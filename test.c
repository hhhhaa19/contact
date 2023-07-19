#define _CRT_SECURE_NO_WARNINGS 1
//打印菜单
#include"test.h"
void menu()
{
	printf("**************************\n");
	printf("*****1:add      2:del ****\n");
	printf("*****3:modtify  4:show ***\n");
	printf("*****5:sort     6:find ***\n");
	printf("******* defaut:exit ******\n");
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
		if (input >= 0 && input <= 6)
		{
			void (*Ctact[7])(contact * con) = { NULL,add_num,del_num,modi_num,show_num,sort_num,find_num };
			Ctact[input](&con);
		}
		else
		{
			printf("输入错误信息，将退出\n");
			break;
		}
		
	} while (1);

	return 0;
}