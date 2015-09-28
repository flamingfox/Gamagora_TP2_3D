#ifndef OPBIN_H
#define OPBIN_H


class OpBin
{
public:
    OpBin(const CsgObjet& _a, const CsgObjet& _b);

protected:
    CsgObjet a, b;
};

#endif // OPBIN_H
