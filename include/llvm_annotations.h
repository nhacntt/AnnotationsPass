#ifndef LLVM_ANNOTATIONS_H
#define LLVM_ANNOTATIONS_H

//#define __In "__In"
//#define __Out "__Out"

#define __In_Buf __attribute__((annotate("IN_BUF")))
#define __Out_Buf __attribute__((annotate("OUT_BUF")))

#define __In_Fd __attribute__((annotate("IN_FD")))
#define __Out_Fd __attribute__((annotate("OUT_FD")))

#endif /* LLVM_ANNOTATIONS_H */
