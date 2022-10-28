/*
 * SSD_cfg.h
 *
 * Created: 8/17/2022 11:28:19 AM
 *  Author: MICHAEL
 */ 


#ifndef SSD_CFG_H_
#define SSD_CFG_H_

/* Modes */
/*COM CATHODE - COM ANODE */

#define SSD_COM COM_ANODE

/* Connections */
#define SSD0_DATA_PORT PORTA_ID
#define SSD0_EN_PORT   PORTB_ID
#define SSD0_EN_PIN    PIN0_ID

#define SSD1_DATA_PORT PORTD_ID
#define SSD1_EN_PORT   PORTD_ID
#define SSD1_EN_PIN    PIN7_ID


#endif /* SSD_CFG_H_ */