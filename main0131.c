
#include<stdio.h>
typedef struct
{
	int x;
	int y;
}Point;

typedef struct
{
	double rad;
	Point* cen;
}Circle;


int main()
{
	Point pos = { 2,3 };
	double rad = 3.5;

	Circle circle = { rad, &pos };
	printf("���� ������ : %g \n", circle.rad);
	printf("���� �߽��� : [ %d , %d ] \n", (*circle.cen).x, circle.cen->y);
	//(*ptr).x  == ptr->x
	//(*circle.cen).x  == circle.cen->x
	return 0;
}



/*
#include<stdio.h>
typedef struct
{
	int x;
	int y;
}Point;

typedef struct
{
	double rad;
	Point center;
}Circle;


int main()
{
	Point pos = { 2,3 };
	double rad = 3.5;

	Circle circle = {rad, pos};
	printf("���� ������ : %g \n", circle.rad);
	printf("���� �߽��� : [ %d , %d ] \n", circle.center.x, circle.center.y);

	return 0;
}
//*/
/*
#include<stdio.h>
typedef struct
{
	int x;
	int y;
}Point;

void disp(Point _pos)
{
	printf("x : %d\n", _pos.x);
	printf("y : %d\n", _pos.y);
}
void input(Point* _pos)//�����ͺ���
{
	_pos->x = 100;
	_pos->y = 200;
}
int main()
{
	Point pos = {10,20};
	disp(pos);

	input(&pos);//PointŸ�Ժ����� �ּ�
	disp(pos);
	return 0;
}
//*/

/*
#include<stdio.h>
typedef struct 
{
	int x;
	int y;
}Point;

int main()
{
	//����ü������ �Ϲݺ������� �����ϰ� ������...
	Point pos = {10,20};//�ʱ�ȭ

	printf("%d %d\n", sizeof(Point), sizeof(pos));
	printf("%d %d\n", pos.x, pos.y);

	//����ü �迭
	Point arr[3] = { {1,2},{3,4},{5,6} };

	//������
	Point* ptr = &pos;

	printf("%d %d\n", (*ptr).x, (*ptr).y );
	//(*ptr).x : ptr�� ����Ű�� ����ü������ ���x 

	//ǥ������ ������� �����ؿ� 
	//*(arr+i) == arr[i]
	// (*ptr).x  ==  ptr->x

	printf("%d %d\n", ptr->x, ptr->y);


	return 0;
}
//*/

/*
#include<stdio.h>

typedef struct point
{
	int x;
	int y;
}Point;

typedef struct// point2   ��������
{
	int x;
	int y;
}Point2;

int main()
{
	struct point pos2;//����� �����ϳ�  ���ھ��?
	Point pos;
	return 0;
}
//*/

/*
#include<stdio.h>

struct point
{
	int x;
	int y;
};

typedef struct point	Point;
typedef unsigned int	UINT;

int main()
{
	//struct point pos;
	Point pos;
	pos.x = 2;
	pos.y = 3;
	unsigned int a = 10;
	UINT b = 20;

	printf("[x, y] : [%d, %d]\n", pos.x, pos.y);


	return 0;
}
//*/

/*
#include<stdio.h>
//����ڰ� ���� �ڷ���
struct person
{
	//����ü ���
	char name[20];
	char phone[20];
	int age;
	double height;

};

int main()
{
	
	//����üŸ�� �����̸�;
	struct person man;
	puts("�̸��Է�!");
	fgets(man.name, 20,stdin);

	puts("��ȭ��ȣ �Է�!");
	fgets(man.phone, 20,stdin);

	puts("���� �Է�!");
	scanf_s("%d", &man.age);

	puts("Ű �Է�!");
	scanf_s("%lf", &man.height);

	printf("�̸� : %s\n", man.name);
	printf("��ȭ : %s\n", man.phone);
	printf("���� : %d\n", man.age);
	printf("Ű : %.2f\n", man.height);

	return 0;
}
//*/

//����ü

