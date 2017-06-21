/*
 * Cortex-M ARMEmuS support.
 *
 * Copyright (c) 2017 lmcapacho
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <hw/cortexm/armemus.h>
#include <hw/cortexm/helper.h>

#include <sys/socket.h>

// ----------------------------------------------------------------------------

static QemuThread armemus_thread;
static armemus_gpio_write_callback_t armemus_write_callback;

// ----------------------------------------------------------------------------

void *cortexm_armemus_loop(void *threadID)
{
	int server_fd;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		fprintf(stderr, "socket failed");
		exit(EXIT_FAILURE);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( socket_port );
	
	// Forcefully attaching socket to the port 4321
	if (bind(server_fd, (struct sockaddr *)&address, 
								sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((server_fd = accept(server_fd, (struct sockaddr *)&address, 
					(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	
	while(1)
	{
		if( read( server_fd , buffer, 1024) > 0)
		{
			armemus_write_callback(buffer);
			//send(server_fd , buffer , strlen(buffer) , 0 );
		}	
	}	
	
	qemu_thread_exit(NULL);
	return NULL;
}

void cortexm_init_armemus_thread(armemus_gpio_write_callback_t armemus_write)
{
	armemus_write_callback = armemus_write; 
	
	qemu_thread_create(&armemus_thread, NULL, cortexm_armemus_loop, NULL, QEMU_THREAD_DETACHED);
} 

// ----------------------------------------------------------------------------

