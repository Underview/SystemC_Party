#ifndef SHARED_H
#define SHARED_H
#include <systemc.h>

SC_MODULE(SHARED)
{
    sc_port<bus_intfc> ram,rom;

    sc_signal<bool> used;

    
    virtual void write(unsigned int data, unsigned int address){
        if(used) wait(used);
        
        used=1;

        if(address > 65536){
            rom->write(addr);
        }else{
            ram->write(addr);
        }

        used=0;

    }
    virtual unsigned int read(unsigned int address){
        if(used) wait(used);
        used=1;        
        
        int temp;
        if(address > 65536){
            temp = ram->read(addr);
        }else{
            temp = rom->read(addr);
        }

        used=0;
    }
}

#endif
