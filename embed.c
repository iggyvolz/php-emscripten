/* embed_sapi_basic_example.c */

#include <sapi/embed/php_embed.h>

// void dump(zval *zv_ptr)
// {
// try_again:
//     switch (Z_TYPE_P(zv_ptr)) {
//         case IS_NULL:
//             php_printf("NULL: null\n");
//             break;
//         case IS_TRUE:
//             php_printf("BOOL: true\n");
//             break;
//         case IS_FALSE:
//             php_printf("BOOL: false\n");
//             break;
//         case IS_LONG:
//             php_printf("LONG: %ld\n", Z_LVAL_P(zv_ptr));
//             break;
//         case IS_DOUBLE:
//             php_printf("DOUBLE: %g\n", Z_DVAL_P(zv_ptr));
//             break;
//         case IS_STRING:
//             php_printf("STRING: value=\"");
//             PHPWRITE(Z_STRVAL_P(zv_ptr), Z_STRLEN_P(zv_ptr));
//             php_printf("\", length=%zd\n", Z_STRLEN_P(zv_ptr));
//             break;
//         case IS_RESOURCE:
//             php_printf("RESOURCE: id=%d\n", Z_RES_HANDLE_P(zv_ptr));
//             break;
//         case IS_ARRAY:
//             php_printf("ARRAY: hashtable=%p\n", Z_ARRVAL_P(zv_ptr));
//             break;
//         case IS_OBJECT:
//             php_printf("OBJECT: object=%p\n", Z_OBJ_P(zv_ptr));
//             break;
//         case IS_REFERENCE:
//             // For references, remove the reference wrapper and try again.
//             // Yes, you are allowed to use goto for this purpose!
//             php_printf("REFERENCE: ");
//             zv_ptr = Z_REFVAL_P(zv_ptr);
//             goto try_again;
// 		default:
//             php_printf("UNKNOWN %d\n", Z_TYPE_P(zv_ptr));
//             break;
//     }
// }

// int main(int argc, char **argv)
// {
// 	/* Invokes the Zend Engine initialization phase: SAPI (SINIT), modules
// 	 * (MINIT), and request (RINIT). It also opens a 'zend_try' block to catch
// 	 * a zend_bailout().
// 	 */
// 	PHP_EMBED_START_BLOCK(argc, argv)

// 	// php_printf(
// 	// 	"Number of functions loaded: %d\n",
// 	// 	zend_hash_num_elements(EG(function_table))
// 	// );

	

// 	zval retval;
// 	zval* zv_ptr = &retval;
// 	ZVAL_STRING(&retval, "foo");
// 	dump(zv_ptr);
// 	// ZVAL_NULL(&retval);
// 	// int success = zend_eval_stringl(ZEND_STRL("eval('echo \\'foo\n\\';');"), &retval, "example");
// 	int success = zend_eval_string("return 4;", &retval,
// 		"Simple Hello World App");


// 	dump(zv_ptr);
// 	// zval ret;
// 	printf("success: %d\n", success);
// 	// int success = zend_eval_stringl("echo 'foo\n';", NULL, "example");

	
// 	// printf("%d\n", success);
// 	// printf("%s\n", ret.value);
// 	/* Close the 'zend_try' block and invoke the shutdown phase: request
// 	 * (RSHUTDOWN), modules (MSHUTDOWN), and SAPI (SSHUTDOWN).
// 	 */
// 	PHP_EMBED_END_BLOCK()
// }

int run_php(char* string)
{
	int success;
	PHP_EMBED_START_BLOCK(0, NULL)
	
	success = zend_eval_string(string, NULL, "Simple Hello World App");
	printf("\n");
	PHP_EMBED_END_BLOCK()
	return success;
}