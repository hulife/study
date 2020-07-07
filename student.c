#include "stdio.h"//学生信息管理系统
#include <string.h>
//定义结构体类型
struct student
{
	char name[10];
	float score;
	int id;
};

//定义一个结构体数组，存储学生信息
struct student stu[50];
//计数
int count = 0;


int menu(void);
int add(void);
void del(void);
void change(void);
void search(void);
void print_all_info(void);
void paixun_chengji(void);
int denglu(void);



int main()
{

	int flag=0;

	flag=denglu();
	if(flag==100)
	{	
		printf("登录成功\n");
	
	}
	if(flag==99)
	{	
		printf("登录失败\n");
	
	}
	//else
	//{
	//	printf("Error\n");
		
	//}



int n = 0;

	while(1)
	{
		n = menu();
		switch(n)
		{
		case 1:add();break;
		case 2:change();break;
		case 3:search();break;
		case 4:del();break;
		case 5:printf("欢迎下次使用\n");return 0;
		case 6:print_all_info();break;
		case 7:paixun_chengji();break;
		case 8:denglu();break;
		//case 8:denglu();break;
		}
	}
	return 0;
}


int denglu(void)
{
int m;
int i=1;
char x;
char a[50],b[50],c[]={"密码对了"},d[]={"密码错了"},e[]={"asdgfdas"},f[50],g[50];
printf("输入您的管理密码\n");
scanf("%s",f);
if(strcmp(f,e)==0)
{
	printf("%s",c);
	return 100; 
}
if(strcmp(f,e)!=0)
{
printf("密码错误，请重新注册\n");
}
printf("是否重新注册Y/N\n");
getchar();
scanf("%c",&x);
getchar();

if(x=='Y'||x=='y')
	{
	
	printf("请输入账户名\n");
	scanf("%s",g);
	getchar();
	
	printf("请输入新密码\n");
	
	scanf("%s",a);
	getchar();
	}else{
	return 99;
	}
printf("账户名%s\n",g);
printf("新密码%s\n",a);
printf("保存成功，请输入解锁密码(至多输入密码3次)\n");
scanf("%s",b);
getchar();
m=strcmp(a,b);
while(i<4)
{
	if(m=0)
	{
	break;
	}
		else
		{
		i++;
		}

printf("%s",i==3?c:b);

}
if(m==0)
{
	return 100;
//goto ggg;
}

}

//菜单
int menu(void)
{
	int num = 0;
	printf("**********************\n");
	printf("\t1,增加信息\n");//
	printf("\t2,修改信息\n");
	printf("\t3,查询信息\n");
	printf("\t4,删除信息\n");//
	printf("\t5,退出系统\n");//
	printf("\t6,输出所有信息\n");//
	printf("\t7,按照成绩升序排列\n");
	printf("\t8,用户登录\n");
	printf("**********************\n");
	printf("请输入要执行的操作(1--8)\n");
	scanf("%d",&num);
	return num;
}

