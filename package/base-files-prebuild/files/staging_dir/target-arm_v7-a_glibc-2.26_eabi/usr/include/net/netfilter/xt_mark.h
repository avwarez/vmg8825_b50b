#ifndef _XT_MARK_H
#define _XT_MARK_H

#include <linux/types.h>

#if 1 /* ZyXEL QoS, John */
/* Version 1 */
struct xt_mark_tginfo2 {
        __u32 mark, mask;
        __u8 mode;
};
#else
struct xt_mark_tginfo2 {
	__u32 mark, mask;
};
#endif

struct xt_mark_mtinfo1 {
	__u32 mark, mask;
	__u8 invert;
};

#endif /*_XT_MARK_H*/
