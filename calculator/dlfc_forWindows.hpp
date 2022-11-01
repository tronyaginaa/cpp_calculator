//
//  dlfc_forWindows.hpp
//  calculator
//
//  Created by Alexandra on 01.11.2022.
//

#ifndef dlfc_forWindows_hpp
#define dlfc_forWindows_hpp

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define RTLD_GLOBAL 0x100 /* do not hide entries in this module */
#define RTLD_LOCAL  0x000 /* hide entries in this module */

#define RTLD_LAZY   0x000 /* accept unresolved externs */
#define RTLD_NOW    0x001 /* abort if module has unresolved externs */

/*
   How to call in Windows:

   void *h = dlopen ("path\\library.dll", flags)
   void (*fun)() = dlsym (h, "entry")
*/

#ifdef __cplusplus
extern "C" {
#endif

      void *dlopen  (const char *filename, int flag);
      int   dlclose (void *handle);

      void *dlsym   (void *handle, const char *name);

const char *dlerror (void);

#ifdef __cplusplus
}
#endif


#endif /* dlfc_forWindows_hpp */
