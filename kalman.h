/**************************************************************
*@Author: John
*@Date:   2015/12/28
*@Description:This file define struct type of kalman filter
*@Verions:1.0
*
**************************************************************/
#ifndef __KALMAN_H
#define __KALMAN_H

typedef struct
{
	float X;
	float P;
	float GAIN;
	float A;
	float H;
	float R;
	float Q;
}st_kalman;




