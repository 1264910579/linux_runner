

CPPFLAGS += -I inc/

LDFLAGS  += -L lib/
LDFLAGS  += -lx

main:main.c
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS)

install:
	$(MAKE) -C lib/


clean:
	@$(RM) main
	$(MAKE) -C lib/ clean

distclean:clean
	$(MAKE) -C lib/ distclean


# 声明伪目标
.PHONY:clean install distclean