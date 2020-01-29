/* ***********************************************************************************************

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2014 Intel Corporation. All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
  The full GNU General Public License is included in this distribution
  in the file called LICENSE.GPL.

  BSD LICENSE

  Copyright(c) 2007-2014 Intel Corporation. All rights reserved.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of Intel Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  ***********************************************************************************************
*/

#ifndef _LWPMUDRV_STRUCT_H_
#define _LWPMUDRV_STRUCT_H_

#if defined(__cplusplus)
extern "C" {
#endif

/* processor execution modes*/
#define MODE_UNKNOWN    99
/* the following defines must start at 0*/
#define MODE_64BIT      3
#define MODE_32BIT      2
#define MODE_16BIT      1
#define MODE_V86        0

/* sampling methods*/
#define SM_RTC          2020	/* real time clock*/
#define SM_VTD          2021	/* OS Virtual Timer Device*/
#define SM_NMI          2022	/* non-maskable interrupt time based*/
#define SM_EBS          2023	/* event based*/

/* sampling mechanism bitmap definitions*/
#define INTERRUPT_RTC   0x1
#define INTERRUPT_VTD   0x2
#define INTERRUPT_NMI   0x4
#define INTERRUPT_EBS   0x8

/* eflags defines*/
#define EFLAGS_VM       0x00020000	/* V86 mode*/
#define EFLAGS_IOPL0    0
#define EFLAGS_IOPL1    0x00001000
#define EFLAGS_IOPL2    0x00002000
#define EFLAGS_IOPL3    0x00003000
#define MAX_DEVICES     30
#define MAX_EMON_GROUPS 1000

	extern float freq_multiplier;

/* Enumeration for invoking dispatch on multiple cpus or not*/
	typedef enum {
		DRV_MULTIPLE_INSTANCE = 0,
		DRV_SINGLE_INSTANCE
	} DRV_PROG_TYPE;

	typedef struct DRV_CONFIG_NODE_S DRV_CONFIG_NODE;
	typedef DRV_CONFIG_NODE *DRV_CONFIG;

	struct DRV_CONFIG_NODE_S {
		U32 size;
		U32 num_events;
		DRV_BOOL start_paused;
		DRV_BOOL counting_mode;
		U32 dispatch_id;
		DRV_BOOL enable_chipset;
		U32 num_chipset_events;
		U32 chipset_offset;
		DRV_BOOL enable_gfx;
		DRV_BOOL enable_pwr;
		DRV_BOOL emon_mode;
		U32 pebs_mode;
		U32 pebs_capture;
		DRV_BOOL collect_lbrs;
		DRV_BOOL collect_callstacks;
		DRV_BOOL debug_inject;
		DRV_BOOL virt_phys_translation;
		DRV_BOOL latency_capture;
		U32 max_gp_counters;
		DRV_BOOL htoff_mode;
		DRV_BOOL power_capture;
		U32 results_offset;	/* this is to store the offset for this device's results*/
		DRV_BOOL eventing_ip_capture;
		DRV_BOOL hle_capture;
		U32 emon_unc_offset[MAX_EMON_GROUPS];
		S32 seed_name_len;
		U32 reserved0;
		U64 target_pid;
		DRV_BOOL use_pcl;
		DRV_BOOL enable_ebc;
		DRV_BOOL enable_tbc;
		U32 reserved1;
		union {
			S8 *seed_name;
			U64 dummy1;
		} u1;
		union {
			S8 *cpu_mask;
			U64 dummy2;
		} u2;
		U32 device_type;
		U32 reserved2;
	};

#define DRV_CONFIG_size(cfg)                      (cfg)->size
#define DRV_CONFIG_num_events(cfg)                (cfg)->num_events
#define DRV_CONFIG_start_paused(cfg)              (cfg)->start_paused
#define DRV_CONFIG_counting_mode(cfg)             (cfg)->counting_mode
#define DRV_CONFIG_dispatch_id(cfg)               (cfg)->dispatch_id
#define DRV_CONFIG_enable_chipset(cfg)            (cfg)->enable_chipset
#define DRV_CONFIG_num_chipset_events(cfg)        (cfg)->num_chipset_events
#define DRV_CONFIG_chipset_offset(cfg)            (cfg)->chipset_offset
#define DRV_CONFIG_enable_gfx(cfg)                (cfg)->enable_gfx
#define DRV_CONFIG_enable_pwr(cfg)                (cfg)->enable_pwr
#define DRV_CONFIG_emon_mode(cfg)                 (cfg)->emon_mode
#if defined(DRV_IA32) || defined(DRV_EM64T)
#define DRV_CONFIG_pebs_mode(cfg)                 (cfg)->pebs_mode
#define DRV_CONFIG_pebs_capture(cfg)              (cfg)->pebs_capture
#define DRV_CONFIG_collect_lbrs(cfg)              (cfg)->collect_lbrs
#define DRV_CONFIG_collect_callstacks(cfg)        (cfg)->collect_callstacks
#define DRV_CONFIG_debug_inject(cfg)              (cfg)->debug_inject
#define DRV_CONFIG_virt_phys_translation(cfg)     (cfg)->virt_phys_translation
#define DRV_CONFIG_latency_capture(cfg)           (cfg)->latency_capture
#define DRV_CONFIG_max_gp_counters(cfg)           (cfg)->max_gp_counters
#define DRV_CONFIG_htoff_mode(cfg)                (cfg)->htoff_mode
#define DRV_CONFIG_power_capture(cfg)             (cfg)->power_capture
#define DRV_CONFIG_results_offset(cfg)            (cfg)->results_offset
#define DRV_CONFIG_eventing_ip_capture(cfg)       (cfg)->eventing_ip_capture
#define DRV_CONFIG_hle_capture(cfg)               (cfg)->hle_capture

#define DRV_CONFIG_emon_unc_offset(cfg,grp_num)   (cfg)->emon_unc_offset[grp_num]
#else
#define DRV_CONFIG_collect_ro(cfg)                (cfg)->collect_ro
#endif
#define DRV_CONFIG_seed_name(cfg)                 (cfg)->u1.seed_name
#define DRV_CONFIG_seed_name_len(cfg)             (cfg)->seed_name_len
#define DRV_CONFIG_cpu_mask(cfg)                  (cfg)->u2.cpu_mask
#define DRV_CONFIG_target_pid(cfg)                (cfg)->target_pid
#define DRV_CONFIG_use_pcl(cfg)                   (cfg)->use_pcl
#define DRV_CONFIG_event_based_counts(cfg)        (cfg)->enable_ebc
#define DRV_CONFIG_timer_based_counts(cfg)        (cfg)->enable_tbc
#define DRV_CONFIG_device_type(cfg)               (cfg)->device_type

/*
 * @macro SOCPERF_VERSION_NODE_S
 * @brief
 * This structure supports versioning in Sep. The field major indicates the major version,
 * minor indicates the minor version and api indicates the api version for the current
 * sep build. This structure is initialized at the time when the driver is loaded.
 */

	typedef struct SOCPERF_VERSION_NODE_S SOCPERF_VERSION_NODE;
	typedef SOCPERF_VERSION_NODE *SOCPERF_VERSION;

	struct SOCPERF_VERSION_NODE_S {
		union {
			U32 socperf_version;
			struct {
				S32 major:8;
				S32 minor:8;
				S32 api:16;
			} s1;
		} u1;
	};

#define SOCPERF_VERSION_NODE_socperf_version(version) (version)->u1.socperf_version
#define SOCPERF_VERSION_NODE_major(version)           (version)->u1.s1.major
#define SOCPERF_VERSION_NODE_minor(version)           (version)->u1.s1.minor
#define SOCPERF_VERSION_NODE_api(version)             (version)->u1.s1.api

	typedef struct DEVICE_INFO_NODE_S DEVICE_INFO_NODE;
	typedef DEVICE_INFO_NODE *DEVICE_INFO;

	struct DEVICE_INFO_NODE_S {
		S8 *dll_name;
		PVOID dll_handle;
		S8 *cpu_name;
		S8 *pmu_name;
		S8 *event_db_file_name;
		/* this is undefined right now. Please take this as structure containing U64*/
		/*PLATFORM_IDENTITY plat_identity;  */
		U32 plat_type;	/* device type (e.g., DEVICE_INFO_CORE, etc. ... see enum below)*/
		U32 plat_sub_type;	/* cti_type (e.g., CTI_Sandybridge, etc., ... see env_info_types.h)*/
		U32 dispatch_id;	/* this will be set in user mode dlls and will be unique across all IPF, IA32 (including MIDS).*/
		ECB *ecb;
		EVENT_CONFIG ec;
		DRV_CONFIG pcfg;
		U32 num_of_groups;
		U32 size_of_alloc;	/* size of each event control block*/
		PVOID drv_event;
		U32 num_events;
		U32 event_id_index;	/* event id index of device (basically how many events processed before this device)*/
		U32 num_counters;
		U32 group_index;
		U32 num_packages;
		U32 num_units;
	};

#define MAX_EVENT_NAME_LENGTH 64

#define DEVICE_INFO_dll_name(pdev)                  (pdev)->dll_name
#define DEVICE_INFO_dll_handle(pdev)                (pdev)->dll_handle
#define DEVICE_INFO_cpu_name(pdev)                  (pdev)->cpu_name
#define DEVICE_INFO_pmu_name(pdev)                  (pdev)->pmu_name
#define DEVICE_INFO_event_db_file_name(pdev)        (pdev)->event_db_file_name
#define DEVICE_INFO_plat_type(pdev)                 (pdev)->plat_type
#define DEVICE_INFO_plat_sub_type(pdev)             (pdev)->plat_sub_type
#define DEVICE_INFO_ecb(pdev)                       (pdev)->ecb
#define DEVICE_INFO_ec(pdev)                        (pdev)->ec
#define DEVICE_INFO_pcfg(pdev)                      (pdev)->pcfg
#define DEVICE_INFO_num_groups(pdev)                (pdev)->num_of_groups
#define DEVICE_INFO_size_of_alloc(pdev)             (pdev)->size_of_alloc
#define DEVICE_INFO_drv_event(pdev)                 (pdev)->drv_event
#define DEVICE_INFO_num_events(pdev)                (pdev)->num_events
#define DEVICE_INFO_event_id_index(pdev)            (pdev)->event_id_index
#define DEVICE_INFO_num_counters(pdev)              (pdev)->num_counters
#define DEVICE_INFO_group_index(pdev)               (pdev)->group_index
#define DEVICE_INFO_num_packages(pdev)              (pdev)->num_packages
#define DEVICE_INFO_num_units(pdev)                 (pdev)->num_units

	typedef struct DEVICE_INFO_DATA_NODE_S DEVICE_INFO_DATA_NODE;
	typedef DEVICE_INFO_DATA_NODE *DEVICE_INFO_DATA;

	struct DEVICE_INFO_DATA_NODE_S {
		DEVICE_INFO pdev_info;
		U32 num_elements;
		U32 num_allocated;
	};

#define DEVICE_INFO_DATA_pdev_info(d)           (d)->pdev_info
#define DEVICE_INFO_DATA_num_elements(d)        (d)->num_elements
#define DEVICE_INFO_DATA_num_allocated(d)       (d)->num_allocated

	typedef enum {
		DEVICE_INFO_CORE = 0,
		DEVICE_INFO_UNCORE = 1,
		DEVICE_INFO_CHIPSET = 2,
		DEVICE_INFO_GFX = 3,
		DEVICE_INFO_PWR = 4,
		DEVICE_INFO_TELEMETRY = 5
	} DEVICE_INFO_TYPE;

#if defined(__cplusplus)
}
#endif
typedef struct DRV_EVENT_MASK_NODE_S DRV_EVENT_MASK_NODE;
typedef DRV_EVENT_MASK_NODE *DRV_EVENT_MASK;

