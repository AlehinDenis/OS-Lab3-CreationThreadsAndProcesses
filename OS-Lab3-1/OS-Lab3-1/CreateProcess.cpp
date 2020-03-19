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
		NULL,								// ��������� ������.
		NULL,								// ���������� �������� �� �����������.
		NULL,								// ���������� ������ �� �����������.
		FALSE,								// ��������� ������������ ����������� � FALSE.
		0,									// ������� �������� ���.
		NULL,								// ����������� ���� ������������ ��������.
		NULL,								// ����������� ��������� ������� ��������.
		&si,								// ��������� �� ��������� STARTUPINFO.
		&pi)								// ��������� �� ��������� PROCESS_INFORMATION.
		)
		printf("Create Process Success\n"); 
	else printf("Create Process Failed. Error: %ld\n", GetLastError());
	
	// ����� �� ��� ���, ���� �������� ������� �� ������ �� ������.
	WaitForSingleObject(pi.hProcess, INFINITE);
	
	// ������� ����������� �������� � ������.
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	system("PAUSE");
	return 0;
}