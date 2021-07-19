#
# source code makefile
#
EXE = $(PKG_NAME)-zcfgd
OBJS = snmp_zcfg_init.o snmp_zcfg_reload.o

LIBS = -lzcfg_fe_rdm_string -lzcfg_fe_rdm_struct -lzcfg_msg -lzcfg_fe_rdm_access -lzyutil -lzyee_zcfg_service -lzyee_msg

all: build

build: $(EXE)

.c.o:
	$(CC) -Wall -Werror -fPIC -c $< -o $@ $(CFLAGS) -DZYXEL_MODSW_ZYEE -DPKG_NAME="\"$(PKG_NAME)\""

$(EXE): $(OBJS)
	$(CC) -o $@ $(OBJS) -Wl,-rpath, $(LIBS)

clean:
	rm -rf *.o
	rm -rf $(EXE)
