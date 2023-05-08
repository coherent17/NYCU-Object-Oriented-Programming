#include "Electronics.h"

#ifndef _PHONE_H_
#define _PHONE_H_

class Phone: public Electronics{
    private:
        int currentt_power;
        int in_rate;
        int out_rate;

    public:
        Phone(int in_rate, int out_rate, int length, int width);
        ~Phone();

        void poweron()override;
        void run()override;
        void charge()override;
        void poweroff()override;
};

#endif