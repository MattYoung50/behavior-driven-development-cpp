#ifndef GHERKIN_TOKEN_SCANNER_H_
#define GHERKIN_TOKEN_SCANNER_H_

#include <wchar.h>

#include "gherkin-c-port.h"
#include "token.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TokenScanner TokenScanner;

typedef Token* (*read_function) (TokenScanner*);

typedef void (*delete_function) (TokenScanner*);

struct TokenScanner {
    read_function read;
    delete_function del;
};

GHERKIN_C_API_ void TokenScanner_delete(TokenScanner* token_scanner);

#ifdef __cplusplus
}
#endif

#endif /* GHERKIN_TOKEN_SCANNER_H_ */
