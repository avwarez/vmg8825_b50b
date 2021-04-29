/*
 * (C) Copyright 2016 Quantenna Communications Inc.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __QSTEER_COMM_H__
#define __QSTEER_COMM_H__

#define QSTEER_ROLE_UNCONFIGURED	0
#define QSTEER_ROLE_MASTER		1
#define QSTEER_ROLE_SLAVE		2

typedef int  qsteer_role_t;

/**
 * \brief Get the current role of the device.
 *
 * OEM can call this function to get the role of Q-Comm-M
 *
 * \param role pointer to the the buffer for storing the value role
 *
 * \\return 0 on success and other for failure
 */
int qsteer_get_role(qsteer_role_t *role);

/**
 * \brief Ask QSteer Comm-M to update the AP configuration.
 *
 * OEM can call this function to reconfigurate all of the APs in the LAN
 *
 * \param path pointer to the path of the file contains the new AP configuration
 *
 * \\return 0 on success and other for failure
 */
int qsteer_cfg_update(const char *path);

/**
 * \brief Get the feedback of the last updating operation.
 *
 * OEM can call this function to get the detailed feedback of last updating operation
 *
 * \param path pointer to the path of the file for storing the feedback
 *
 * \\return 0 on success
 * \\return 1 on updating is in process
 * \\return -1 on error
 */
int qsteer_get_update_fdbk(const char *path);

#endif

