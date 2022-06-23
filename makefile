CC             := g++
CFLAGS         := -std=c++17 -Wall -Wextra -g
CPP_LIBS       := -pthread

#File Structure
SRC = src
TEST = test
BIN = bin
OBJ = obj
TEST_OBJ = obj

#Include Dirs
INC_CALCULATOR = src
INC_GTEST = lib/gtest/include
INC_GUNIT = lib/gunit/include
INC_GHERKIN = lib/gherkin/include
INC_GHERKIN_CPP = lib/gherkin-cpp/include
INC_FMEM = lib/fmem/include
INC_JSON = lib/json/include -Ilib/json/include/nlohmann
INCLUDES = -I$(INC_CALCULATOR) -I$(INC_GTEST) -I$(INC_GUNIT) -I$(INC_GHERKIN) -I$(INC_GHERKIN_CPP) -I$(INC_FMEM) -I$(INC_JSON)

TARGET = $(BIN)

GTEST_LIBS = -Llib/gtest/lib -l:libgmock.a -l:libgtest.a -l:libgtest_main.a
GHERKIN_LIBS = -Llib/gherkin/lib -l:libgherkin.a
GHERKIN_CPP_LIBS = -Llib/gherkin-cpp/lib -l:libgherkin-cpp.a
FMEM_LIBS = -Llib/fmem/lib -l:libfmem.a

BUILD_CMD = g++ $(OBJS) $(CPP_LIBS) -o $(TARGET)/helloworld $(RPATH)
BUILD_TEST = g++ $(CFLAGS) $(CPP_LIBS) $(ALL_OBJS_EXCLUDING_MAIN) $(TEST_OBJS) -o $(TARGET)/runtests $(FMEM_LIBS) $(GHERKIN_LIBS) $(GHERKIN_CPP_LIBS) $(GTEST_LIBS) 

#Output and dependencies
SRCS_EXCLUDING_MAIN = $(shell find $(SRC) -name *.cpp -not -name main.cpp)
ALL_OBJS_EXCLUDING_MAIN := $(subst $(SRC)/,$(OBJ)/,$(addsuffix .o,$(basename $(SRCS_EXCLUDING_MAIN))))
SRCS = $(shell find $(SRC) -name *.cpp)
OBJS := $(subst $(SRC)/,$(OBJ)/,$(addsuffix .o,$(basename $(SRCS))))
TEST_SRCS = $(shell find $(TEST) -name *.cpp)
TEST_OBJS := $(subst $(TEST)/,$(TEST_OBJ)/,$(addsuffix .o,$(basename $(TEST_SRCS))))
RPATH := -Wl,-rpath=$(BIN)

.PHONY: clean test

build: $(OBJS)
	@echo "Building nlak executable"
	@mkdir -p $(BIN)
	@echo $(BUILD_CMD)
	@$(BUILD_CMD)

rebuild: clean build
	@echo "Rebuilt executable"

run: build
	@echo "Executing..."
	@./bin/helloworld

runtests: test
	@echo "Executing..."
	@./bin/runtests

test: $(ALL_OBJS_EXCLUDING_MAIN) $(TEST_OBJS)
	@echo "Building tests"
	@mkdir -p $(BIN)
	@echo $(BUILD_TEST)
	@$(BUILD_TEST)

all: rebuild run

clean:
	@echo "Cleaning..."
	@rm -rf bin
	@rm -rf obj

$(OBJ)/%.o:$(SRC)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(TEST_OBJ)/%.o:$(TEST)/%.cpp
	@mkdir -p $(dir $@)
	@echo $(TEST_OBJ)
	@echo "$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<" 
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $< 