#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include "Loader.h"

int main(void)
{
  fMessage fMsg[NMESSAGES];
    //  Open the desired libraries.
  HANDLE hHello   = dlopen("./Hello.so", RTLD_LAZY);
  HANDLE hGoodbye = dlopen("./Goodbye.so", RTLD_LAZY);
  HANDLE hWazUp = NULL;
  /*HANDLE hWazUp   = dlopen("./libHello.dll", RTLD_LAZY);*/
  int exitcode = 0, i;

    //  Check that the libraries opened.
  if (!hHello || !hGoodbye)
  {
    fprintf(stderr, "Open: %s\n", dlerror());
    exitcode = -1;
    goto LABEL_EXIT;
  }
  if (!hWazUp)
  {
    fprintf(stderr, "Windows Dll Open: %s\n", dlerror());
  }

    //  Load symbols from libraries.
  fMsg[0] = (fMessage)dlsym(hHello, "message1");
  fMsg[1] = (fMessage)dlsym(hHello, "message2");
  fMsg[2] = (fMessage)dlsym(hGoodbye, "message1");
  fMsg[3] = (fMessage)dlsym(hGoodbye, "message2");
  /*sleep(100);*/
  //  Check that the symbols loaded.
  for(i = 0; i < NMESSAGES; i++)
  {
    if (!fMsg[i])
    {
      fprintf(stderr, "Msg%i: %s\n", i, dlerror());
      exitcode = i;
      goto LABEL_EXIT;
    }
  }

    //  Print message pairs.
  fMsg[0]();  fMsg[1]();  // Hello World!
  fMsg[2]();  fMsg[3]();  // Goodbye Cruel World!
  fMsg[0]();  fMsg[3]();  // Hello Cruel World!
  fMsg[2]();  fMsg[1]();  // Goodbye World!

    //  If by some miracle the windows dll loaded, load & call its function.
  if (hWazUp)
  {
    fMessage fWinMsg = (fMessage)dlsym(hWazUp, "message1");
    if (!fWinMsg)
    {
      fprintf(stderr, "WinMsg: %s\n", dlerror());
      exitcode = 5;
      goto LABEL_EXIT;
    }
    fWinMsg();
  }

LABEL_EXIT:
    //  clean up the library handles.
  if (hHello)
    dlclose(hHello);
  if (hGoodbye)
    dlclose(hGoodbye);
  if (hWazUp)
    dlclose(hWazUp);

  return exitcode;
}
