#ifndef LLVM_ANNOTATIONS_H
#define LLVM_ANNOTATIONS_H

#define __Anno1  __attribute__((annotate("__Anno1")))
#define __Anno2  __attribute__((annotate("__Anno2")))
#define __Anno3  __attribute__((annotate("__Anno3")))
#define __Anno4  __attribute__((annotate("__Anno4")))
#define __Anno5  __attribute__((annotate("__Anno5")))


#define __df(i,o) __attribute__((annotate(#i "_" #o)))

#endif /* LLVM_ANNOTATIONS_H */


