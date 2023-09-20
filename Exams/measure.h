#ifndef MEASURE_H
#define MEASURE_H
#include <systemc.h>

SC_MODULE(MEASURE)
{
    sc_in<bool> in;
    sc_in<bool> clk;

    sc_signal<sc_uint<32>> count, average; 
    

    virtual sc_uint<16> read(sc_uint<32> address)
    {
        switch(address){
            case 0x0100:
        }
    }

    /* i need to fix it*/
    void counter(){  
        int vector[11]={0};
        while(1){
            wait(clk.posedge());
            while(1){
                wait(clk.posedge());
                if(in==1) break;
                count++;
            }
            vector[i] = count;
            average + = count/11;
            i = (i+1) % 11;
        }
    }
};

#endif
