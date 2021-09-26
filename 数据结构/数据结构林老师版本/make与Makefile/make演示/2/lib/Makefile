
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)

libx.so:$(OBJ)
	$(CC) -shared -fPIC -o $@ $^

# $(OBJ):%.o:%.c
# 	$(CC) $^ -o $@ -c -fPIC

clean:
	@$(RM) $(OBJ)

distclean:clean
	@$(RM) libx.so