#ifndef TLM_BUS_DEC_H
#define TLM_BUS_DEC_H
#include <systemc.h>

SC_MODULE(TLM)
{
    sc_port<bus_if> timer;
    sc_port<bus_if> pio;

    sc_signal<bool> busy;

    SC_CTOR(TLM), timer("timer"), pio("pio"){

    }

    virtual void write(sc_uint<16> data, sc_uint<32> address)
    {
        if(busy==true) wait(busy);
        busy=true;

        wait((10, SC_NS));
        busy = false;

    }

    virtual sc_uint<16> read(sc_uint<32> address)
    {
        if(busy==true) wait(busy);
        busy=true;


        wait((20, SC_NS));
        busy = false;
    }    
}

#endif
