#include <stdio.h>
#include <Windows.h>

int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	
	if (CreateProcess(
		L"C:\\Windows\\system32\\notepad.exe",
		NULL,								// Командная строка.
		NULL,								// Дескриптор процесса не наследуемый.
		NULL,								// Дескриптор потока не наследуемый.
		FALSE,								// Установим наследование дескриптора в FALSE.
		0,									// Флажков создания нет.
		NULL,								// Используйте блок конфигурации родителя.
		NULL,								// Используйте стартовый каталог родителя.
		&si,								// Указатель на структуру STARTUPINFO.
		&pi)								// Указатель на структуру PROCESS_INFORMATION.
		)
		printf("Create Process Success\n"); 
	else printf("Create Process Failed. Error: %ld\n", GetLastError());
	
	// Ждать до тех пор, пока дочерний процесс не выйдет из работы.
	WaitForSingleObject(pi.hProcess, INFINITE);
	
	// Закроем дескрипторы процесса и потока.
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	system("PAUSE");
	return 0;
}