struct DRV_EVENT_MASK_NODE_S {
	U8 event_idx;		/* 0 <= index < MAX_EVENTS*/
	union {
		U8 bitFields1;
		struct {
			U8 precise:1;
			U8 lbr_capture:1;
			U8 dear_capture:1;	/* Indicates which events need to have additional registers read*/
			/* because they are DEAR events.*/
			U8 iear_capture:1;	/* Indicates which events need to have additional registers read*/
			/* because they are IEAR events.*/
			U8 btb_capture:1;	/* Indicates which events need to have additional registers read*/
			/* because they are BTB events.*/
			U8 ipear_capture:1;	/* Indicates which events need to have additional registers read*/
			/* because they are IPEAR events.*/
			U8 uncore_capture:1;
			U8 reserved0:2;
		} s1;
	} u1;
};

#define DRV_EVENT_MASK_event_idx(d)             (d)->event_idx
#define DRV_EVENT_MASK_bitFields1(d)            (d)->u1.bitFields1
#define DRV_EVENT_MASK_precise(d)               (d)->u1.s1.precise
#define DRV_EVENT_MASK_lbr_capture(d)           (d)->u1.s1.lbr_capture
#define DRV_EVENT_MASK_dear_capture(d)          (d)->u1.s1.dear_capture
#define DRV_EVENT_MASK_iear_capture(d)          (d)->u1.s1.iear_capture
#define DRV_EVENT_MASK_btb_capture(d)           (d)->u1.s1.btb_capture
#define DRV_EVENT_MASK_ipear_capture(d)         (d)->u1.s1.ipear_capture
#define DRV_EVENT_MASK_uncore_capture(d)        (d)->u1.s1.uncore_capture

