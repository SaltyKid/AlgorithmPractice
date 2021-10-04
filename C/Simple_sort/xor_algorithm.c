/*******************************************************************************
* Copyleft (c) 2020 SaltyKid 1035183478@qq.com
*
* Copyright description information omitted.
*
* @file    xor_algorithm.c
* @author  SaltyKid
* @version 0.0.1
* @date    2021-10-03
* @license GNU General Public License (GPL) 
* @brief   灵活运用异或运算
*          This file contains:
*              - 一个数组中，只有一种数出现奇数次，其它所有数出现偶数次，找到出现奇数次的这种数
*              - 一个数组中，有两种数出现奇数次，其它所有数出现偶数次，找到这两种数
*              - 要求时间复杂度 O(N) 空间复杂度 O(1)
*
* -----------------------------------------------------------------------------
* Change History:
*   <Date>      |  <Version>  |  <Author>  |  <Description>
*   2021-10-03  |  v0.0.1     |  SaltyKid  |  Create file
* -----------------------------------------------------------------------------
******************************************************************************/

/*============================= INCLUDE FILES ===============================*/
#include <stdio.h>
#include <stdint.h>


/*============================ GLOBAL VARIABLES =============================*/


/*========================== FUNCTION PROTOTYPES ============================*/

static void find_even_times_num();
static void find_odd_times_num();

/******************************************************************************
 * @brief        程序入口
 *
 * @param[in]    argc: 传入参数的个数
 * 
 * @param[in]    argv: 传入的每一个参数
 *
 * @return       None
******************************************************************************/
int main(int argc, char const *argv[])
{
    uint32_t i = 0, j = 0;
    uint32_t odd_arr[9] = {8, 2, 8, 2, 4, 5, 4, 2, 5};
    uint32_t even_arr[10] = {3, 5, 4, 9, 3, 4, 3, 5, 9, 5};

    puts("odd_arr:");
    for(i = 0; i < 9; i++)
        printf("%d ", odd_arr[i]);
    
    puts("\neven_arr:");
    for(i = 0; i < 10; i++)
        printf("%d ", even_arr[i]);

    puts("\nodd:");
    find_odd_times_num(odd_arr, 9, &i);
    printf("%d", i);
    puts("");

    puts("even:");
    find_even_times_num(even_arr, 10, &i, &j);
    printf("%d %d", i, j);
    puts("");

    return 0;
}

/******************************************************************************
 * @brief        找出一组数据中（两种数出现奇数次，其它数均出现偶数次），出现奇数次的这两种数
 *
 * @param[in]    None
 *
 * @return       None
******************************************************************************/
static void find_even_times_num(uint32_t *arr, uint32_t num_arr, uint32_t *out_num1, uint32_t *out_num2)
{
    uint32_t i = 0, eor = 0;

    for(i = 0; i < num_arr; i++)
        eor ^= *(arr + i);  //< 遍历数组，找出num1 和 num2 不同的位eor, 此时 eor 必然有一位是 1
    
    *out_num1 = eor & (~(eor) + 1);  //< 取出 eor 最右侧位的 1

    *out_num2 = 0;
    for(i = 0; i < num_arr; i++)
    {
        if(((*(arr + i)) & (*out_num1)) == 0)
            *out_num2 ^= *(arr + i);
    }

    *out_num1 = *out_num2 ^ eor;
}

/******************************************************************************
 * @brief        找出一组数据中（一种数出现奇数次，其它数均出现偶数次），出现奇数次的这种数
 *
 * @param[in]    None
 *
 * @return       None
******************************************************************************/
static void find_odd_times_num(uint32_t *arr, uint32_t num_arr, uint32_t *out_num)
{
    uint32_t i = 0;

    *out_num = 0;
    for(i = 0; i < num_arr; i++)
        *out_num ^= *(arr + i);
}