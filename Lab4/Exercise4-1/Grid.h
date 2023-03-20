#define cout wcout

class Grid {
    bool isMine = false;
    bool isOpen = false;
    bool isExplode = false;
    int mineCount = 0;
    static int gridOpenCount;

    public:

        // Setters
        void setMine();
        void setExplode();
        void setMineCount(int mineCount);
        void open();

        // Getters
        bool getIsMine();
        bool getIsOpen();
        int getMineCount();

        // Static
        static int getGridOpenCount(){
            return gridOpenCount;
        }
        static void resetGridOpenCount(){
            gridOpenCount = 0;
        }

        // Render
        void render();
};
