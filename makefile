CC             := g++
CFLAGS         := -std=c++11 -Wall
CPP_LIBS       := -pthread

#File Structure
SRC = src
TEST = test
BIN = bin
OBJ = obj
TEST_OBJ = obj

#Include Dirs
INC_CALCULATOR = src
INC_GTEST = /usr/local/include
INCLUDES = -I$(INC_CALCULATOR) -I$(INC_GTEST)

TARGET = $(BIN)

GTEST_LIBS = -L/usr/local/lib64 -l:libgmock.a -l:libgtest.a -l:libgtest_main.a

BUILD_CMD = g++ $(OBJS) $(CPP_LIBS) -o $(TARGET)/helloworld $(RPATH)
BUILD_TEST = g++ $(CPP_LIBS) $(ALL_OBJS_EXCLUDING_MAIN) $(TEST_OBJS) -o $(TARGET)/runtests $(GTEST_LIBS)

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