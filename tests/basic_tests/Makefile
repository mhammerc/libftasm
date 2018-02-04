C_FLAGS := -Wall -Werror -Wextra -g
CC := gcc
RM := rm
LINKFLAGS := -L../.. -lfts -lcheck -lm -lpthread -lrt -lcheck_pic -lsubunit

.PHONY: $(TARGET)
.PHONY: clean

# Path for .c , .h and .o Files
SRC_PATH := ./
OBJ_PATH := ./obj/
INC_PATH :=

# Executable Name
TARGET := ../basic

# Files to compile
OBJ1 :=\
	main.o \

OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	@echo [CC] $<
	@$(CC) $(FLAGS) -o $@ -c $< $(INC_PATH)

# Build final Binary
$(TARGET): $(OBJ)
	@echo [INFO] Creating Binary Executable [$(TARGET)]
	@$(CC) -o $@ $^ $(LINKFLAGS)

# Clean all the object files and the binary
clean:
	@echo "[Cleaning objects]"
	@$(RM) -rfv $(OBJ_PATH)

fclean:
	@echo "[Cleaning objects and binary]"
	@$(RM) -rfv $(OBJ_PATH)
	@$(RM) -rfv $(TARGET)

all: $(TARGET)

re: fclean all
