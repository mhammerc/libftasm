FLAGS := -f elf64
CC := nasm
RM := rm
LINKFLAGS := rc

ARCHIVER := ar
#LINKFLAGS := -lanylibrary

.PHONY: $(TARGET)
.PHONY: clean

VPATH := ./src/ ./obj/ ./include/

# Path for .c , .h and .o Files
SRC_PATH := ./src/
OBJ_PATH := ./obj/
INC_PATH :=

# Executable Name
TARGET := libftasm.a

# Files to compile
OBJ1 :=\
	ft_bzero.o\
	ft_strcat.o\
	ft_isalpha.o

OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.s
	@mkdir -p obj
	@echo [NASM] $<
	@$(CC) $(FLAGS) -o $@ $< $(INC_PATH)

# Build final Binary
$(TARGET): $(OBJ)
	@echo [INFO] Creating Binary Archive [$(TARGET)]
	@$(ARCHIVER) $(LINKFLAGS) $@ $^

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