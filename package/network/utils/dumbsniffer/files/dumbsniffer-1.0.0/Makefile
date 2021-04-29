.PHONY: all clean

TARGETS:=dumbsniffer
CFLAGS += --std=c99 -Wall -ggdb -O2 -lnl

USRINC:= -I $(USRLIBDIR) -I $(USRLIBDIR)/libnl -I $(USRLIBDIR)/libnfnetlink
USRLIB:= -L $(USRLIBDIR) -lnl-nf -lnl

all: $(TARGETS)

dumbsniffer: dumbsniffer.c
	$(CC) $(CFLAGS) $^ $(USRINC) $(USRLIB) -o $@

clone:
	echo Building directories...
	mkdir -pv $(PKG_BUILD_DIR)
	ls -al 
	cp -rf . $(PKG_BUILD_DIR)

clean:
	rm -f $(TARGETS)
