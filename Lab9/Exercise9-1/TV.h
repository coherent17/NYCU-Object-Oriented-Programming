#include "Electronics.h"

#ifndef _TV_H_
#define _TV_H_

class TV: public Electronics{
    private:

    public:
        TV(int, int);
        ~TV();

        void poweron()override;
        void run()override;
        void charge()override;
        void poweroff()override;
};

#endif