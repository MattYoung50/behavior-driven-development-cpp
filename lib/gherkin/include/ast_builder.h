#ifndef GHERKIN_AST_BUILDER_H_
#define GHERKIN_AST_BUILDER_H_

#include "gherkin-c-port.h"
#include "builder.h"
#include "gherkin_document.h"

#ifdef __cplusplus
extern "C" {
#endif

GHERKIN_C_API_ Builder* AstBuilder_new();

GHERKIN_C_API_ void AstBuilder_delete(Builder* builder);

GHERKIN_C_API_ const GherkinDocument* AstBuilder_get_result(Builder* builder);

#ifdef __cplusplus
}
#endif

#endif /* GHERKIN_AST_BUILDER_H_ */
