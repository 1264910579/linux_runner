define commands
	echo "thank you!"
	echo "you are welcome."
endef

all:
	$(commands)

# OBJ = a.c b.o c.txt d.c

# REL = $(OBJ:%.c=%.o)
# SRC = $(filter %.c, $(OBJ))

# B := I love China 
# C := $(A) tree
# D ?= dog
# D ?= ddd

# all:
# 	@echo $(REL)
# 	@echo $(SRC)
# 	@echo $(B)
# 	@echo $(C)
# 	@echo $(D)
# 	$(MAKE) -C ./subdir

# A := apple 


# CPPFLAGS += -I xxx/

# LDFLAGS += -L xxx/
# LDFLAGS += -lx



# 一套规则
#

# 终极目标
#
# SRC := $(wildcard *.c) # 自动查找当前目录下的所有 .c 文件

# # 剔除1-1.c 和 a.c
# SRC := $(filter-out a.c, $(SRC))
# SRC := $(filter-out 1-1.c, $(SRC))

# BIN = $(SRC:%.c=%)    # 将 SRC 中的所有 .c 去掉后缀


# all:$(BIN) 1-1 x

# 1-1:1-1.c a.c
# 	$(CC) $^ -o $@ -lm -lpthread

# # 静态模式，用来生成多套规则的目标依赖列表
# $(BIN):%  :  %.c
# 	$(CC) $^ -o $@

# # a:a.c
# # 	$(CC) $^ -o $@
# # 1-3:1-3.c
# # 	$(CC) $^ -o $@
# # 1-1:1-1.c
# # 	$(CC) $^ -o $@
# # 1-2:1-2.c
# # 	$(CC) $^ -o $@

# clean:
# 	$(RM) 1-1 $(BIN)
