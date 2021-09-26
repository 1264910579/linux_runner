
# 自动找到所有的.c

SRC = $(wildcard *.c) # 1.c a.c b.c
BIN = $(SRC:%.c=%)    # 1   a   b  

all:$(BIN)

$(BIN):%:%.c
	$(CC) $^ -o $@

clean:
	@$(RM) $(BIN)