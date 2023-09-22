// level1-2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdio.h>

int main()
{
	int person_floor, person_aim_floor, elevator_floor, time, number_of_people;
	time = number_of_people = 0;
	char useless[9];
	FILE* file = fopen("level1-2.txt", "r");
	if (file == NULL) {
		printf("无法打开文件\n");
		return 1;
	}
	if (fscanf(file, "%s %d %d %d",&useless ,& elevator_floor, &person_floor, &person_aim_floor) != 4) {
		printf("无法读取三个数字\n");
		fclose(file);
		return 1;
	}
	fclose(file);

			if (person_floor == elevator_floor)
			{
				number_of_people = 1;
				printf_s("1%5d%5d%5d\n", elevator_floor, time, number_of_people);
				time = (person_aim_floor > person_floor) ? (person_aim_floor - person_floor) : -(person_aim_floor - person_floor);
				number_of_people = 0;
				printf_s("2%5d%5d%5d", elevator_floor, time, number_of_people);
		
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
