/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 2beef1dccbd6b0db8dfca04c0c7e441c81fe233a */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_IMG_LoadTexture, 0, 2, SDL_Texture, 0)
	ZEND_ARG_INFO(0, renderer)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_IMG_Load, 0, 1, SDL_Surface, 1)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(IMG_LoadTexture);
ZEND_FUNCTION(IMG_Load);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(IMG_LoadTexture, arginfo_IMG_LoadTexture)
	ZEND_FE(IMG_Load, arginfo_IMG_Load)
	ZEND_FE_END
};
