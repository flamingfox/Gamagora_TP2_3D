#ifndef VOXEL_H
#define VOXEL_H
#include "QVector"

class Voxel
{
public:
    Voxel();
    Voxel(int n);

    const int operator()(int i, int j, int k)const{return v.at(i*_n*_n+j*_n+k);}
    int& operator()(int i, int j, int k){return v[i*_n*_n+j*_n+k];}
private:
    QVector<int>v;
    int _n;
};

#endif // VOXEL_H
