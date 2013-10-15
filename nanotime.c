#include "php_nanotime.h"
#include "nanotime/nanotime.h"

#if HAVE_NANOTIME

ZEND_BEGIN_ARG_INFO(arginfo_nanotime_time, 0)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO(arginfo_nanotime_second, 0)
ZEND_END_ARG_INFO()

static const zend_function_entry nanotime_functions[] = {
	ZEND_NS_FENTRY("nano", second,	ZEND_FN(nanotime_second), arginfo_nanotime_second, 0)
	ZEND_NS_FENTRY("nano", time,	ZEND_FN(nanotime_time), arginfo_nanotime_time, 0)
	{ NULL, NULL, NULL }
};

zend_module_entry nanotime_module_entry = {
	STANDARD_MODULE_HEADER,
	"nanotime",
	nanotime_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_MINFO(nanotime),
	PHP_NANOTIME_VERSION, 
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_NANOTIME
ZEND_GET_MODULE(nanotime)
#endif

PHP_MINFO_FUNCTION(nanotime)
{
	php_printf("The nanoetime extension\n");
	php_info_print_table_start();
	php_info_print_table_row(2, "Version", PHP_NANOTIME_VERSION);
	php_info_print_table_end();
}

PHP_FUNCTION(nanotime_second)
{
	unsigned long ts;

	if (zend_parse_parameters_none()) {
		RETURN_NULL();
	}

	if (NANO_UNEXPECTED(nano_second(&ts))) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Could not retrieve current system nanosecond");
		RETURN_NULL();
	}

	RETURN_LONG(ts);
}

PHP_FUNCTION(nanotime_time)
{
	long double ts;

	if (zend_parse_parameters_none()) {
		RETURN_NULL();
	}

	if (NANO_UNEXPECTED(nano_time(&ts))) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Could not retrieve current system nanosecond");
		RETURN_NULL();
	}

	RETURN_DOUBLE(ts);
}

#endif /* HAVE_NANOTIME */
