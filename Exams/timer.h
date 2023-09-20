#ifndef WAVEFORM_H
#define WAVEFORM_H
#include <systemc.h>

SC_MODULE(timer), public bus_intfc
{

    sc_signal<sc_uint<32>> control;
    sc_signal<sc_uint<32>> counter0,period0;
    sc_signal<sc_uint<32>> counter1,period1;
    sc_in<bool> reset,clock;

    virtual void write(sc_uint<16> data, sc_uint<32> address)
    {
        switch(address){
            case 0: control.write(data);break;
            case 4: counter0.write(data);break;
            case 8: counter1.write(data);break;
            case 12: period0.write(data);break;
            case 16: period1.write(data) ;break;
        }
    }

    virtual sc_uint<16> read(sc_uint<32> address)
    {
        sc_uint<32> tmp;
        switch(address){
            case 0: tmp = control.read();break;
            case 4: tmp = counter0.read();break;
            case 8: tmp = counter1.read();break;
        }
        return tmp;
    }

    void counter(){
        while(1){
            wait(reset);
            if(reset==1){
                control = 0x00000000;
                counter0 = 0x00000000;
                counter1 = 0x00000000;
            }else{
                wait(clk.posedge());
                if(counter0 == period0-1){
                    counter0 = 0x00000000;
                    control = 0x00000001
                }else{
                    counter0++;
                }
                if(counter1 == period1-1){
                    counter0 = 0x00000000;
                    control = 0x00000002
                }else{
                    counter1++;
                }                
    
           
            }

        }
    }

}
#endif
