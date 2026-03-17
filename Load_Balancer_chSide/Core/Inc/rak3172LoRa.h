/*
 * rak3172LoRa.h
 *
 *  Created on: Apr 24, 2025
 *      Author: hashara
 */

#ifndef INC_RAK3172LORA_H_
#define INC_RAK3172LORA_H_


#include "stdbool.h"
#include "main.h"

#define CH_RX_SIZE 32
#define AES_KEY_SIZE 16
#define AES_BLOCK_SIZE 16
#define CH_TX_SIZE 32
#define SN_ADDR ((uint32_t)0x0803F000)

extern uint8_t key[AES_KEY_SIZE];
extern  uint8_t iv[AES_BLOCK_SIZE];

extern  uint8_t LoRaCH_Rx[CH_RX_SIZE];
extern  uint8_t LoRaCH_Tx[CH_TX_SIZE];

extern uint8_t SNW[11];
extern uint32_t randNum;

typedef enum {
    STATE_IDLE,
    STATE_TX_DONE,
	STATE_TX_TIMEOUT,
    STATE_RX_DONE,
    STATE_RX_TIMEOUT,
    STATE_RX_ERROR
} LoRaState_t;

extern volatile LoRaState_t LoRaState;

struct RxData
{
	float I1rms;
	float I2rms;
	float I3rms;

};

extern volatile struct RxData RxCurrents;
extern volatile struct RxData CurrentAvrgBefore;
extern volatile struct RxData CurrentAvrgAfter;

extern uint8_t SN[11];




#define RF_DEFAULT_FREQUENCY                        910000000 /* Hz */
#define TX_OUTPUT_POWER                             22
#define LORA_BANDWIDTH                              2         /* [0: 125 kHz, 1: 250 kHz, 2: 500 kHz, 3: Reserved] */
#define LORA_SPREADING_FACTOR                       10        /* [SF7..SF12] */
#define LORA_CODINGRATE                             1         /* [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8] */
#define LORA_PREAMBLE_LENGTH                        8         /* Same for Tx and Rx */
#define LORA_SYMBOL_TIMEOUT                         5         /* Symbols */
#define LORA_FIX_LENGTH_PAYLOAD_ON                  false
#define LORA_IQ_INVERSION_ON                        false
#define PAYLOAD_LEN                                 64

#define TX_TIMOUT_VALUE                             10000
#define RX_TIMOUT_VALUE                             30000

#define MAX_APP_BUFFEE_SIZE                         255

void RadioInit(void);

void Send_Request(void);

void LoadSerialNumber(void);

#endif /* INC_RAK3172LORA_H_ */
