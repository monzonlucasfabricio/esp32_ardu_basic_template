/*
 * wrapper.hpp
 *
 *  Created on: 8 jul 2024
 *      Author: Lucas
 */

#ifndef WRAPPER_H_
#define WRAPPER_H_

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

void WR_Println(char* message);
void WR_SerialBegin(uint32_t baudrate);

#ifdef __cplusplus
}
#endif


#endif /* WRAPPER_H_ */
