/* sdl_image extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php_sdl_image.h"

extern DECLSPEC SDL_Texture * SDLCALL IMG_LoadTexture(SDL_Renderer *renderer, const char *file);
extern DECLSPEC SDL_Surface * SDLCALL IMG_Load(const char *file);
#define SDL_RENDERER_RES_NAME "SDL Renderer"
extern int le_sdl_renderer;
extern int le_sdl_texture;
extern zend_bool sdl_surface_to_zval(SDL_Surface *surface, zval *z_val);

/* {{{ proto SDL_Texture IMG_LoadTexture(string file)

	PHP note: stream are supported

 *  Load a texture from a file.
 extern DECLSPEC SDL_Texture * SDLCALL IMG_LoadTexture(SDL_Renderer *renderer, const char *file);
 */
PHP_FUNCTION(IMG_LoadTexture)
{
    zend_string *file;
	SDL_Texture *texture = NULL;

	zval *z_renderer = NULL;
	SDL_Renderer *renderer = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(z_renderer)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();

    renderer = (SDL_Renderer*)zend_fetch_resource(Z_RES_P(z_renderer), SDL_RENDERER_RES_NAME, le_sdl_renderer);
	texture = IMG_LoadTexture(renderer, ZSTR_VAL(file));

	if (!texture) {
		RETURN_NULL();
	}

	RETURN_RES(zend_register_resource(texture, le_sdl_texture));
}
/* }}} */

PHP_FUNCTION(IMG_Load)
{
	zend_string *file;
	SDL_Surface *surface = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();

	surface = IMG_Load(ZSTR_VAL(file));

	if (!surface) {
		RETURN_NULL();
	}

	sdl_surface_to_zval(surface, return_value);
}

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(sdl_image)
{
#if defined(ZTS) && defined(COMPILE_DL_SDL_IMAGE)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(sdl_image)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "sdl_image support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ sdl_image_module_entry
 */
zend_module_entry sdl_image_module_entry = {
	STANDARD_MODULE_HEADER,
	"SDL_image",				/* Extension name */
	ext_functions,				/* zend_function_entry */
	PHP_MINIT(sdl_image),		/* PHP_MINIT - Module initialization */
	NULL,						/* PHP_MSHUTDOWN - Module shutdown */
	NULL,						/* PHP_RINIT - Request initialization */
	NULL,						/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(sdl_image),		/* PHP_MINFO - Module info */
	PHP_SDL_IMAGE_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SDL_IMAGE
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(sdl_image)
#endif
