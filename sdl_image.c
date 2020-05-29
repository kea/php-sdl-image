/* sdl_image extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_sdl_image.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void sdl_image_test1()
 */
PHP_FUNCTION(sdl_image_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "sdl_image");
}
/* }}} */

/* {{{ string sdl_image_test2( [ string $var ] )
 */
PHP_FUNCTION(sdl_image_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(sdl_image)
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

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_sdl_image_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_sdl_image_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ sdl_image_functions[]
 */
static const zend_function_entry sdl_image_functions[] = {
	PHP_FE(sdl_image_test1,		arginfo_sdl_image_test1)
	PHP_FE(sdl_image_test2,		arginfo_sdl_image_test2)
	PHP_FE_END
};
/* }}} */

/* {{{ sdl_image_module_entry
 */
zend_module_entry sdl_image_module_entry = {
	STANDARD_MODULE_HEADER,
	"sdl_image",					/* Extension name */
	sdl_image_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(sdl_image),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(sdl_image),			/* PHP_MINFO - Module info */
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
