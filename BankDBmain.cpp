// Visual Studio 2019에서 작성된 코드입니다.

#include <iostream>

#define NAME_LEN 20

void ShowMenu(); // 메뉴 출력
void MakeAccount(); // 계좌개설을 위한 함수
void DepositMoney(); // 입금
void WithdrawMoney(); // 출금
void ShowAllAccInfo(); // 계좌정보 전체 출력

typedef struct _AccoutInfo
{
	int accID; // 고객 정보
	char name[NAME_LEN]; // 고객이름
	int money; // 잔액
}Account;

Account accArr[100]; // Account 저장을 위한 배열
int accNum = 0; // 저장된 Account 수

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();

		std::cout << "선택 : ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				DepositMoney();
				break;
			case WITHDRAW:
				WithdrawMoney();
				break;
			case INQUIRE:
				ShowAllAccInfo();
				break;
			case EXIT:
				return 0;
			default:
				std::cout << "메뉴를 잘못 선택하셨습니다." << std::endl;
				break;
		}
	}

	return 1;
}

void ShowMenu()
{
	std::cout << "------ Menu ------" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입금" << std::endl;
	std::cout << "3. 출금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int money;
	
	std::cout << "[계좌개설]" << std::endl;

	std::cout << "계좌ID : ";
	std::cin >> id;

	std::cout << "이름 : ";
	std::cin >> name;

	std::cout << "입금액 : ";
	std::cin >> money;
	std::cout << std::endl;

	accArr[accNum].accID = id;
	strcpy_s(accArr[accNum].name, sizeof(accArr[accNum].name), name);
	accArr[accNum].money = money;

	accNum++;
}

void DepositMoney()
{
	int id;
	int money;

	std::cout << "[입금]" << std::endl;
	
	std::cout << "계좌ID : ";
	std::cin >> id;
	
	std::cout << "입금액 : ";
	std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].money += money;
			std::cout << "입금이 완료되었습니다. \n" << std::endl;
			return;
		}
	}

	std::cout << "유효하지 않은 ID입니다. \n" << std::endl;
}

void WithdrawMoney()
{
	int id;
	int money;

	std::cout << "[출금]" << std::endl;

	std::cout << "계좌ID : ";
	std::cin >> id;

	std::cout << "출금액 : ";
	std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].money < money)
			{
				std::cout << "잔액이 부족합니다. \n" << std::endl;
				return;
			}
			else
			{
				accArr[i].money -= money;
				std::cout << "출금이 완료되었습니다. \n" << std::endl;
				return;
			}
		}
	}

	std::cout << "유효하지 않은 ID입니다. \n" << std::endl;
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		std::cout << "계좌ID : " << accArr[i].accID << std::endl;
		std::cout << "이름 : " << accArr[i].name << std::endl;
		std::cout << "잔액 : " << accArr[i].money << std::endl << std::endl;
	}
}