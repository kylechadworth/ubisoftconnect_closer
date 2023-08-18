#include <iostream>
#include <Windows.h>

int main()
{
    HWND hWnd = FindWindowA(NULL, "Ubisoft Connect");
    if (hWnd == NULL) {
        std::cout << "Ubisoft Connect aint running." << std::endl;
        return -1;
    }
    DWORD pid;
    GetWindowThreadProcessId(hWnd, &pid);
    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (hProc == NULL) {
        std::cout << "Cant access the ubi" << std::endl;
        return -1;
    }
    TerminateProcess(hProc, 0);
    MessageBoxA(NULL, "Ubi gone.", "Done!", MB_OK);
    return 0;
}
