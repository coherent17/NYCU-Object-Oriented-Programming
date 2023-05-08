#ifndef ELECTRONICS_H_
#define ELECTRONICS_H_

using namespace std;

class Electronics{
    private:
        int length;
        int width;
        bool usage;
        bool charging;

    public:
        Electronics(int length, int width);
        ~Electronics();

        bool get_usage();
        void set_usage(bool flag);
        bool get_charging();
        void set_charging(bool flag);
        int get_length();
        int get_width();

        virtual void poweron();
        virtual void run();
        virtual void charge();
        virtual void poweroff();
};

#endif