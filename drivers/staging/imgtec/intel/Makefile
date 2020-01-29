obj-$(CONFIG_DRM_INTEL_MID) += drm_intel_mid.o

ccflags-y += \
 -include $(srctree)/drivers/staging/imgtec/config_kernel.h \
 -I$(srctree)/$(src) \
 -I$(srctree)/$(src)/display/tng/drv \
 -I$(srctree)/$(src)/display/tng/drv/ospm \
 -I$(srctree)/$(src)/display/tng/interface \
 -I$(srctree)/$(src)/graphics/rgx/services/3rdparty/intel_devfreq \
 -I$(srctree)/$(src)/graphics/rgx/services/3rdparty/intel_drm \
 -I$(srctree)/$(src)/interface \
 -I$(srctree)/$(src)/otm_hdmi/ipil/common \
 -I$(srctree)/$(src)/otm_hdmi/ipil/include \
 -I$(srctree)/$(src)/otm_hdmi/ipil/specific/include \
 -I$(srctree)/$(src)/otm_hdmi/ipil/specific/mfld \
 -I$(srctree)/$(src)/otm_hdmi/os/android/include \
 -I$(srctree)/$(src)/otm_hdmi/pil/common \
 -I$(srctree)/$(src)/otm_hdmi/pil/include \
 -I$(srctree)/$(src)/otm_hdmi/pil/specific/include \
 -I$(srctree)/$(src)/video/common \
 -I$(srctree)/$(src)/video/decode \
 -I$(srctree)/$(src)/video/encode \
 -I$(srctree)/$(src)/video/vsp \
 -I$(srctree)/drivers/staging/imgtec \
 -I$(srctree)/drivers/staging/imgtec/rogue \
 -I$(srctree)/drivers/staging/imgtec/rogue/hwdefs \
 -I$(srctree)/drivers/staging/imgtec/rogue/hwdefs/km \
 -I$(srctree)/include/drm \
 -DBC_DISCONTIG_BUFFERS \
 -DMERRIFIELD \
 -DOTM_HDMI_HDCP_ENABLE \
 -DOTM_HDMI_UNIT_TEST \
 -DSUPPORT_VSP

# Include all of the Rogue bridges (for pvr_drm_ext.c)
ccflags-y += \
 $(addprefix -I,$(wildcard $(srctree)/drivers/staging/imgtec/rogue/generated/*))

drm_intel_mid-y += \
 bufferclass_video.o \
 bufferclass_video_linux.o \
 ion_support_intel.o \
 pci_support.o \
 pvr_drm_ext.o \
 sysconfig.o \
 display/tng/drv/mdfld_csc.o \
 display/tng/drv/mdfld_debugfs.o \
 display/tng/drv/mdfld_hdmi_audio.o \
 display/tng/drv/mdfld_intel_hdcp.o \
 display/tng/drv/mdfld_msic.o \
 display/tng/drv/mdfld_output.o \
 display/tng/drv/ospm/dc_maxfifo.o \
 display/tng/drv/ospm/dc_ospm.o \
 display/tng/drv/ospm/early_suspend.o \
 display/tng/drv/ospm/early_suspend_sysfs.o \
 display/tng/drv/ospm/gfx_ospm_ann.o \
 display/tng/drv/ospm/gfx_rtpm.o \
 display/tng/drv/ospm/pwr_mgmt.o \
 display/tng/drv/ospm/video_ospm.o \
 display/tng/drv/mofd_dc_callbacks.o \
 display/tng/drv/mrfld_clock.o \
 display/tng/drv/pmu_tng.o \
 display/tng/drv/psb_bl.o \
 display/tng/drv/psb_drv.o \
 display/tng/drv/psb_fb.o \
 display/tng/drv/psb_gtt.o \
 display/tng/drv/psb_hotplug.o \
 display/tng/drv/psb_intel_display.o \
 display/tng/drv/psb_intel_hdmi.o \
 display/tng/drv/psb_irq.o \
 display/tng/drv/psb_socket.o \
 display/tng/drv/psb_umevents.o \
 display/tng/drv/tng_wa.o \
 graphics/rgx/services/3rdparty/intel_devfreq/dfrgx_interface.o \
 graphics/rgx/services/3rdparty/intel_devfreq/dfrgx_utilstats.o \
 graphics/rgx/services/3rdparty/intel_devfreq/rgxdf.o \
 graphics/rgx/services/3rdparty/intel_drm/dc_mrfld.o \
 otm_hdmi/ipil/common/ipil_hdcp.o \
 otm_hdmi/ipil/common/otm_ipil_main.o \
 otm_hdmi/ipil/specific/mfld/ips_hdmi.o \
 otm_hdmi/ipil/specific/mrfld/ips_hdcp.o \
 otm_hdmi/ipil/specific/mrfld/ips_hdmi_priv.o \
 otm_hdmi/os/android/android_hdmi.o \
 otm_hdmi/pil/common/edid.o \
 otm_hdmi/pil/common/edid_print.o \
 otm_hdmi/pil/common/hdcp.o \
 otm_hdmi/pil/common/infoframes.o \
 otm_hdmi/pil/common/mode_info.o \
 otm_hdmi/pil/common/otm_hdmi.o \
 otm_hdmi/pil/specific/mofd/ps_hdmi.o \
 video/common/psb_buffer.o \
 video/common/psb_cmdbuf.o \
 video/common/psb_fence.o \
 video/common/psb_mmu.o \
 video/common/psb_ttm_fence.o \
 video/common/psb_ttm_fence_user.o \
 video/common/psb_ttm_glue.o \
 video/common/psb_ttm_placement_user.o \
 video/common/tng_securefw.o \
 video/decode/psb_msvdx.o \
 video/decode/psb_msvdx_ec.o \
 video/decode/psb_msvdx_fw.o \
 video/decode/psb_msvdxinit.o \
 video/encode/tng_topaz.o \
 video/encode/tng_topazinit.o \
 video/vsp/vsp.o \
 video/vsp/vsp_init.o

obj-y += dfrgx/
obj-y += hdmi_audio/
