/* ***********************************************************************************************

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2013 Intel Corporation. All rights reserved.

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

  Contact Information:
  SOCWatch Developer Team <socwatchdevelopers@intel.com>

  BSD LICENSE

  Copyright(c) 2013 Intel Corporation. All rights reserved.
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

#ifndef _PW_MESSAGE_H_
#define _PW_MESSAGE_H_ 1

#include "pw_types.h"

#pragma pack(push)		/* Store current alignment */
#pragma pack(2)			/* Set new alignment -- 2 byte boundaries */

/*
 * The main PWCollector_sample structure.
 * are encoded in these.
 */
/*
 * "Final" message header. ALL Ring 0 --> Ring 3 (data) messages are encoded in these.
 * -------------------------------------------------------------------------------------------
 * MUST Set "cpuidx" to ZERO for payloads that don't require a cpu field (e.g. GFX C-states).
 * (cpuidx is included for all messages because it makes sorting data easier)
 * -------------------------------------------------------------------------------------------
 * WARNING!: This struct is being used and locally defined in the VMM of the SoFIA OS src. Any
 * changes in this struct should be reflected in the VMM/SoFIA copy as well.
 * Contact Robert Knight/Jay Chheda if you have any questions.
 */
typedef struct PWCollector_msg PWCollector_msg_t;
struct PWCollector_msg {
	u64 tsc;		/* TSC of message.*/
	/* GEH: Is this equal to wakeup TSC for c_msg_t samples?*/
	u16 data_len;		/* length of payload message in bytes (not including this header) represented by p_data.*/
	u16 cpuidx;		/* GEH: Need to define what this is for post-processed samples*/
	u8 data_type;		/* The type of payload encoded by 'p_data': one of 'sample_type_t'*/
	u8 padding;		/* The compiler would have inserted it anyway!*/

	u64 p_data;		/* For SW1 file, this is the payload: one of *_msg_t corresponding to data_type (inline memory).*/
	/* For internal data, this field is a pointer to the non-contiguous payload memory (not inline).*/
	/* GU: changed from "u8[1]" to "u64" to get the driver to compile*/
};
#define PW_MSG_HEADER_SIZE ( sizeof(PWCollector_msg_t) - sizeof(u64) )

#pragma pack(pop)		/* Restore previous alignment */

#endif /* _PW_MESSAGE_H_*/
