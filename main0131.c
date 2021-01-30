
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
	printf("원의 반지름 : %g \n", circle.rad);
	printf("원의 중심점 : [ %d , %d ] \n", (*circle.cen).x, circle.cen->y);
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
	printf("원의 반지름 : %g \n", circle.rad);
	printf("원의 중심점 : [ %d , %d ] \n", circle.center.x, circle.center.y);

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
void input(Point* _pos)//포인터변수
{
	_pos->x = 100;
	_pos->y = 200;
}
int main()
{
	Point pos = {10,20};
	disp(pos);

	input(&pos);//Point타입변수의 주소
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
	//구조체변수도 일반변수사용법 동일하게 쓰세요...
	Point pos = {10,20};//초기화

	printf("%d %d\n", sizeof(Point), sizeof(pos));
	printf("%d %d\n", pos.x, pos.y);

	//구조체 배열
	Point arr[3] = { {1,2},{3,4},{5,6} };

	//포인터
	Point* ptr = &pos;

	printf("%d %d\n", (*ptr).x, (*ptr).y );
	//(*ptr).x : ptr이 가리키는 구조체변수의 멤버x 

	//표현식이 어려워요 복잡해요 
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

typedef struct// point2   생략가능
{
	int x;
	int y;
}Point2;

int main()
{
	struct point pos2;//사용은 가능하나  쓰겠어요?
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
//사용자가 만든 자료형
struct person
{
	//구조체 멤버
	char name[20];
	char phone[20];
	int age;
	double height;

};

int main()
{
	
	//구조체타입 변수이름;
	struct person man;
	puts("이름입력!");
	fgets(man.name, 20,stdin);

	puts("전화번호 입력!");
	fgets(man.phone, 20,stdin);

	puts("나이 입력!");
	scanf_s("%d", &man.age);

	puts("키 입력!");
	scanf_s("%lf", &man.height);

	printf("이름 : %s\n", man.name);
	printf("전화 : %s\n", man.phone);
	printf("나이 : %d\n", man.age);
	printf("키 : %.2f\n", man.height);

	return 0;
}
//*/

//구조체

//이름,국어,영어,수학,총점,평균
//효율적인 관리가 가능
/*
#include<stdio.h>
int main()
{
	//1반의 성적관리
	//인원 20명
	//국영수
	char* subject[3] = {"KOR", "ENG", "MAT"};
	char* name[4] = { "조인성", "장동건", "강동원", "전지현" };
	int kor[4] = { 77,88,80,90 };
	int eng[4] = { 80,90,100,80 };
	int mat[4] = { 90,100,85,88 };
	int tot[4];//tot[0], tot[1], tot[2], tot[3]
	double avg[4];
	for (int i = 0; i < 4; i++)
	{
		//총점계산
		tot[i] = kor[i] + eng[i] + mat[i];
		//평균
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
	fopen_s(&file,"test01.txt", "wt");//wt:쓰기모드,text파일

	//w모드는 파일이 존재하지않으면 자동으로 생성시켜준다.

	if (file != NULL)//출력스트림이 정상적으로 만들어졌으면
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
//파일 : 텍스트파일, 바이너리파일
//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//FILE* file=fopen("test.txt","rt");//rt :읽기, 텍스트파일
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

//버퍼를 비우는 함수
void clearBuffer() {
	while (getchar() != 10) { ; }
}

int main()
{
	int ch, ch2;

	puts("한글자 입력해주세요");
	ch =getchar();
	//getchar();//엔터를 제거
	clearBuffer();
	puts("한번더 입력해주세요");
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

	fputs("이름 : ", stdin);
	fgets(name, sizeof(name), stdin);

	fputs("전화 : ", stdin);
	fgets(phone, sizeof(phone), stdin);

	printf("입력된 이름 : %s\n", name);
	printf("입력된 전화 : %s\n", phone);

	return 0;
}
//*/

/*
//문자열단위 입출력
//puts() ,fputs()
//gets_s() ,fgets()
#include<stdio.h>
int main()
{
	//char* str = "hello!";
	//puts(str);//자동줄바꿈
	//fputs(str, stdout);
	char buffer[5];
	// gets_s(저장주소,최대사이즈)
	//gets_s(buffer, sizeof(buffer));
	fgets(buffer, sizeof(buffer), stdin);


	puts(buffer);

	return 0;
}
//*/

/*
//문자단위 입출력함수
#include<stdio.h>

int main()
{
	int ch;
	//ch=getchar();
	//성공시에는 문자정보, 실패시에는 EOF

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
	//문자열저장
	char str[] = "hello";

	//문자열상수의 첫번째문자의주소만 저장
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
	
	printf("결과 : %d\n", result);
	puts("-----------");
	// int (*ptr)[4]
	disp(arr2, sizeof(arr2) / sizeof(arr2[0]));

	return 0;
}
//*/