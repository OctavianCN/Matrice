#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
#include <stdexcept>
using namespace std;
class Matrice
{
    public:
       Matrice();
       Matrice(int n,int m);
       Matrice(const Matrice& other);
        ~Matrice();
       Matrice operator=(const Matrice &A);
       Matrice operator+(const Matrice &A);
       float* operator[](int i);
       Matrice operator-(const Matrice &A);
       Matrice operator*(const Matrice &A);
       Matrice operator*(float scalar);
       float determinant();
       bool inversabilitate();
       void EliminareLiniiSiColoane(int n,int m);
       void EliminareLinie(int n);
       void EliminareColoana(int n);
       int GetLinii();
       int GetColoane();
       friend ostream & operator << (ostream &out, const Matrice &A);
       friend istream & operator >> (istream &in,Matrice &A);

    private:
        int linii,coloane;
        float **mat;
};

#endif // MATRICE_H
