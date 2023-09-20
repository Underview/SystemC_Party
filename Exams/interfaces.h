#ifndef INTERFACE_H
#defined INTERFACE_H
class bus_intfc : public sc_interface
{
    virtual void write(sc_uint<32> data, sc_uint<32> address) = 0;
    virtual sc_uint<32> read(sc_uint<32> address) = 0;
};
#endif
