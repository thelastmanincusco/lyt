// level1-3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdbool.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMIT 4
static int count = 0;
int MAX(int arr[], int);
int MIN(int arr[], int);
int input_number(void);
int get_number(int arr[], int, int, int);
void print(int,int,int);
bool if_up(int arr[], int,int);
bool if_down(int arr[], int,int);
bool if_same(int arr[], int, int);
int main()
{
	bool upward;
	int number_of_people = 0;//呼叫电梯人数
	int people_in_elevator = 0;//电梯内人数
	int time = 0;//电梯运行时间
	int aim_floor_max, aim_floor_min;//电梯已知要到达的最高层与最低层
	int temp = 0;
	int people_arr[10] = { 0 };//人所在楼层
	int aim_arr[10] = {0};//人去往楼层
	int elevator_count_arr[10] = {0};//电梯已知要把人送到的楼层
	int elevator;//电梯所在楼层
	int n,i,m;
	int up, under;//电梯启动时在电梯所在层楼上与楼下人数
	aim_floor_max = aim_floor_min = up = under = m=0;
	for (i = 0; i < 10; i++)
	{
		printf_s("请输入第%d个人的所在楼层(最多10人)\n输入0以退出\n", i + 1);
		people_arr[i] = input_number();
		if (people_arr[i] == 0)
			break;
		printf_s("请输入第%d个人所去的楼层(最多10人)\n输入0以退出\n", i + 1);
		aim_arr[i] = input_number();
		if (aim_arr[i] == 0)
			break;
		number_of_people++;
	}
	printf_s("接下来输入电梯启动时所在层数\n");
	elevator = input_number();
	n = get_number(people_arr, elevator, m, number_of_people);
	printf_s("%d\n", n);
	time = abs(people_arr[n] - elevator);
	elevator = people_arr[n];
	elevator_count_arr[n] = aim_arr[n];
	print(elevator, time, people_in_elevator);
	if (elevator_count_arr[n] <elevator)
		upward = false;
	else
		upward = true;
	while (number_of_people != 0) {
		//电梯上行
		while (upward) {
			if (number_of_people == 0)
				break;
			for (i = 0; i < 10; i++) {
				//电梯下人
				if ((elevator_count_arr[i] == elevator and aim_floor_max != elevator) or
					(elevator_count_arr[i] == elevator and aim_floor_max == elevator
						and (if_up(people_arr, 10, elevator))))
				{
					people_in_elevator--;
					number_of_people--;
					if (number_of_people == 0)
						break;
					elevator_count_arr[i] = 0;
					if(!if_same(people_arr,10,elevator))
					   print(elevator, time, people_in_elevator);
				}
					//电梯进人
					if (people_arr[i] == elevator and people_in_elevator < LIMIT) {
						people_in_elevator++;
						people_arr[i] = 0;
						elevator_count_arr[i] = aim_arr[i];
						aim_floor_max = MAX(elevator_count_arr, 10);
						aim_floor_min = MIN(elevator_count_arr, 10);
						print(elevator, time, people_in_elevator);
					}
					//电梯到顶后
					if (elevator_count_arr[i] == elevator and aim_floor_max == elevator
						and  !(if_up(people_arr, 10, elevator))) {
						people_in_elevator--;
						number_of_people--;
						if (number_of_people == 0)
							break;
						elevator_count_arr[i] = 0;
						upward = false;
						print(elevator, time, people_in_elevator);
					}


				}
				elevator++;
				time++;
			}


			while (!upward) {
				if (number_of_people == 0)
					break;
				for (i = 0; i < 10; i++) {
					//电梯下人
					if ((elevator_count_arr[i] == elevator and aim_floor_min != elevator) or
						(elevator_count_arr[i] == elevator and aim_floor_min == elevator
							and (if_down(people_arr, 10, elevator))))
					{
						people_in_elevator--;
						number_of_people--;
						if (number_of_people == 0)
							break;
						elevator_count_arr[i] = 0;
						if (!if_same(people_arr, 10, elevator))
						print(elevator, time, people_in_elevator);
						//电梯进人
						if (people_arr[i] == elevator and people_in_elevator < LIMIT) {
							people_in_elevator++;
							people_arr[i] = 0;
							elevator_count_arr[i] = aim_arr[i];
							aim_floor_max = MAX(elevator_count_arr, 10);
							aim_floor_min = MIN(elevator_count_arr, 10);
							print(elevator, time, people_in_elevator);
						}
						//电梯到底后
						if (elevator_count_arr[i] == elevator and aim_floor_min == elevator
							and !(if_down(people_arr, 10, elevator))) {
							people_in_elevator--;
							number_of_people--;
							if (number_of_people == 0)
								break;
							elevator_count_arr[i] = 0;
							upward = false;
							print(elevator, time, people_in_elevator);
						}	
					}
					elevator--;
					time++;
				}
				return 0;
			}
		}
	}
	int input_number(void)
	{
		int input;
		char ch;
		while (scanf_s("%d", &input) != 1 or input > 10 or input < 0) {
			while ((ch = getchar()) != '\n')
				putchar(ch);
			printf_s("输入错误，请重试！\n");
		}
		return input;
	}
int MAX(int arr[], int n) {
	int max = arr[0]; // 假设第一个元素是最大值

	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i]; // 更新最大值
		}
	}
	return max;
}
int MIN(int arr[], int n) {
	int min=10; 
	for (int i = 1; i < n; i++) {
		if (arr[i] < min and arr[i]!=0) {
			min = arr[i]; // 更新最小值
		}
	}
	return min;
}
int get_number(int arr[],int n,int m,int k ){
	int minDifference = abs(n - arr[0]); // 初始化最小差值为第一个元素与目标数的差值
	for (int i=0; i < k; i++) {
		int currentDifference = abs(n - arr[i]); // 计算当前元素与目标数的差值
		if (currentDifference < minDifference) {
			// 如果当前差值更小，则更新最接近的数、最小差值和索引
			m = i;
			minDifference = currentDifference;
		}
	}
	return m;
}
void print(int x, int y, int z) {
	count++;
	printf_s("%d%5d%5d%5d\n", count, x, y, z);
}
bool if_up(int arr[], int n,int m) {
	bool up = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] > m) {
			up = true;
			break;
		}
	}
	return up;
}
bool if_down(int arr[], int n, int m) {
	bool down = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] < m and arr[i]!=0) {
			down = true;
			break;
		}
	}
	return down;
}
bool if_same(int arr[], int n, int m) {
	bool same = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] > m) {
			same = true;
			break;
		}
	}
	return same;
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
