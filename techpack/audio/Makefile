TECHPACK_PROFILE ?= whyred
CONFIG_TECHPACK_PROFILE = $(TECHPACK_PROFILE)

include $(srctree)/techpack/audio/config/$(patsubst "%",%,$(CONFIG_TECHPACK_PROFILE)).conf
export

# Use USERINCLUDE when you must reference the UAPI directories only.
USERINCLUDE     += \
                -I$(srctree)/techpack/audio/include/uapi \
                -I$(srctree)/techpack/audio/include

# Use LINUXINCLUDE when you must reference the include/ directory.
# Needed to be compatible with the O= option
LINUXINCLUDE    += \
                -I$(srctree)/techpack/audio/include/uapi \
                -I$(srctree)/techpack/audio/include \
                -include $(srctree)/techpack/audio/config/$(patsubst "%",%,$(CONFIG_TECHPACK_PROFILE))conf.h

obj-y += soc/
obj-y += dsp/
obj-y += ipc/
obj-y += asoc/
