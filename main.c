#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<Windows.h>

struct houses
{
	int id;
	char name[10];
	double daily_price;
	double hour_price;
	double free_nums;
};

struct customer
{
	int id;
	char name[10];
	int id_card;
	int house_id;
	int house_timetype;
	int house_time;
	char house_name[10];
	double should_pay;
	double payed;
};


int main()
{
	int funa();
	int funb();
	int func();
	int fund();
	char inputa;
	int flag;
	FILE *fp;
	
	fp = fopen("D:\\housetypes.txt", "r");
	if (fp == NULL) fp = fopen("D:\\housetypes.txt", "w");
	fclose(fp);

	fp = fopen("D:\\customers.txt", "r");
	if (fp == NULL) fp = fopen("D:\\customers.txt", "w");
	fclose(fp);

	flag = 0;
	while (!flag){
		system("cls");
		printf("---------------------欢迎访问酒店信息管理系统---------------------");
		printf("\n请键入您想要的执行的操作：\n");
		printf("\tA.查询房型及房型价格\n");
		printf("\tB.房型信息修改\n");
		printf("\tC.客户登记入住\n");
		printf("\tD.月底结算\n");
		printf("\tE.退出管理系统\n");
		inputa = _getch();
		switch (inputa)
		{
		case 'a':
			flag = funa();
			break;
		case 'b':
			flag = funb();
			break;
		case 'c':
			flag = func();
			break;
		case 'd':
			flag = fund();
			break;
		case 'e':
			exit(0);
			break;
		default:
			printf("键入不正确！");
			Sleep(500);
			flag = 0;
			system("cls");
			break;
		}
	}
}
int exist_house_num()
{
	FILE *fp;
	char a[100];
	int flag = 0, count = 0;
	fp = fopen("D:\\housetypes.txt", "r");
	while (!flag){
		if (fgets(a, 99, fp) != NULL)
			count++;
		else
			flag = 1;
	}
	fclose(fp);
	return count;
}
int funa()
{
	FILE *fp;
	char temp = 100;
	system("cls");
	printf("---------------------房间信息查询---------------------");
	printf("\n以下是现有房型：\n");
	printf("序号 房型 日价 时价 余量\n");
	fp = fopen("D:\\housetypes.txt", "r");
	while (temp != EOF){
		temp = fgetc(fp);
		printf("%c", temp);
	}
	fclose(fp);
	printf("\n");
	printf("按任意键返回主界面……");
	_getch();
	return 0;
}

int funb()
{
	FILE *fp, *curfp, *tempfp;
	char oldname[15] = { "D:\\tp.txt" }, newname[25] = { "D:\\housetypes.txt" };
	struct houses new_house, temp_house;
	int tempnum = 100;
	char tempchar = 100;
	int flag = 0;
	int inputa, count = 0;
	while (!flag){
		system("cls");
		printf("---------------------房间信息修改---------------------");
		printf("\n请键入您想要执行的操作：\n");
		printf("\tA.添加房型\n");
		printf("\tB.删除房型\n");
		printf("\tD.返回上级菜单\n");
		printf("\tE.退出程序\n");
		inputa = _getch();
		switch (inputa)
		{
		case 'a':
			fp = fopen("D:\\housetypes.txt", "a");
			printf("\n请输入新房名：");
			scanf("%s", &new_house.name);
			printf("\n请输入新房的日价格：");
			scanf("%lf", &new_house.daily_price);
			printf("\n请输入新房的时价格：");
			scanf("%lf", &new_house.hour_price);
			printf("\n请输入新房余量：");
			scanf("%d", &new_house.free_nums);
			new_house.id = exist_house_num() + 1;
			fprintf(fp, "%d %s %.1f %.1f %d\n", new_house.id, new_house.name, new_house.daily_price, new_house.hour_price, new_house.free_nums);
			printf("增加房型成功！");
			Sleep(1000);
			fclose(fp);
			break;
		case 'b':
			count = 0;
			printf("\n请输入要删除的房间的序号:");
			scanf("%d", &inputa);
			fp = fopen("D:\\housetypes.txt", "r");
			tempfp = fopen("D:\\tp.txt", "w");
			tempnum = fscanf(fp, "%d %s %lf %lf %d\n", &temp_house.id, &temp_house.name, &temp_house.daily_price, &temp_house.hour_price, &temp_house.free_nums);
			while (tempnum != EOF){
				if (temp_house.id == inputa){
					flag = 2;
					tempnum = fscanf(fp, "%d %s %lf %lf %d\n", &temp_house.id, &temp_house.name, &temp_house.daily_price, &temp_house.hour_price, &temp_house.free_nums);
				}
				else{
					count++;
					temp_house.id = count;
					fprintf(tempfp, "%d %s %.1f %.1f %d\n", temp_house.id, temp_house.name, temp_house.daily_price, temp_house.hour_price, temp_house.free_nums);
					tempnum = fscanf(fp, "%d %s %lf %lf %d\n", &temp_house.id, &temp_house.name, &temp_house.daily_price, &temp_house.hour_price, &temp_house.free_nums);
				}
			}
			fflush(tempfp);
			fclose(tempfp);
			fclose(fp);
			remove(newname);
			rename(oldname, newname);
			if (flag != 2){
				printf("\n未找到相应房型！");
			}
			else {
				printf("删除成功！");
			}
			Sleep(1000);
			break;
		case 'd':
			return 0;
			break;
		case 'e':
			exit(0);
			break;
		default:
			printf("输入错误！");
			Sleep(1000);
			system("cls");
			break;
		}
	}
}

