#include <stdio.h>
#include <Windows.h>

volatile int Var;

DWORD WINAPI ThreadFunctionVarPlus(LPVOID lpParam)
{
	int i;
	for (i = 0; i < 100000000; i++)
		Var++;
	return 0;
}

DWORD WINAPI ThreadFunctionVarMinus(LPVOID lpParam)
{
	int i;
	for (i = 0; i < 100000000; i++)
		Var--;
	return 0;
}

int main()
{
	printf("Var = %i\n", Var);

	HANDLE hThread[20];
	DWORD ThreadID[20];

	int i;
	for (i = 0;i < 10; i++)
		hThread[i] = CreateThread(
			NULL,
			0,
			ThreadFunctionVarPlus,
			NULL,
			0,
			&ThreadID[i]);

	for (i; i < 20; i++)
		hThread[i] = CreateThread(
			NULL,
			0,
			ThreadFunctionVarMinus,
			NULL,
			0,
			&ThreadID[i]);

	int ThreadsCreatFail = 0;
	for (i = 0; i < 20; i++)
		if (hThread[i] == NULL)
			ThreadsCreatFail++;

	printf("%i Threads Created Failed\n", ThreadsCreatFail);

	for (i = 0; i < 20; i++)
		CloseHandle(hThread[i]);

	printf("Var = %i\n", Var);

	system("PAUSE");
	return 0;
}