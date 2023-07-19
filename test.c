#define _CRT_SECURE_NO_WARNINGS 1
//¥Ú”°≤Àµ•
#include"test.h"
void menu()
{
	printf("**************************\n");
	printf("*****1:add      2:del ****\n");
	printf("*****3:modtify  4:show ***\n");
	printf("*****5:sort     6:find ***\n");
	printf("*****0:exit***************\n");
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
		if (input != 0)
		{
			void (*Ctact[7])(contact * con) = { NULL,add_num,del_num,modi_num,show_num,sort_num,find_num };
			Ctact[input](&con);
		}
		else
			break;
		
	} while (1);

	return 0;
}