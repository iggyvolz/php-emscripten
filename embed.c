/* embed_sapi_basic_example.c */

#include <sapi/embed/php_embed.h>
#include <emscripten.h>

static size_t embed_ub_write(const char* str, size_t str_length)
{
	EM_ASM({
		console.log($0, $1);
		stdoutCallback(HEAP8.slice($0, $0 + $1));
	}, str, str_length);
	return str_length;
}
void printhi(char* string)
{
	EM_ASM({
		console.log({start: $0, len: $1, str: UTF8ToString($0, $1)});
	}, string, strlen(string));
}

int run_php(char* string)
{
	int success;
	php_embed_module.ub_write = embed_ub_write;
	PHP_EMBED_START_BLOCK(0, NULL)
	printf("%s\n", string);
	printhi(string);
	success = zend_eval_string(string, NULL, "Simple Hello World App");
	PHP_EMBED_END_BLOCK()
	return success;
}