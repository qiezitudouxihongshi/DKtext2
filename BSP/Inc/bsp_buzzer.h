#ifndef DM0_BUZZER_H
#define DM0_BUZZER_H

#include "tim.h"

#define Do 262
#define Re 294
#define Mi 330
#define Fa 349
#define So 392
#define La 440
#define Xi 494

void buzzer_init(void);
void buzzer_Set_freq(uint16_t freq);
void buzzer_off(void);

//小星星
void Little_Star(void);

#endif //DM0_BUZZER_H
