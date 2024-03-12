#ifndef I_TIA_H
#define  I_TIA_H

#include "esp_err.h"
#include "digipot.h"
#include "esp_log.h"

struct i_tia{
    float  maxR;
    struct digipot d;
};

extern "C" void itia_init(struct i_tia *p, float maxR, int address, i2c_port_t *i2c);
extern "C" void itia_setgain(struct i_tia *p, bool channo,float gain);
extern "C" float itia_presentgain(struct i_tia *p, bool channo);

class TIA
{
private:
    /* data */
    struct i_tia *p;
    i2c_port_t *i2c;

public:
    begin(float maxR,int address);
    setgain(bool channel_number,float gain);
    presentgain(bool channel_number);
    // ~i_tia();
};



#endif