/*
 * ledprograms.h
 *
 *  Created on: Apr 10, 2020
 *      Author: chris
 */

#ifndef INC_LEDPROGRAMS_H_
#define INC_LEDPROGRAMS_H_

#include <stdint.h>

void ledprogram_contfade();
void ledprogram_stepfade();
void ledprogram_symcontfade();
void ledprogram_resetall();
void ledprogram_flash(uint8_t num, uint8_t delay);

#endif /* INC_LEDPROGRAMS_H_ */
