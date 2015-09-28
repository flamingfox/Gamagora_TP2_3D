#ifndef OPBIN_H
#define OPBIN_H


class OpBin
{
public:
    OpBin(const ObjetCsg& _a, const ObjetCsg& _b);

protected:
    ObjetCsg a, b;
};

#endif // OPBIN_H
