#ifndef SUPPORT_PUP_H
#define SUPPORT_PUP_H

#include "library_base.h"

ULONG InitDispatch(struct PrivateBase *PrivateBase, ULONG MsgType);
void RemoveDispatch(struct PrivateBase *PrivateBase, ULONG MsgType);
ULONG InitSupport(struct PrivateBase *PrivateBase);
void RemoveSupport(struct PrivateBase *PrivateBase);

#endif
