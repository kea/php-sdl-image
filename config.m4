dnl config.m4 for extension sdl_image

PHP_ARG_ENABLE([sdl_image],
    [whether to enable sdl_image support],
    [AS_HELP_STRING([--enable-sdl_image],
        [Enable sdl_image support])],
    [no])

if test "$PHP_SDL_IMAGE" != "no"; then
    AC_DEFINE(WITH_SDL_IMAGE, 1, [Whether you want SDL Image])
    AC_MSG_CHECKING([for SDL_image.h])
    for i in $PHP_SDL_IMAGE /usr/local /usr; do
      if test -r $i/include/SDL2/SDL_image.h; then
        SDL_IMAGE_DIR=$i
        AC_DEFINE(HAVE_SDL_IMAGE_H, 1, [Whether you have SDL2/SDL_image.h])
        PHP_ADD_INCLUDE($i/include)
      fi
    done

    if test -z "$SDL_IMAGE_DIR"; then
      AC_MSG_RESULT([not found])
      AC_MSG_ERROR([Please reinstall the SDL_image distribution including development files])
    else
      AC_MSG_RESULT([found])
    fi

    AC_CHECK_LIB(SDL2_image, IMG_Load, [
      PHP_ADD_LIBRARY(SDL_image,, SDL2_IMAGE_SHARED_LIBADD)
    ], [
      AC_MSG_ERROR([libSDL2_image not found!])
    ])

  AC_DEFINE(HAVE_SDL_IMAGE, 1, [ Have sdl_image support ])

  PHP_SUBST(SDL2_IMAGE_SHARED_LIBADD)
  PHP_NEW_EXTENSION(sdl_image, php_sdl_image.c, $ext_shared)
fi
