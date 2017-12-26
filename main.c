#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

struct price
{
	int floor; //楼层
	double price; //价格
	char name[20]; //套房类型
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
	int mainlist();
	mainlist(); //调用主菜单
}

int mainlist() //主菜单函数
{
	int flag = 0; //标记，作用不明
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

		switch (_getch()){   //VS2013中getch()需要写成_getch() 如用其它编译器请替换
		case 'a':
			ht_information();
			break;
		case 'b':
			checkin();
			break;
		case 'c':
			checkout();
			break; 
		case 'd':
			getprice();
			break;
		case 'e':
			changeprice();
			break;
		case 'f':
			getcus();
			break; 
		case 'g':
			history();
			break;
		case 'z':
			system("cls");
			printf("欢迎再次使用酒店信息管理系统！");
			Sleep(1500);
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
