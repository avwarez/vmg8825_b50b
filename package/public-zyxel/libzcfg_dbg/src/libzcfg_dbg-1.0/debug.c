#include <stdio.h>
#include "be_module_debug.h"

int
main ( int argc, char *argv[])
{
	zcfg_dbg_module_list_t *dbg_p = &zcfg_dbg_module_list[0];
	printf("%s: dbg_p=%p, module=%s, %d\n",__FUNCTION__,dbg_p, dbg_p->module, sizeof(zcfg_dbg_module_list_t));
	while ( dbg_p->module != NULL ) {
		printf("%s: dbg_p=%p, module=%s\n",__FUNCTION__,dbg_p, dbg_p->module);
		dbg_p++;
	}
}