int add(void)
{
	int id = 0;
	int i = 0;
	char ch;
input_add:
	if(count >=50)
	{
		printf("系统已满，请执行其他操作\n");
		return -1;
	}
input_id:
	printf("请输入要添加学生的学号\n");
	scanf("%d",&id);
	getchar();
	//判断学号为id的学生是否存在
	for(i = 0;i<count;i++)
	{
		if(stu[i].id == id)
		{
			printf("学号为%d的学生已经存在，请重新输入\n",id);
			goto input_id;
		}
	}

	stu[count].id = id;
	printf("请输入要添加学生的姓名\n");
	scanf("%s",stu[count].name);
	getchar();
	printf("请输入要添加学生的成绩\n");
	scanf("%f",&stu[count].score);
	getchar();
	count++  ;
	printf("添加完成\n");
	printf("系统现有%d名学生\n",count);
	printf("是否继续添加(Y/N)\n");
	ch = getchar();
	getchar();
	if(ch == 'Y' || ch == 'y')
		goto input_add;
	return 1;
}
void del(void)
{
	int id;
	int flag = 0;
	int i,j = 0;
	printf("function del is called\n");
	printf("请输入要删除学生的学号\n");
	scanf("%d",&id);
	getchar();
	//判断学号为id的学生是否存在
	for(i = 0;i<count;i++)
	{
		if(stu[i].id == id)
		{
			//可以删除
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		for(j = i;j<count;j++)
		{
			stu[j] = stu[j+1];
		}
		count--;
	}
	else
		printf("查无此人\n");
}
void change(void)
{
	int i=0;
	int id=0;
	int fl=0;
	printf("function change is called\n");
shu:
	printf("请输入原始学号");
	scanf("%d",&id);
	getchar();
	
		for(i = 0;i<count;i++)
	{
		if(stu[i].id == id)
		{
			fl = 1;
			break;
		}
	}
		
	if(fl==1)
	{
	printf("学号\t名字\t分数\n");
	printf("%d\t%s\t%f\n",stu[i].id,stu[i].name,stu[i].score);
	}
	else
	{
	printf("输入错误");
	goto shu;
	}
	
	int flag=0;
	int num;
	char gai[100];
	int g=0;
head:
	printf("按1修改名字\t,按2修改分数\n");
	scanf("%d",&flag);
	getchar();
	if(flag==1)
	{
	printf("输入新名字");
	scanf("%s",gai);	
	getchar();				
	strcpy(stu[i].name,gai);				
	printf("修改后\n");
	printf("学号\t名字\t分数\n");
	printf("%d\t%s\t%f\n",stu[i].id,stu[i].name,stu[i].score);
	goto head;
	}
	if(flag==2)
	{
	printf("输入新分数");
	scanf("%d",&num);
	getchar();
	stu[i].score=num;
	}
	printf("修改后");
	printf("学号\t名字\t分数\n");
	printf("%d\t%s\t%f\n",stu[i].id,stu[i].name,stu[i].score);
	}
	
	


void search(void)
{	

	int i=0,id,j,k=0;
	int flag=0;
	int fl=0;
	char xin[100];
	char *p=xin;
	printf("function search is called\n");
	printf("学号查找请按0,姓名查找请按1");
	scanf("%d",&flag);
	getchar();
	if (flag==0)
	{
	printf("请输入学号\n");
	scanf("%d",&id);
	getchar();
	for(i = 0;i<count;i++)
	{
		if(stu[i].id ==id)
		{
		fl=1;
		printf("学号\t名字\t分数\n");
		printf("%d\t%s\t%f\n",stu[i].id,stu[i].name,stu[i].score);
		}
	}
		if(fl==0)
		{
		printf("差无此人\n");
		}
}
	
	if(flag==1)
	{
	printf("请输入名字\n");
	scanf("%s",p);
	getchar();
		for(i=0;i<count;i++)
		{
			for(j=0;j<strlen(p);j++)
			{
				if(stu[i].name[j] ==*(p+j))
				{
				k++;
				}
			}
			if(k==strlen(p))
			{
			fl=1;
			goto and;
			}
			
		}
and:
		if(fl==1)
		{
		printf("%d\t%s\t%f\n",stu[i].id,stu[i].name,stu[i].score);
		}
		if(fl==0)
		{
		printf("没这个人");
		}
	}
	
}
	
	
void paixun_chengji(void)
{
 	int i=0;
	int j=0;
	struct student t;
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(stu[j].score>stu[j+1].score)
			{	
			t=stu[j+1];
			stu[j+1]=stu[j];
			stu[j]=t;
			}		
		}
	}
	printf("id\tname\tscore\n");
	for(i = 0;i<count;i++)
	{
		printf("%d\t%s\t%.2f\n",stu[i].id,stu[i].name,stu[i].score);
	}
}



void print_all_info(void)
{
	int i = 0;
	printf("系统里边共有%d名学生\n",count);
	printf("详细信息如下:\n");
	printf("id\tname\tscore\n");
	for(i = 0;i<count;i++)
	{
		printf("%d\t%s\t%.2f\n",stu[i].id,stu[i].name,stu[i].score);
	}
}



