/**
 * Copyright (c) 2014 - 2018, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* =================================================================================
  ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ú¹Ù·ï¿½ï¿½Ä»ï¿½ï¿½ï¿½ï¿½Ï¸ï¿½ï¿½ï¿½,ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ëµï¿½ï¿½ï¿½ï¿½ï¿½Ò¸ï¿½ï¿½ï¿½ï¿½Ó¶ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿
 =================================================================================*/

/**
* @file         main.c
* @brief        ï¿½Ã»ï¿½Ó¦ï¿½Ã³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿
* @details      ï¿½Ã»ï¿½Ó¦ï¿½Ã³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä¼ï¿½,ï¿½Ã»ï¿½ï¿½ï¿½ï¿½ï¿½ÒªÊµï¿½ÖµÄ¹ï¿½ï¿½ï¿½ï¿½ß¼ï¿½ï¿½ï¿½ï¿½Ç´Ó¸ï¿½ï¿½Ä¼ï¿½ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½ß´ï¿½ï¿½ï¿½
* @author       Helon_Chan
* @par Copyright (c):
*               ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ß¿ï¿½ï¿½ï¿½ï¿½Å¶ï¿½
* @par History:
*               Ver0.0.1:
                     Helon_Chan, 2018/06/09, ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½æ±¾\n
*/


/* =============
Í·ï¿½Ä¼ï¿½ï¿½ï¿½ï¿½ï¿½
 =============*/
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "user_log.h"
#include "user_application.h"

/**
 * log´òÓ¡Êä³ö³õÊ¼»¯º¯Êý
 * @param[in]   NULL
 * @retval      NULL
 * @par         ÐÞ¸ÄÈÕÖ¾
 *              Ver0.0.1:
                  Helon_Chan, 2018/06/09, ³õÊ¼»¯°æ±¾\n
 */
int main(void)
{
  /* logÄ£¿é³õÊ¼»¯ */
  log_init();
  user_app_gpiote_ppi_init();
  NRF_LOG_INFO("/******************************************************************************/\n");
  NRF_LOG_INFO("                       Welcome to wireless-tech ppi demo project                \n");
  NRF_LOG_INFO("                       website :bbs.wireless-tech.cn                            \n");
  NRF_LOG_INFO("                       QQ Group:671139854                                       \n");
  NRF_LOG_INFO("/******************************************************************************/\n");
}

