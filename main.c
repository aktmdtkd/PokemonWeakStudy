#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define NORMAL 0
#define FIRE 1
#define WATER 2
#define GRASS 3
#define ELECTRIC 4
#define ICE 5
#define FIGHTING 6
#define POISON 7
#define GROUND 8
#define FLYING 9
#define PSYCHIC 10
#define BUG 11
#define ROCK 12
#define GHOST 13
#define DRAGON 14
#define DARK 15
#define STEEL 16
#define FAIRY 17

void textcolor(int color_number){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

void problem(int count);
void PrintType(int number);
//                   0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17
int TYPE[18][18]=  {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}//노말이 약점인 애들 
				   ,{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0}//불 
				   ,{0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}//물 
				   ,{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}//풀 
				   ,{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}//전기 
				   ,{0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0}//얼음 
				   ,{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0}//격투 
				   ,{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}//독 
				   ,{0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0}//땅 
				   ,{0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}//비행 
				   ,{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}//에스퍼 
				   ,{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0}//벌레 
				   ,{0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}//바위 
				   ,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}//고스트 
				   ,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}//드래곤 
				   ,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}//악 
				   ,{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}//강철 
				   ,{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}};//페어리 
//[type_A][Type_B] == 1 인 경우 A는 B의 약점(중 하나)이다. 

int main(void) {
	system("mode con cols=70 lines=5");
    int pikapika = 1;
	printf("포켓몬 각 타입 상성 약점 공부 프로그램 Masik_ver_1.0\n");
	printf("제작   : Masik(이라 쓰고 조형남이라 읽는다.)\n검수자 : 김현우\n");
	printf("계속 하시려면 아무키나 눌러주십시오.");
	getch();
	while(1)
	{
		problem(pikapika);
		pikapika = pikapika % 10 + 1;
	}
}

void problem(int count)
{
	system("mode con cols=45 lines=20");
	int RT[6];
	int RandNumber, answer, RealAnswer, i, tile = 0, pikapika, gacha;
	static int combo = 0, hwecha = 1, correct=0, incorrect=0;
	srand(time(NULL));
	printf("%d회차 문제", hwecha);
	printf("\n\n%d번 문제 : 다음 포켓몬의 약점은 무엇일까요?\n\n", count);
	RandNumber = rand() % 18;
	PrintType(RandNumber);
	printf("의 약점은?(복수여도 하나만 체크)\n");
	RT[0] = -1;
	RT[1] = rand() % 18;
	while(1)	{
		RT[2] = rand() % 18;
		if(RT[2] != RT[1]) break;
	}
	while(1)	{
		RT[3] = rand() % 18;
		if(RT[3] != RT[1] && RT[3] != RT[2]) break;
	}
	while(1)	{
		RT[4] = rand() % 18;
		if(RT[4] != RT[3] && RT[4] != RT[1] && RT[4] != RT[2]) break;
	}
	while(1)	{
		RT[5] = rand() % 18;
		if(RT[5] != RT[4] && RT[5] != RT[1] && RT[5] != RT[2] && RT[5] != RT[3]) break;
	}
	printf("\n1번 : ");	PrintType(RT[1]);
	printf("\n2번 : ");	PrintType(RT[2]);
	printf("\n3번 : ");	PrintType(RT[3]);
	printf("\n4번 : ");	PrintType(RT[4]);
	printf("\n5번 : ");	PrintType(RT[5]);
	printf("\n6번 : 이중에 없음");
	printf("\n\n답을 입력하시오(1~6중에 숫자만 입력) : ");
	scanf("%d", &answer);
	
	////////
	
	if(TYPE[RT[5]][RandNumber]==0 && TYPE[RT[1]][RandNumber]==0 && TYPE[RT[2]][RandNumber]==0 && TYPE[RT[3]][RandNumber]==0 && TYPE[RT[4]][RandNumber]==0 && answer == 6)
	{
		printf("정답입니다.\n");
		correct++;
		combo++;
		tile++;
		textcolor(14);
		if(combo > 1) printf("%d 콤보\n", combo);
		textcolor(15);
	}
	if(TYPE[RT[answer]][RandNumber]==1)
	{
		printf("정답입니다.\n");
		combo++;
		correct++;
		textcolor(14);
		if(combo > 1) printf("%d 콤보!\n", combo);
		textcolor(15);
	}
	if(TYPE[RT[answer]][RandNumber]==0 && tile == 0)
	{
		printf("틀렸습니다.\n");
		incorrect++;
		if(combo > 1) printf("콤보끊김\n");
		combo=0;
	}
	printf("%2d회차 맞은 문제 갯수:%2d\n%2d회차 틀린 문제 갯수:%2d\n", hwecha, correct, hwecha, incorrect);
	
	gacha = rand()%5; 
	if(gacha == 0) printf("5252 츠즈쿠 하고싶으면 아무키나 꾹꾹하라우");
	else printf("다음문제로 넘어가려면 아무키나 눌러주세요.");
	getch();
	if(count > 9) {
		hwecha++;
		correct = 0;
		incorrect = 0;
	}
}
void PrintType(int number)
{
	textcolor(11);
	if(number == NORMAL) printf("노말");
	if(number == FIRE) printf("불");
	if(number == WATER) printf("물");
	if(number == GRASS) printf("풀");
	if(number == ELECTRIC) printf("전기");
	if(number == ICE) printf("얼음");
	if(number == FIGHTING) printf("격투");
	if(number == POISON) printf("독");
	if(number == GROUND) printf("땅");
	if(number == FLYING) printf("비행");
	if(number == PSYCHIC) printf("에스퍼");
	if(number == BUG) printf("벌레");
	if(number == ROCK) printf("바위");
	if(number == GHOST) printf("고스트");
	if(number == DRAGON) printf("드래곤");
	if(number == DARK) printf("악");
	if(number == STEEL) printf("강철");
	if(number == FAIRY) printf("페어리");
	textcolor(15);
}