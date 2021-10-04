/*******************************************************************************
* Copyleft (c) 2020 SaltyKid 1035183478@qq.com
*
* Copyright description information omitted.
*
* @file    simple_sort.c
* @author  SaltyKid
* @version 0.0.1
* @date    2021-10-04
* @license GNU General Public License (GPL) 
* @brief   简单排序算法
*          This file contains:
*              - insert_sort() 插入排序
*              - bubble_sort() 冒泡排序
*              - select_sort() 选择排序
*
* -----------------------------------------------------------------------------
* Change History:
*   <Date>      |  <Version>  |  <Author>  |  <Description>
*   2021-10-04  |  v0.0.1     |  SaltyKid  |  Create file
* -----------------------------------------------------------------------------
******************************************************************************/

/*============================= INCLUDE FILES ===============================*/
#include "simple_sort.h"

/*========================== FUNCTION PROTOTYPES ============================*/

static void swap_two_nums(uint32_t *p_num1, uint32_t *p_num2);

/******************************************************************************
 * @brief        插入排序
 *
 * @param[in]    arr: 待排序的数组
 * 
 * @param[in]    num_arr: 数组中的元素数量
 *
 * @return       None
******************************************************************************/
void insert_sort(uint32_t *arr, uint32_t num_arr)
{
    uint32_t i = 0, j = 0;

    for(i = 1; i < num_arr; i++)
    {
        for(j = i; j > 0 && arr[j - 1] > arr[j]; j--)
            swap_two_nums(&arr[j - 1], &arr[j]);
    }
}

/******************************************************************************
 * @brief        冒泡排序
 *
 * @param[in]    arr: 待排序的数组
 * 
 * @param[in]    num_arr: 数组中的元素数量
 * 
 * @return       None
******************************************************************************/
void bubble_sort(uint32_t *arr, uint32_t num_arr)
{
    uint32_t i, j;

    if((void *)0 == arr || 2 > num_arr)
        return;

    for(i = num_arr - 1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(arr[j] > arr[j + 1])
                swap_two_nums(&arr[j], &arr[j + 1]);
        }
    }
}

/******************************************************************************
 * @brief        选择排序
 *
 * @param[in]    arr: 待排序的数组
 * 
 * @param[in]    num_arr: 数组中的元素数量
 *
 * @return       None
******************************************************************************/
void select_sort(uint32_t *arr, uint32_t num_arr)
{
    uint32_t i = 0, j = 0;
    uint32_t min_idx = 0;

    if((void *)0 == arr || num_arr < 2)
        return;

    for ( i = 0; i < num_arr; i++)
    {
        min_idx = i;
        for(j = i + 1; j < num_arr; j++)
        {
            if(arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap_two_nums(&arr[i], &arr[min_idx]);
    }
    
}

/******************************************************************************
 * @brief        Swap two numbers
 *
 * @param[in]    p_num1: A pointer to the first number
 * 
 * @param[in]    p_num2: A pointer to the first number
 *
 * @return       None
******************************************************************************/
static void swap_two_nums(uint32_t *p_num1, uint32_t *p_num2)
{
    if(p_num1 == p_num2)
        return;
    *p_num1 ^= *p_num2;
    *p_num2 ^= *p_num1;
    *p_num1 ^= *p_num2;
}
