#ifndef GHERKIN_PARSER_H_
#define GHERKIN_PARSER_H_

#include "gherkin-c-port.h"
#include "builder.h"
#include "error.h"
#include "token_matcher.h"
#include "token_scanner.h"
#include <stdbool.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Parser Parser;

GHERKIN_C_API_ Parser* Parser_new(Builder* builder);

GHERKIN_C_API_ void Parser_delete(Parser* parser);

GHERKIN_C_API_ int Parser_parse(Parser* parser, TokenMatcher* token_matcher, TokenScanner* token_scanner);

GHERKIN_C_API_ bool Parser_has_more_errors(Parser* parser);

GHERKIN_C_API_ Error* Parser_next_error(Parser* parser);

#ifdef __cplusplus
}
#endif

#endif /* GHERKIN_PARSER_H_ */
