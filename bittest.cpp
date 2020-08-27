#include <iostream>
#include <cstdint>
#include <cstdio>
#include "bittest.h"

int CheckParam(uint64_t subject, size_t size) {
    if(subject > (1 << size)) {
        return 0;
    }
    return 1;    
}

int main(int argc, char** argv) {
    int arr_res[7];
    uint8_t row = 30;
    uint8_t col = 7;
    bool checkresult;
                      //  DOW  WDOM   WOY  Month  DOM  Hour  
    int mask[row][col] = {{0,    0,    0,    0,    0,    0,    0}, // every hour (constantly)
                          {0,    0,    0,    0,    0,    1,    0}, // every day at Hour:Minute
                          {0,    0,    0,    0,    1,    0,    0}, // every hour of every DOM-th day of every month
                          {0,    0,    0,    0,    1,    1,    0}, // every DOM-th day of every month at Hour:Minute
                          {0,    0,    0,    1,    0,    0,    0}, // every hour of Month
                          {0,    0,    0,    1,    0,    1,    0}, // every day of Month at Hour:Minute
                          {0,    0,    0,    1,    1,    0,    0}, // every hour of every DOM-th day of Month
                          {0,    0,    0,    1,    1,    1,    0}, // every DOM-th day of Month at Hour:Minute
                          {0,    0,    1,    0,    0,    0,    0}, // every hour of WOY
                          {0,    0,    1,    0,    0,    1,    0}, // every day of WOY at Hour:Minute
                          {0,    0,    1,    0,    1,    2,    0}, // restricted (both WOY and DOM)
                          {0,    0,    1,    1,    2,    2,    0}, // restricted (both WOY and Month)
                          {0,    1,    2,    2,    2,    2,    0}, // restricted (WDOM implies DOW)
                          {1,    0,    0,    0,    0,    0,    0}, // every hour of each DOW
                          {1,    0,    0,    0,    0,    1,    0}, // every DOW at Hour:Minute
                          {1,    0,    0,    0,    1,    2,    0}, // restricted (Friday the 13th)
                          {1,    0,    0,    1,    0,    0,    0}, // every hour of every DOW of Month
                          {1,    0,    0,    1,    0,    1,    0}, // every DOW of Month at Hour:Minute
                          {1,    0,    0,    1,    1,    2,    0}, // restricted (Friday the 13th)
                          {1,    0,    1,    0,    0,    0,    0}, // every hour of WOY-th DOW of a year (1 day a year)
                          {1,    0,    1,    0,    0,    1,    0}, // WOY-th DOW of a year at Hour:Minute (once a year)
                          {1,    0,    1,    0,    1,    2,    0}, // restricted (Friday the 13th)
                          {1,    0,    1,    1,    2,    2,    0}, // restricted (both WOY and Month)
                          {1,    1,    0,    0,    0,    0,    0}, // every hour every WDOM-th DOW of every month
                          {1,    1,    0,    0,    0,    1,    0}, // every WDOM-th DOW of every month at Hour:Minute
                          {1,    1,    0,    0,    1,    2,    0}, // restricted (Friday the 13th)
                          {1,    1,    0,    1,    0,    0,    0}, // every hour every WDOM-th DOW of Month
                          {1,    1,    0,    1,    0,    1,    0}, // every WDOM-th DOW of Month at Hour:Minute
                          {1,    1,    0,    1,    1,    2,    0}, // restricted (Friday the 13th)
                          {1,    1,    1,    2,    2,    2,    0}  // restricted (both WDOM and WOY)
                         };
    
    arr_res[0] = CheckParam(11, 5);   // DOW
    arr_res[1] = CheckParam(555, 9);  // WDOM
    arr_res[2] = CheckParam(33, 5);   // WOY
    arr_res[3] = CheckParam(33, 5);   // Month
    arr_res[4] = CheckParam(25, 5);   // DOM
    arr_res[5] = CheckParam(33, 5);   // Hour
    arr_res[6] = CheckParam(33, 5);   // Minute

    for(size_t i = 0; i < row; ++i) {
        checkresult = true;
        for(size_t j = 0; j < (col - 1); ++j) {
            if(arr_res[j] != mask[i][j]) {
                checkresult = false; 
                break;
            }
        }
        if(checkresult) {
            std::cout<<"\nAll right!\n";
            break;    
        }
    }
    if(!checkresult) {
        std::cout<<"\nFailed\n"; 
    }
    for(size_t i = 0; i < 7; ++i) {
        std::cout<<arr_res[i] <<"  ";    
    }
    std::cout<<"\n";
    return 0;
}
