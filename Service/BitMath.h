/*
 * BitMath.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Safwat
 */

#ifndef SERVICE_BITMATH_H_
#define SERVICE_BITMATH_H_

#define SetBit(Reg,Bit)   Reg |=(1<<Bit)
#define ClrBit(Reg,Bit)    Reg &=~(1<<Bit)
#define GetBit(Reg,Bit)   ((Reg >>Bit)&1)
#define TogBit(Reg,Bit)     Reg ^=(1<<Bit)

#endif