int func()
{
	char inputa,getca;
	struct customer new_cus;
	struct houses temp_house;
	FILE *cfp, *housefp;
	int flag = 0;
	while (!flag)
	{
		system("cls");
		printf("---------------------客户登记系统---------------------");
		printf("\n请键入您想要执行的操作：\n");
		printf("\tA查询客人信息\n");
		printf("\tB.入住\n");
		printf("\tC.退房\n");
		printf("\tD.返回上级菜单\n");
		printf("\tE.退出系统\n");

		switch (inputa = _getch())
		{
		case 'a':  //查询现有顾客信息
			cfp = fopen("D:\\customers.txt", "r");

			printf("编号 身份证 姓名 时型 时长 应收 实收\n");
			while (!feof(cfp)){
				getca = fgetc(cfp);
				printf("%c", getca);
			}
			fclose(cfp);
			printf("\n按任意键返回\n");
			_getch();
			break;
		case 'b':  //入住办理
			printf("\n身份证：");
			scanf("%d", &new_cus.id_card);
			prntf("\n姓名：");
			scanf("%s", new_cus.name);
			printf("\n房型id：");
			scanf("%d", &new_cus.house_id);
			printf("\n租住时型(1 按日 2 按时)：");
			scanf("%d", &new_cus.house_timetype);
			if (new_cus.house_timetype == 1){  //判断租住时型
				printf("\n租住日数：");
			}
			else if(new_cus.house_timetype==2) printf("\n租住小时数：");
			else{
				printf("\n输入不正确！自动改为按小时！");
				printf("\n租住小时数：");
				new_cus.house_timetype = 2;
			}
			scanf("%d", &new_cus.house_time);

			housefp = fopen("D:\\housetypes.txt", "r");
			while (!feof(housefp)){  //由顾客输入的房型结算顾客应收金额
				fscanf(housefp, "%d %s %lf %lf %d\n", &temp_house.id, &temp_house.name, &temp_house.daily_price, &temp_house.hour_price, &temp_house.free_nums);
				if (temp_house.id == new_cus.house_id){
					if (new_cus.house_timetype == 1){
						new_cus.should_pay = temp_house.daily_price*(double)new_cus.house_time;
						break;
					}
					else{
						new_cus.should_pay = temp_house.hour_price*(double)new_cus.house_time;
						break;
					}
				}
			}
			for (int i = 0; temp_house.name[i] != '\n'; i++){  //输入顾客的房型名称
				new_cus.house_name[i] = temp_house.name[i];
			}
			new_cus.house_name[i] = temp_house.name[i];
			fclose(housefp);

			printf("\n应收：%.1f", new_cus.should_pay);  //输出应收金额

			printf("\n输入已收金额：");
			scanf("%lf", &new_cus.payed);


		case 'd':
			return 0;
		case 'e':
			exit(0);
		default:
			printf("输入错误！");
			Sleep(1000);
			break;
		}
	}
	
}

int fund()
{
	return 0;
}