//�̸�,����,����,����,����,���
//ȿ������ ������ ����
/*
#include<stdio.h>
int main()
{
	//1���� ��������
	//�ο� 20��
	//������
	char* subject[3] = {"KOR", "ENG", "MAT"};
	char* name[4] = { "���μ�", "�嵿��", "������", "������" };
	int kor[4] = { 77,88,80,90 };
	int eng[4] = { 80,90,100,80 };
	int mat[4] = { 90,100,85,88 };
	int tot[4];//tot[0], tot[1], tot[2], tot[3]
	double avg[4];
	for (int i = 0; i < 4; i++)
	{
		//�������
		tot[i] = kor[i] + eng[i] + mat[i];
		//���
		avg[i] = (double)tot[i] / 3;
	}

	for (int i = 0; i < 4; i++)
	{
		printf("%s : %3d %3d %3d %3d %.2f\n", name[i], kor[i], eng[i], mat[i], tot[i], avg[i]);
	}

	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	FILE* file=NULL;
	fopen_s(&file,"test01.txt", "wt");//wt:������,text����

	//w���� ������ �������������� �ڵ����� ���������ش�.

	if (file != NULL)//��½�Ʈ���� ���������� �����������
	{
		fputc('a', file);
		fputc('b', file);
		fputc('c', file);

		fclose(file);
	}

	return 0;
}
//*/

/*
//���� : �ؽ�Ʈ����, ���̳ʸ�����
//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//FILE* file=fopen("test.txt","rt");//rt :�б�, �ؽ�Ʈ����
	FILE* file=NULL;
	fopen_s(&file, "test.txt", "rt");
	if (file!=NULL) 
	{
		int readChar;
		while ((readChar = fgetc(file)) != EOF) 
		{
			printf("%c", readChar);
		}
		fclose(file);
	}

	return 0;
}
//*/

/*
#include<stdio.h>

//���۸� ���� �Լ�
void clearBuffer() {
	while (getchar() != 10) { ; }
}

int main()
{
	int ch, ch2;

	puts("�ѱ��� �Է����ּ���");
	ch =getchar();
	//getchar();//���͸� ����
	clearBuffer();
	puts("�ѹ��� �Է����ּ���");
	ch2 = getchar();

	printf("ch : %c %d\n", ch, ch);
	printf("ch2 : %c %d\n", ch2, ch2);


	return 0;
}
//*/
/*
#include<stdio.h>
int main()
{
	char name[10];
	char phone[20];

	fputs("�̸� : ", stdin);
	fgets(name, sizeof(name), stdin);

	fputs("��ȭ : ", stdin);
	fgets(phone, sizeof(phone), stdin);

	printf("�Էµ� �̸� : %s\n", name);
	printf("�Էµ� ��ȭ : %s\n", phone);

	return 0;
}
//*/

/*
//���ڿ����� �����
//puts() ,fputs()
//gets_s() ,fgets()
#include<stdio.h>
int main()
{
	//char* str = "hello!";
	//puts(str);//�ڵ��ٹٲ�
	//fputs(str, stdout);
	char buffer[5];
	// gets_s(�����ּ�,�ִ������)
	//gets_s(buffer, sizeof(buffer));
	fgets(buffer, sizeof(buffer), stdin);


	puts(buffer);

	return 0;
}
//*/

/*
//���ڴ��� ������Լ�
#include<stdio.h>

int main()
{
	int ch;
	//ch=getchar();
	//�����ÿ��� ��������, ���нÿ��� EOF

	//putchar(ch);
	//printf("%d %c\n", ch, ch);

	int ch1=fgetc(stdin);
	fputc(ch1, stdout);
	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	//���ڿ�����
	char str[] = "hello";

	//���ڿ������ ù��°�������ּҸ� ����
	char* str1 = "hello";

	puts(str);
	puts(str1);
	return 0;
}
//*/

/*
#include<stdio.h>

      //int * arr
int sum(int arr[], int length)
{
	int result = 0;
	for (int i = 0; i < length; i++) {
		result += arr[i];
	}

	return result;
}
//arr[0]==*(arr+0)
//        int(*arr2)[4]
void disp(int arr2[][4],int rows)
{
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%2d ", arr2[i][j]);
		}
		puts("");
	}
}

int main()
{
	int arr[] = { 10,20,30 };
	int arr2[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	// arr2[0], arr2[1], arr2[2]

	int result=sum(arr, sizeof(arr)/sizeof(int));
	
	printf("��� : %d\n", result);
	puts("-----------");
	// int (*ptr)[4]
	disp(arr2, sizeof(arr2) / sizeof(arr2[0]));

	return 0;
}
//*/