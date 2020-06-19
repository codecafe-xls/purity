/* purify extension for PHP */

#ifndef PHP_PURIFY_H
# define PHP_PURIFY_H

extern zend_module_entry purify_module_entry;
# define phpext_purify_ptr &purify_module_entry

# define PHP_PURIFY_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PURIFY)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PURIFY_H */
