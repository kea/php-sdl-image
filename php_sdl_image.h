/* sdl_image extension for PHP */

#ifndef PHP_SDL_IMAGE_H
# define PHP_SDL_IMAGE_H

#define PHP_SDL_IMAGE_VERSION "0.4.0"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "php.h"
#include "ext/standard/info.h"

# include <SAPI.h>
# include <Zend/zend_extensions.h>

extern zend_module_entry sdl_image_module_entry;
#define phpext_sdl_image_ptr &sdl_image_module_entry

#include "php_sdl_image_arginfo.h"

PHP_FUNCTION(IMG_LoadTexture);
PHP_FUNCTION(IMG_Load);

PHP_MINIT_FUNCTION(sdl_image);

# if defined(ZTS) && defined(COMPILE_DL_SDL_IMAGE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_SDL_IMAGE_H */
