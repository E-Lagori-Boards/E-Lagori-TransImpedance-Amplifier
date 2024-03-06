#include "i_tia.h"

void itia_init(struct i_tia *p, float maxR, int address, i2c_port_t *i2c){
    p->maxR = 100000;
    digipot_init(&(p->d), address, i2c);
}

void itia_setgain(struct i_tia *p, bool channo,float gain){
    float R = 0;
    R = gain;
    R = (R>p->maxR)?p->maxR:R;
    R = (R<0)?0:R;
    // ESP_LOGI("Setgain","%f, %d",R,(int)(R/p->maxR*256.0));
    digipot_Write_RDAC(&(p->d),channo, (int)(R/(p->maxR+3340)*256.0));
}

float ivga_presentgain(struct i_tia *p, bool channo){
    float R = digipot_Readback_RDAC(&(p->d),channo)/256.0*(p->maxR+3340);
    return(R);
}