dnl config.m4 for extension sdl_image

dnl If your extension references something external, use 'with':

PHP_ARG_ENABLE([sdl_image],
  [whether to enable sdl_image support],
  [AS_HELP_STRING([--enable-sdl_image],
    [Enable sdl_image support])],
  [no])

if test "$PHP_SDL_IMAGE" != "no"; then
  PKG_CHECK_MODULES([LIBSDL_IMAGE], [SDL2_image >= 2.0])
  PHP_EVAL_INCLINE($LIBSDL_IMAGE_CFLAGS)
  PHP_EVAL_LIBLINE($LIBSDL_IMAGE_LIBS, SDL_IMAGE_SHARED_LIBADD)

  AC_DEFINE(HAVE_SDL_IMAGE, 1, [ Have sdl_image support ])

  PHP_SUBST(SDL_IMAGE_SHARED_LIBADD)
  PHP_NEW_EXTENSION(sdl_image, php_sdl_image.c, $ext_shared)
fi
