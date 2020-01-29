# By default, build the EMON portions of the driver
ccflags-y += -DEMON -DEMON_INTERNAL -DDRV_ANDROID -DDRV_ATOM_ONLY -DPCI_HELPERS_API

obj-$(CONFIG_INTEL_SOCWATCH_PERF_DRV) +=	\
		control.o	\
		pci.o	\
		socperfdrv.o	\
		soc_uncore.o
