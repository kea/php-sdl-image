dnl config.m4 for extension sdl_image

PHP_ARG_WITH([sdl_image],
  [whether to enable sdl_image support],
  [AS_HELP_STRING([[--with-sdl_image[=DIR]]],
    [Include SDL_image support. DIR is the SDL_image base include and lib directory])])

if test "$PHP_SDL_IMAGE" != "no"; then
  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/include/SDL2/SDL_image.h"
  AC_MSG_CHECKING([for SDL_image files])
  if test -r $PHP_SDL_IMAGE/$SEARCH_FOR; then # path given as parameter
    SDL_IMAGE_DIR=$PHP_SDL_IMAGE
  else # search default path list
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        SDL_IMAGE_DIR=$i
      fi
    done
  fi

  if test -z "$SDL_IMAGE_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the SDL_image distribution])
  fi

  PHP_ADD_INCLUDE($SDL_IMAGE_DIR/include)
  AC_MSG_RESULT(found in $SDL_IMAGE_DIR)

  PKG_CHECK_MODULES([_SDL2], [sdl2 < 3.0])
  PHP_EVAL_INCLINE($_SDL2_CFLAGS)

  LIBNAME=SDL2_image
  LIBSYMBOL=IMG_Load
  AC_CHECK_LIB($LIBNAME, $LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SDL_IMAGE_DIR/$PHP_LIBDIR, SDL_IMAGE_SHARED_LIBADD)
    AC_DEFINE(HAVE_SDL_IMAGE_FEATURE, 1, [ ])
  ],[
    AC_MSG_ERROR([$LIBNAME not found! Libs: $_SDL2_LIBS])
  ],[
    -L$SDL_IMAGE_DIR/$PHP_LIBDIR $_SDL2_LIBS
  ])

  PHP_SUBST(SDL_IMAGE_SHARED_LIBADD)

  AC_DEFINE(HAVE_SDL_IMAGE, 1, [ Have sdl_image support ])

  PHP_SUBST(SDL_IMAGE_SHARED_LIBADD)
  PHP_NEW_EXTENSION(sdl_image, php_sdl_image.c, $ext_shared)
  PHP_ADD_EXTENSION_DEP(sdl_image, sdl)
fi
