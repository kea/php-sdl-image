dnl config.m4 for extension sdl_image

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([sdl_image],
dnl   [for sdl_image support],
dnl   [AS_HELP_STRING([--with-sdl_image],
dnl     [Include sdl_image support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([sdl_image],
  [whether to enable sdl_image support],
  [AS_HELP_STRING([--enable-sdl_image],
    [Enable sdl_image support])],
  [no])

if test "$PHP_SDL_IMAGE" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, SDL_IMAGE_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-sdl_image -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/sdl_image.h"  # you most likely want to change this
  dnl if test -r $PHP_SDL_IMAGE/$SEARCH_FOR; then # path given as parameter
  dnl   SDL_IMAGE_DIR=$PHP_SDL_IMAGE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for sdl_image files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SDL_IMAGE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SDL_IMAGE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the sdl_image distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-sdl_image -> add include path
  dnl PHP_ADD_INCLUDE($SDL_IMAGE_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-sdl_image -> check for lib and symbol presence
  dnl LIBNAME=SDL_IMAGE # you may want to change this
  dnl LIBSYMBOL=SDL_IMAGE # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_SDL_IMAGE_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your sdl_image library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SDL_IMAGE_DIR/$PHP_LIBDIR, SDL_IMAGE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SDL_IMAGE_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your sdl_image library.])
  dnl ],[
  dnl   -L$SDL_IMAGE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SDL_IMAGE_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_SDL_IMAGE, 1, [ Have sdl_image support ])

  PHP_NEW_EXTENSION(sdl_image, sdl_image.c, $ext_shared)
fi
