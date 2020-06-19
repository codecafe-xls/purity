/* purify extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_purify.h"
#include "purify_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void test1()
 */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "purify");
}
/* }}} */

/* {{{ string test2( [ string $var ] )
 */
PHP_FUNCTION(test2)
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

PHP_FUNCTION(purify){
	zend_string  *source;

	if(zend_parse_parameters(ZEND_NUM_ARGS(),"S",&source) == FAILURE){
		RETURN_FALSE;
	}

	RETURN_STR(s);
}

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(purify)
{
#if defined(ZTS) && defined(COMPILE_DL_PURIFY)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(purify)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "purify support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ purify_module_entry
 */
zend_module_entry purify_module_entry = {
	STANDARD_MODULE_HEADER,
	"purify",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(purify),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(purify),			/* PHP_MINFO - Module info */
	PHP_PURIFY_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PURIFY
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(purify)
#endif
