time (make \
ARCH=arm64 \
SUBARCH=arm64 \
CC=/home/v4lkyr/android/tools/toolchains/proton-clang/bin/clang \
LD=/home/v4lkyr/android/tools/toolchains/proton-clang/bin/ld.lld \
AR=/home/v4lkyr/android/tools/toolchains/proton-clang/bin/llvm-ar \
NM=/home/v4lkyr/android/tools/toolchains/proton-clang/bin/llvm-nm \
OBJCOPY=/home/v4lkyr/android/tools/toolchains/proton-clang/bin/llvm-objcopy \
OBJDUMP=/home/v4lkyr/android/tools/toolchains/proton-clang/bin/llvm-objdump \
STRIP=/home/v4lkyr/android/tools/toolchains/proton-clang/bin/llvm-strip \
CROSS_COMPILE=/home/v4lkyr/android/tools/toolchains/arm-gcc/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu- \
$1 $2)
