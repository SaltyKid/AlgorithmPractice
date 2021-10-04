/*******************************************************************************
* Copyleft (c) 2020 SaltyKid 1035183478@qq.com
*
* Copyright description information omitted.
*
* @file    simple_sort.h
* @author  SaltyKid
* @version 0.0.1
* @date    2021-10-04
* @license GNU General Public License (GPL) 
* @brief   简单排序算法
*          This file contains:
*              - insert_sort() 插入排序
*              - bubble_sort() 冒泡排序
*              - select_sort() 选择排t
*
* -----------------------------------------------------------------------------
* Change History:
*   <Date>      |  <Version>  |  <Author>  |  <Description>
*   2021-10-04  |  v0.0.1     |  SaltyKid  |  Create file
* -----------------------------------------------------------------------------
******************************************************************************/
#ifndef __SIMPLE_SORT_H__
#define __SIMPLE_SORT_H__

#ifdef __cplusplus
extern "C" {
#endif

/*============================= INCLUDE FILES ===============================*/
#include <stdint.h>

/*========================== FUNCTION PROTOTYPES ============================*/

extern void select_sort(uint32_t *arr, uint32_t num_arr);
extern void insert_sort(uint32_t *arr, uint32_t num_arr);
extern void bubble_sort(uint32_t *arr, uint32_t num_arr);

#ifdef __cplusplus
}
#endif

#endif