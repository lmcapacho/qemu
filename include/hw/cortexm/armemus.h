/*
 * Cortex-M ARMEmuS definitions.
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

#ifndef CORTEXM_ARMEMUS_H_
#define CORTEXM_ARMEMUS_H_


#define socket_port	4321

typedef void (*armemus_gpio_write_callback_t)(const char*);

void *cortexm_armemus_loop(void *threadID);
void cortexm_init_armemus_thread(armemus_gpio_write_callback_t);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_ARMEMUS_H_ */

