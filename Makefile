.PHONY: all clean

BUILD_DIR = ./build
SRC_DIR = ./src
COMPILER = g++
FLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr


DIRS = calculate input output structs test utils flag

BUILD_DIRS = $(DIRS:%=$(BUILD_DIR)/%)


SOURCES_LIST = main.cpp calculate/calculate.cpp input/input.cpp \
			   output/output.cpp test/test.cpp flag/flag.cpp

SOURCES_REL_PATH = $(SOURCES_LIST:%=$(SRC_DIR)/%)
OBJECTS_REL_PATH = $(SOURCES_LIST:%.cpp=$(BUILD_DIR)/%.o)
DEPS_REL_PATH = $(OBJECTS_REL_PATH:%.o=%.d)


all: build start

build: quadratka.out

start:
	./quadratka.out


quadratka.out: $(OBJECTS_REL_PATH)
	$(COMPILER) -o $@ $^

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp | $(BUILD_DIRS)
	$(COMPILER) $< -c -MMD -o $@

-include $(DEPS_REL_PATH)

$(BUILD_DIRS):
	mkdir $@


clean_all: clean_log clean_obj clean_deps

clean: clean_obj clean_deps clean_out

clean_log:
	rm -rf ./log/*.log

clean_out:
	rm -rf ./*.out

clean_obj:
	rm -rf ./$(OBJECTS_REL_PATH)

clean_deps:
	rm -rf ./$(DEPS_REL_PATH)