#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

FILE *hotel;
FILE *cus_now;
FILE *cus_bef;

struct price
{
	int floor; //楼层
	int price; //价格
	int state[5]; //用来录入每层每间的住房状态
	int num[5]; //表示房号
	char name[10]; //套房类型
};

struct customer
{
	int id; //身份证
	char name[30]; //姓名
	char sex; //性别
	int floor; //楼层号
	int num; //房间号
	int days; //居住天数
};

int main() //主函数 程序入口
{
	FILE *fp;
	fp = fopen("D:\\hotel.txt", "r");
	if (fp == NULL) fp = fopen("D:\\hotel.txt", "w");
	fclose(fp);
	fp = fopen("D:\\cus_now.txt", "r");
	if (fp == NULL) fp = fopen("D:\\cus_now.txt", "w");
	fclose(fp);
	fp = fopen("D:\\cus_bef.txt", "r");
	if (fp == NULL) fp = fopen("D:\\cus_bef.txt", "w");
	fclose(fp);
	fp = fopen("D:\\history.txt", "r");
	if (fp == NULL) fp = fopen("D:\\history.txt", "w");
	fclose(fp);



	int mainlist();
	mainlist(); //调用主菜单
}

int mainlist() //主菜单函数
{
	int flag = 0; //标记，作用不明
	char input; //接受收入值

	int ht_information();
	int checkin();
	int checkout();
	int getprice();
	int changeprice();
	int getcus();
	int history();


	while (!flag){
		system("cls"); //清屏
		printf("--------------------欢迎来到酒店信息管理系统V1--------------------\n");
		printf("--------------------请按对应字母进入相应功能界面--------------------\n\n");
		printf("\tA.现有酒店住房信息\n\n");
		printf("\tB.房价查询\n\n");
		printf("\tC.房间价格修改\n\n");
		printf("\tD.客人登记入住\n\n");
		printf("\tE.退房\n\n");
		printf("\tF.客户信息查询\n\n");
		printf("\tG.历史结算\n\n");
		printf("\tZ.退出系统\n");

		input = _getch();
		switch (input){   //VS2013中getch()需要写成_getch() 如用其它编译器请替换
		case 'a':
			ht_information();
			break;
		case 'b':
			getprice();
			break;
		case 'c':
			changeprice();
			break;
		case 'd':
			checkin();
			break;
		case 'e':
			checkout();
			break;
		case 'f':
			getcus();
			break;
		case 'g':
			history();
			break;
		case 'z':
			system("cls");
			printf("欢迎再次使用酒店信息管理系统！\n");
			exit(0);
		default:  //输入不正确 
			system("cls");
			printf("键入指令不正确！");
			Sleep(1000);
			break;
		}
	}
}

int ht_information()  //酒店信息显示
{
	system("cls");
	printf("======欢迎来到本酒店！======");
	printf("\n酒店概况：\n");
	printf("\n本酒店装修时间为2017年\n");
	printf("\n酒店共5层\n");
	printf("\n每层共10间\n");
	printf("\n1层单人间 日150元");
	printf("\n2层大床房 日250元");
	printf("\n3层亲子房 日300元");
	printf("\n4层商务大床房 日250元");
	printf("\n5层总统套房 日9999元");
	printf("\n\n======欢迎光临！======");
	printf("\n");
	system("pause");
	return 0;
}

int checkin() //登记入住
{

	return 0;
}

int checkout() //结账退房
{

	return 0;
}

int getprice() //房间价格查询
{
	system("cls");
	struct price temp;
	hotel = fopen("D:\\hotel.txt", "r");
	while (!feof(hotel)){
		fscanf(hotel,"%s %d %d-%d %d-%d %d-%d %d-%d %d-%d\n",&temp.name,&temp.price,&temp.num[0],&temp.state[0],&temp.num[1],&temp.state[1],&temp.num[2],&temp.state[2]
			,&temp.num[3],&temp.state[3],&temp.num[4],&temp.state[4]);
		temp.floor = temp.num[0] / 10;
		printf("%d楼 %s:\n\t日价:%d\n\n", temp.floor, temp.name, temp.price);
	}
	system("pause");
	return 0;
}

int changeprice() //房间价格更改
{

	return 0;
}

int getcus() //客户信息查询
{

	return 0;
}

int history() //历史结算
{

	return 0;
}
