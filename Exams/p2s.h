#ifndef P2S_H
#define P2S_H
#include <systemc.h>

SC_MODULE(P2S)
{
    sc_out<bool> out;
    sc_in<bool> clk;
    
    sc_event ev1;

    virtual void write(sc_uint<16> address, sc_uint<8> data){
        if(address == 0x0100){

            ev1.notify(SC_ZERO_TIME);
        }
    }


    void conversion(){
        while(1){
            wait(ev1 & clk.posedge());
            out.write(1);
            wait(clk.posedge());

        }
    }
}

#endif