#define MAX_OVERFLOW_EVENTS 11	/* This defines the maximum number of overflow events per interrupt.*/
				  /* In order to reduce memory footprint, the value should be at least*/
				  /* the number of fixed and general PMU registers.*/
				  /* Sandybridge with HT off has 11 PMUs(3 fixed and 8 generic)*/

typedef struct DRV_MASKS_NODE_S DRV_MASKS_NODE;
typedef DRV_MASKS_NODE *DRV_MASKS;

/*
 * @macro DRV_EVENT_MASK_NODE_S
 * @brief
 * The structure is used to store overflow events when handling PMU interrupt.
 * This approach should be more efficient than checking all event masks
 * if there are many events to be monitored
 * and only a few events among them have overflow per interrupt.
 */
struct DRV_MASKS_NODE_S {
	DRV_EVENT_MASK_NODE eventmasks[MAX_OVERFLOW_EVENTS];
	U8 masks_num;		/* 0 <= mask_num <= MAX_OVERFLOW_EVENTS*/
	U8 padding;		/* data structure alignment*/
};

#define DRV_MASKS_masks_num(d)           (d)->masks_num
#define DRV_MASKS_eventmasks(d)          (d)->eventmasks

typedef struct EMON_SCHED_INFO_NODE_S EMON_SCHED_INFO_NODE;
typedef EMON_SCHED_INFO_NODE *EMON_SCHED_INFO;

