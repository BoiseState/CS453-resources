#include <dlfcn.h>
#include <stdio.h>
#include "Loader.h"

int main()
{
  fMessage fMsg[NMESSAGES];
  //  Open the desired libraries.
  HANDLE hHello   = dlopen("./Hello.so", RTLD_LAZY);
  HANDLE temp   = dlopen("./temp.so", RTLD_LAZY);
  HANDLE hGoodbye = dlopen("./Goodbye.so", RTLD_LAZY);
  int exitcode = 0, i;

  //  Check that the libraries opened.
  if (!hHello || !hGoodbye) {
    fprintf(stderr, "Open: %s\n", dlerror());
    exitcode = -1;
    goto LABEL_EXIT;
  }

  printf("handle for Hello lib = %x,  handle for second hello lib %x \n", hHello, temp);

  //  Load symbols from libraries.
  fMsg[0] = (fMessage)dlsym(hHello, "message1");
  fMsg[1] = (fMessage)dlsym(hHello, "message2");
  fMsg[2] = (fMessage)dlsym(temp, "message1");
  fMsg[3] = (fMessage)dlsym(temp, "message2");

  //  Check that the symbols loaded.
  for(i = 0; i < NMESSAGES; i++) {
    if (!fMsg[i]) {
      fprintf(stderr, "Msg%i: %s\n", i, dlerror());
      exitcode = i;
      goto LABEL_EXIT;
    }
  }

  //  Print message pairs.
  fMsg[0]();  fMsg[1]();  // Hello World!
  fMsg[2]();  fMsg[3]();  // Hello World again from the second copy of the library


LABEL_EXIT:
    //  clean up the library handles.
  if (hHello)
    dlclose(hHello);
  if (hGoodbye)
    dlclose(hGoodbye);

  return exitcode;
}
