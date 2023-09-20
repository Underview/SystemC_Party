#ifndef DMA_H
#define DMA_H
#include <systemc.h>

SC_MODULE(DMA), public bus_intfc
{

    sc_signal<sc_uint<32>> read_address, write_address, num_words;
    sc_port<bus_intfc> bus;
    sc_event ev1;

    SC_CTOR(DMA)
    {
    }

    virtual void write(sc_uint<32> data, sc_uint<32> address)
    {
        switch (address)
        {
        case 0:
            read_address.write(data);
            break;
        case 4:
            write_address.write(data);
            break;
        case 8:
            num_words.write(data)
                ev1.notify(SC_ZERO_TIME);
            break;
        }
    }

    virtual sc_uint<32> read(sc_uint<32> address)
    {
    }

    void dma()
    {
        sc_uint<32> tmp;
        sc_uint<32> n = num_words.read();
        sc_uint<32> read_start_loc = read_address.read();
        sc_uint<32> write_start_loc = write_address.write();
        while (1)
        {
            wait(ev1);
            n = num_words.read();
            read_start_loc = read_address.read();
            write_start_loc = write_address.write();
            for (int i = 0; i < n; i++)
            {
                tmp = bus->read(read_start_loc + i * 4);
                bus->write(tmp, write_start_loc + i * 4);
            }
        }
    }
}
#endif
