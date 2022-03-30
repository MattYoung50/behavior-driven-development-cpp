#ifndef GHERKIN_FILE_READER_H_
#define GHERKIN_FILE_READER_H_

#include <wchar.h>

#include "gherkin-c-port.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FileReader FileReader;

GHERKIN_C_API_ FileReader* FileReader_new(const char* const file_name);

GHERKIN_C_API_ const wchar_t* FileReader_read(FileReader* file_reader);

GHERKIN_C_API_ void FileReader_delete(FileReader* file_reader);

#ifdef __cplusplus
}
#endif

#endif /* GHERKIN_FILE_READER_H_ */
