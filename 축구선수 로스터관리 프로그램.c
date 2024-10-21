#include <stdio.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4996)

// 'player'라는 구조체를 정의
struct player
{
	char player_name[30];
	int player_back_number;
	int player_enroll_number;
	int player_price;
	int player_age;
	char player_age_group[50];
};
typedef struct player Player;	// 구조체의 이름을 명명


// 함수 선언
void printMenu(void);
void addPlayer(void);
void searchByPlayerBackNumber(void);
void searchByPlayerName(void);
void searchByPlayerAgeGroup(void);
void showPlayerList(void);
void flushInputBuffer(void);
void removeInputEnter(char * str);
void getAgeGroup(int age, char* age_group);

// 전역 변수로 선언
Player players[30];
int player_count = 1;

int main(void)
{
	int input_menu = 0;

	while (1)
	{
	
		printMenu();
		scanf("%d", &input_menu);

		switch(input_menu)
		{
		
		case 1:
			addPlayer();
			break;
		case 2:
			searchByPlayerBackNumber();
			break;	
		case 3:
			searchByPlayerName();
			break;
		case 4:
			searchByPlayerAgeGroup();
			break;
		case 5:
			showPlayerList();
			break;
		case 6:
			printf("종료합니다.\n");
			break;
		default:
			printf("잘못된 입력입니다. 다시 시도해주세요.\n");
			break;
		}
		if (input_menu == 6)
			break;
	}
	return 0;
}

void printMenu(void)
{
	system("cls");
	printf("-------------------------------------------------------\n");
	printf("1. 이번 시즌 1군에 등록될 선수 입력 \n");
	printf("2. 선수 검색 (등번호로 검색) \n");
	printf("3. 선수 검색 (이름으로 검색) \n");
	printf("4. 선수 검색 (연령대로 검색) \n");
	printf("5. 전체 1군 선수 정보 출력 \n");
	printf("6. 종료 \n");
	printf("메뉴 입력 >> ");
	return;
}

// 선수 추가 함수
void addPlayer(void)
{
	int age;
	char age_group[50];

	// 선수 등록된 순서 자동으로 추가 (1군 로스터 최대 인원 표시 위함) 
	players[player_count].player_enroll_number = player_count;

	if (players[player_count].player_enroll_number >= 31)
	{
		printf("1군 로스터 최대한도를 넘어선 번호 입니다\n");
		return;
	}

	// 선수 이름 입력 
	printf("선수 이름 공백없이 입력 (띄어야하면 '_' 사용)>> ");
	scanf("%s", players[player_count].player_name);

	// 선수 등번호 입력
	printf("선수 등번호 공백없이 입력 >> ");
	scanf("%d", &players[player_count].player_back_number);

	// 선수 가격 입력
	printf("선수 가격(m€) 정수 값 입력 >> ");
	scanf("%d", &players[player_count].player_price);

	// 선수 나이 입력
	printf("선수 나이 정수값 입력 >> ");
	scanf("%d", &age);
	players[player_count].player_age = age;
	getAgeGroup(age, age_group);

	// 연령대 저장
	strcpy(players[player_count].player_age_group, age_group);

	//시스템클리어
	system("cls");

	// 추가된 선수 출력
	printf("선수 추가 내용 \n");
	printf("--------------------------------------- \n" );
	printf("선수 등록 순서 : [%d]번째 \n", players[player_count].player_enroll_number);
	printf("선수 이름 : [%s] \n", players[player_count].player_name);
	printf("선수 등번호 : [%d] \n", players[player_count].player_back_number);
	printf("선수 나이 : [%d] \n", players[player_count].player_age);
	printf("선수 가격 : 약[%d m€] \n", players[player_count].player_price);
	printf("--------------------------------------- \n");

	player_count++;

	//Pause
	system("pause");
	//시스템클리어
	system("cls");

	return;
}


// 선수 등번호로 검색하는 함수
void searchByPlayerBackNumber(void)
{
	int player_back_number;
	int found = 0;

	printf("선수 등번호 입력 >> ");
	scanf("%d", &player_back_number);

	for (int i = 1; i < player_count; i++)
	{
		if (players[i].player_back_number == player_back_number)
		{
			printf("등번호 %d번 선수 정보 \n", players[i].player_back_number);
			printf("--------------------------------------- \n");
			printf("선수 등록 순서 : [%d]번째 \n", players[i].player_enroll_number);
			printf("선수 이름 : [%s] \n", players[i].player_name);
			printf("선수 나이 : [%d] \n", players[i].player_age);
			printf("선수 가격 : 약[%d m€] \n", players[i].player_price);
			printf("--------------------------------------- \n");
			found = 1;
			break;
		}
	}

	if (!found)
	{
		printf("존재하지 않는 등번호입니다.\n");
	}
	
	//Pause
	system("pause");
	//시스템클리어
	system("cls");

	return;
}