struct EMON_SCHED_INFO_NODE_S {
	U32 max_counters_for_all_pmus;
	U32 num_cpus;
	U32 group_index[MAX_EMON_GROUPS];
	U32 offset_for_next_device[MAX_EMON_GROUPS];
	U32 device_id;
	U32 num_packages;
	U32 num_units;
	U32 user_scheduled;
};

#define EMON_SCHED_INFO_max_counters_for_all_pmus(x)           (x)->max_counters_for_all_pmus
#define EMON_SCHED_INFO_num_cpus(x)                            (x)->num_cpus
#define EMON_SCHED_INFO_group_index(x,grp_num)                 (x)->group_index[grp_num]
#define EMON_SCHED_INFO_offset_for_next_device(x, grp_num)     (x)->offset_for_next_device[grp_num]
#define EMON_SCHED_INFO_device_id(x)                           (x)->device_id
#define EMON_SCHED_INFO_num_packages(x)                        (x)->num_packages
#define EMON_SCHED_INFO_num_units(x)                           (x)->num_units
#define EMON_SCHED_INFO_user_scheduled(x)                      (x)->user_scheduled

#define INITIALIZE_Emon_Sched_Info(x,j)                                                            \
    for((j) =0; (j) < MAX_EMON_GROUPS; (j)++) {                                                    \
        EMON_SCHED_INFO_group_index((x),(j))             = 0;                                      \
        EMON_SCHED_INFO_offset_for_next_device((x), (j)) = 0;                                      \
    }

#endif
