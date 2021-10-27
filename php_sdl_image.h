/* sdl_image extension for PHP */

#ifndef PHP_SDL_IMAGE_H
# define PHP_SDL_IMAGE_H

#define PHP_SDL_IMAGE_VERSION "0.1.0"

#include <SDL2/SDL.h>
#include "php.h"
#include "ext/standard/info.h"

# include <SAPI.h>
# include <Zend/zend_extensions.h>

extern zend_module_entry sdl_image_module_entry;
#define phpext_sdl_image_ptr &sdl_image_module_entry

ZEND_BEGIN_ARG_INFO_EX(arginfo_IMG_LoadTexture, 0, 0, 2)
      ZEND_ARG_INFO(0, renderer)
      ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

PHP_FUNCTION(IMG_LoadTexture);

ZEND_BEGIN_ARG_INFO_EX(arginfo_IMG_Load, 0, 0, 1)
      ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

PHP_FUNCTION(IMG_Load);

PHP_MINIT_FUNCTION(sdl_image);

# if defined(ZTS) && defined(COMPILE_DL_SDL_IMAGE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_SDL_IMAGE_H */
