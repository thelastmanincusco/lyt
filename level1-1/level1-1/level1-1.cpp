// level1-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdio.h>

int main()
{
	int person_floor, person_aim_floor, elevator_floor, time, number_of_people;
	time = number_of_people = 0;
	while (1) {
		printf_s("请输入用户所在楼层，用户去往楼层，电梯所在楼层（输入任意非数字以结束）\n");
		if ((scanf_s("%d%d%d", &person_floor, &person_aim_floor, &elevator_floor)) != 3)
		{
			printf_s("再见\n");
			break;
		}

		else if (person_floor > 10 || person_aim_floor > 10 || elevator_floor > 10)
		{
			printf_s("请输入1到10之间的数字\n");
			continue;
		}
		else if (person_floor == person_aim_floor)
		{
			printf_s("用户去往楼层与所在楼层相同！\n");
			continue;
		}
		else
			if (person_floor == elevator_floor)
			{
				number_of_people = 1;
				printf_s("1%5d%5d%5d\n", elevator_floor, time, number_of_people);
				time = (person_aim_floor > person_floor) ? (person_aim_floor - person_floor) : -(person_aim_floor - person_floor);
				number_of_people = 0;
				printf_s("2%5d%5d%5d", elevator_floor, time, number_of_people);
				continue;
			}


		if (person_floor > elevator_floor) {
			printf_s("1%5d%5d%5d\n", elevator_floor, time, number_of_people);
			time = (person_floor - elevator_floor);
			elevator_floor = person_floor;
			number_of_people = 1;
			printf_s("2%5d%5d%5d\n", elevator_floor, time, number_of_people);
			time += (person_aim_floor > elevator_floor) ? (person_aim_floor - elevator_floor) : -(person_aim_floor - elevator_floor);
			elevator_floor = person_aim_floor;
			number_of_people = 0;
			printf_s("3%5d%5d%5d\n", elevator_floor, time, number_of_people);
			continue;

		}
		else {
			printf_s("1%5d%5d%5d\n", elevator_floor, time, number_of_people);
			time = (elevator_floor - person_floor);
			elevator_floor = person_floor;
			number_of_people = 1;
			printf_s("2%5d%5d%5d\n", elevator_floor, time, number_of_people);
			time += (person_aim_floor > elevator_floor) ? (person_aim_floor - elevator_floor) : -(person_aim_floor - elevator_floor);
			elevator_floor = person_aim_floor;
			number_of_people = 0;
			printf_s("3%5d%5d%5d\n", elevator_floor, time, number_of_people);
			continue;
		}
	}

	return 0;

}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
