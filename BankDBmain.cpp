// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#include <iostream>

#define NAME_LEN 20

void ShowMenu(); // �޴� ���
void MakeAccount(); // ���°����� ���� �Լ�
void DepositMoney(); // �Ա�
void WithdrawMoney(); // ���
void ShowAllAccInfo(); // �������� ��ü ���

typedef struct _AccoutInfo
{
	int accID; // �� ����
	char name[NAME_LEN]; // ���̸�
	int money; // �ܾ�
}Account;

Account accArr[100]; // Account ������ ���� �迭
int accNum = 0; // ����� Account ��

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();

		std::cout << "���� : ";
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
				std::cout << "�޴��� �߸� �����ϼ̽��ϴ�." << std::endl;
				break;
		}
	}

	return 1;
}

void ShowMenu()
{
	std::cout << "------ Menu ------" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �Ա�" << std::endl;
	std::cout << "3. ���" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int money;
	
	std::cout << "[���°���]" << std::endl;

	std::cout << "����ID : ";
	std::cin >> id;

	std::cout << "�̸� : ";
	std::cin >> name;

	std::cout << "�Աݾ� : ";
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

	std::cout << "[�Ա�]" << std::endl;
	
	std::cout << "����ID : ";
	std::cin >> id;
	
	std::cout << "�Աݾ� : ";
	std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].money += money;
			std::cout << "�Ա��� �Ϸ�Ǿ����ϴ�. \n" << std::endl;
			return;
		}
	}

	std::cout << "��ȿ���� ���� ID�Դϴ�. \n" << std::endl;
}

void WithdrawMoney()
{
	int id;
	int money;

	std::cout << "[���]" << std::endl;

	std::cout << "����ID : ";
	std::cin >> id;

	std::cout << "��ݾ� : ";
	std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].money < money)
			{
				std::cout << "�ܾ��� �����մϴ�. \n" << std::endl;
				return;
			}
			else
			{
				accArr[i].money -= money;
				std::cout << "����� �Ϸ�Ǿ����ϴ�. \n" << std::endl;
				return;
			}
		}
	}

	std::cout << "��ȿ���� ���� ID�Դϴ�. \n" << std::endl;
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		std::cout << "����ID : " << accArr[i].accID << std::endl;
		std::cout << "�̸� : " << accArr[i].name << std::endl;
		std::cout << "�ܾ� : " << accArr[i].money << std::endl << std::endl;
	}
}