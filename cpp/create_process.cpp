#include <windows.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  if( !CreateProcess( NULL,   // No module name (use command line)
      argv[1],        // Command line
      NULL,           // Process handle not inheritable
      NULL,           // Thread handle not inheritable
      FALSE,          // Set handle inheritance to FALSE
      0,              // No creation flags
      NULL,           // Use parent's environment block
      NULL,           // Use parent's starting directory 
      &si,            // Pointer to STARTUPINFO structure
      &pi )           // Pointer to PROCESS_INFORMATION structure
  ) {
      printf( "CreateProcess failed (%d).\n", GetLastError() );
      return 0;
  }

  // Wait until child process exits.
  WaitForSingleObject( pi.hProcess, INFINITE );

  FILETIME create_time, exit_time, kernel_time, user_time;
  GetProcessTimes(pi.hProcess, &create_time, &exit_time, &kernel_time, &user_time);

  SYSTEMTIME dura;
  FileTimeToSystemTime(&user_time, &dura);

  printf("min:%d, s:%d, ms:%d\n", dura.wMinute, dura.wSecond, dura.wMilliseconds);

  // Close process and thread handles. 
  CloseHandle( pi.hProcess );
  CloseHandle( pi.hThread );
  return 0;
}