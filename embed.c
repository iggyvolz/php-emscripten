/* embed_sapi_basic_example.c */

#include <sapi/embed/php_embed.h>

int run_php(char* string)
{
	int success;
	PHP_EMBED_START_BLOCK(0, NULL)
	
	success = zend_eval_string(string, NULL, "Simple Hello World App");
	printf("\n");
	PHP_EMBED_END_BLOCK()
	return success;
}