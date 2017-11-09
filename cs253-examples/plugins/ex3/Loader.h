// This program was created by Daniel Sayko.
// It was created in April 2001.

#ifndef DLLOAD_H
#define DLLOAD_H

typedef void* HANDLE;
typedef void (*fMessage)();

#define NMESSAGES 4

#ifdef WIN32
#define dlopen(file, garbage) (LoadLibraryA(file))
#define dlsym GetProcAddress
#define dlerror GetLastError
#define dlclose FreeLibrary
#endif


#endif
