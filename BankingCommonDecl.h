// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int NAME_LEN = 20;

// ���α׷� ������� ���� �޴�
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// �ſ���
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// ������ ����
enum { NORMAL = 1, CREDIT };

#endif