// 선수 이름으로 검색하는 함수
 void searchByPlayerName(void)
{
	char player_name[30];
	int target_number = -1;

	printf("선수 이름 입력 >> ");
	flushInputBuffer();
	fgets(player_name, sizeof(player_name), stdin);
	removeInputEnter(player_name);

	for (int i = 1; i < player_count; i++)
	{
		if (!strcmp(player_name, players[i].player_name))
		{
			target_number = i;
			break;
		}
	}

	if (target_number == -1) 
	{
		printf("존재하지 않는 선수\n");
	}
	else
	{
		printf("선수 내용 \n");
		printf("--------------------------------------- \n");
		printf("선수 등록 순서 : [%d]번째 \n", players[target_number].player_enroll_number);
		printf("선수 이름 : [%s] \n", players[target_number].player_name);
		printf("선수 등번호 : [%d] \n", players[target_number].player_back_number);
		printf("선수 나이 : [%d] \n", players[target_number].player_age);
		printf("선수 가격 : 약[%d m€] \n", players[target_number].player_price);
		printf("--------------------------------------- \n");
	}

	//Pause
	system("pause");
	//시스템클리어
	system("cls");

	return;
}


 // 나이를 연령대로 변환하는 함수
 void getAgeGroup(int age, char* age_group)
 {
	 if (age >= 10 && age <= 19)
	 {
		 sprintf(age_group, "10대");
	 }
	 else if (age >= 20 && age <= 29)
	 {
		 sprintf(age_group, "20대");
	 }
	 else if (age >= 30 && age <= 39)
	 {
		 sprintf(age_group, "30대");
	 }
	 else
	 {
		 sprintf(age_group, "등록되어있지 않은 나이대");
	 }
 }

 // 연령대로 선수 검색
 void searchByPlayerAgeGroup(void)
 {
	 char age_group[50];
	 int found = 0;

	 printf("선수 연령대 입력 ('10대', '20대'와 같이 입력) >> ");
	 flushInputBuffer();
	 fgets(age_group, sizeof(age_group), stdin);
	 removeInputEnter(age_group);

	 printf("연령대가 %s인 선수들:\n", age_group);
	 for (int i = 1; i < player_count; i++)
	 {
		 if (strcmp(players[i].player_age_group, age_group) == 0)
		 {
			 printf("--------------------------------------- \n");
			 printf("선수 등록 순서 : [%d]번째 \n", players[i].player_enroll_number);
			 printf("선수 이름 : [%s] \n", players[i].player_name);
			 printf("선수 등번호 : [%d] \n", players[i].player_back_number);
			 printf("선수 나이 : [%d] \n", players[i].player_age);
			 printf("선수 가격 : 약[%d m€] \n", players[i].player_price);
			 printf("--------------------------------------- \n");
			 found = 1;
		 }
	 }
	 if (!found)
	 {
		 printf("해당 연령대의 선수를 찾을 수 없습니다.\n");
	 }

	//Pause
	system("pause");
	//시스템클리어
	system("cls");

	return;
}



// 전체 선수 리스트 출력
void showPlayerList(void)
{
	int i=1;

	while (i < player_count)
	{
		
		printf("1군 등록된 선수 명단 \n");
		printf("--------------------------------------- \n");
		printf("선수 등록 순서 : [%d]번째 \n", players[i].player_enroll_number);
		printf("선수 이름 : [%s] \n", players[i].player_name);
		printf("선수 등번호 : [%d] \n", players[i].player_back_number);
		printf("선수 연령 : [%d] \n", players[i].player_age);
		printf("선수 가격 : 약[%d]m \n", players[i].player_price);
		printf("--------------------------------------- \n");
		i++;
	}

	//Pause
	system("pause");
	//시스템클리어
	system("cls");

	return;
}

void flushInputBuffer(void)
{
	while (getchar() != '\n');	// 입력 버퍼 제거
	return;
}

void removeInputEnter(char* str)
{
	int i = 0;
	while (str[i] != '\n')
		i++;
	str[i] = '\0';
	return;
}

