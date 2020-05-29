/* sdl_image extension for PHP */

#ifndef PHP_SDL_IMAGE_H
# define PHP_SDL_IMAGE_H

extern zend_module_entry sdl_image_module_entry;
# define phpext_sdl_image_ptr &sdl_image_module_entry

# define PHP_SDL_IMAGE_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_SDL_IMAGE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_SDL_IMAGE_H */
