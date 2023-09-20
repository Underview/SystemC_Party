#ifndef WAVEFORM_H
#define WAVEFORM_H
#include <systemc.h>

SC_MODULE(WAVEFORM_GENERATOR), public bus_intfc
{

    sc_signal<uint<16>> period;
    sc_signal<uint<10>> amplitude;
    sc_out<double> output; // limited between -10 and +10
    sc_in<bool> clk;

    virtual void write(sc_uint<16> data, sc_uint<32> address)
    {
        switc(address)
        {
        case 0:
            period.write(data);
            break;
        case 2:
            amplitude.write((double)data(9, 0) / 51.1);
            break;
        }
    }

    virtual sc_uint<16> read(sc_uint<32> address)
    {
    }

    void sin_wave()
    {
        while (1)
        {
            for (int i = 0; i < period.read(); i++)
            {
                wait(clk.posedge_event());
                out.write(amplitude * sin(2 * pi * i / period.read()));
            }
        }
    }
}

#endif
