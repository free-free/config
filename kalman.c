/***********************************************************************************************************
*
*@Author:John
*@Date:2015/12/28
*@Description:This file define kalman filter process function
*@Version:1.0
*
*************************************************************************************************************/
#include "kalman.h"

/**
*
*@param st_kalman pointer kalman_filter
*@param float x
*@param float p
*@param float q
*@param float r
*@return None
&
*/

void init_kalman_param(st_kalman* kalman_filter,float x,float p,float q,float r)
{
	kalman_filter->X=x;
	kalman_filter->P=p;
	kalman_filter->Q=q;
	/*R is sensor's static errors */
	kalman_filter->R=r;
	/* H equals 1 if output can be detected by sensor */
	kalman_filter->H=1;
	/* A equals 1 in the most of condition */
	kalman_filter->A=1;
}


/*
*
*@param st_kalman poninter kalman_filter
*@param float z //detect output
*@return float  //calculate output
*
*/
float calc_kalman(st_kalman *kalman_filter,float z)
{
	/* x=A*x*A'+B*u  */
	kalman_filter->X=kalman_filter->A*kalman_filter->X;
	/* p=A*p*A'+Q  */
	kalman_filter->P=kalman_filter->A*kalman_filter->P*kalman_filter->H+kalman_filter->Q;
	/* kg=p*H'/(H*p*H'+R)   */
	kalman_filter->GAIN=kalman_filter->P*kalman_filter->H(kalman_filter->H*kalman_filter->P*kalman_filter->H+kalman_filter->R);
	/* x=x+kg*(z-H*x)   */
	kalman_filter->X=kalman_filter->X+kalman_filter->GAIN*(z-kalman_filter->H*kalman_filter->X);
	/* p=(1-kg*H)*P  */
	kalman_filter->P=(1-kalman_filter->GAIN*kalman_filter->H)*kalman_filter->P;
	return kalman_filter->X;
} 
