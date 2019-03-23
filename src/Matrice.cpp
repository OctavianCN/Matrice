#include "Matrice.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Matrice::Matrice(int n,int m)
{
    linii=n;
    coloane=m;
    mat=new float*[linii];
    for(int i=0;i<linii;i++)
        mat[i]=new float[coloane];
    // am setat nr de linii si de coloane si am alocat matricea dinamic
}
Matrice::Matrice()
{
    linii=0;
    coloane=0;
}
Matrice::Matrice(const Matrice& other)
{
    linii=other.linii;
    coloane=other.coloane;
    mat=new float*[linii];
    for(int i=0;i<linii;i++)
        mat[i]=new float[coloane];
    for(int i=0;i<linii;i++)
    {
        for(int j=0;j<coloane;j++)
            mat[i][j]=other.mat[i][j];
    }
}
Matrice::~Matrice()
{
    for(int i=0;i<linii;i++)
        delete [] mat[i];
    delete [] mat;
    // am dezalocat matricea
}
Matrice Matrice:: operator=(const Matrice &A)
{
    linii=A.linii;
    coloane=A.coloane;
    for(int i=0;i<linii;i++)
        delete [] mat[i];
    delete [] mat;
    mat=new float*[linii];
    for(int i=0;i<linii;i++)
        mat[i]=new float[coloane];
    for(int i=0;i<linii;i++)
    {
        for(int j=0;j<coloane;j++)
        {
            mat[i][j]=A.mat[i][j];
        }
    }
    return *this;
}
Matrice Matrice:: operator+(const Matrice &A)
{
    Matrice B(linii,coloane);
    int i,j;

   if((A.linii!=linii)||(A.coloane!=coloane))
    {
        cout<<"Nu se poate efectua adunarea\n";
        throw "Nu se poate efectua adunarea\n";
    }

    for(i=0;i<linii;i++)
    {
        for(j=0;j<coloane;j++)
        {
            B.mat[i][j]=A.mat[i][j]+mat[i][j];//adun fiecare element cu elementul care se afla pe aceeasi pozitie cu el
        }
    }
    return B;
}
float* Matrice::operator[](int i)
{
    return mat[i];
}
Matrice Matrice:: operator-(const Matrice &A)
{
    Matrice B(linii,coloane);
    int i,j;
    if((A.linii!=linii)||(A.coloane!=coloane))
    {
        cout<<"Nu se poate efectua scaderea\n";
        throw "Nu se poate efectua scaderea\n";

    }
    for(i=0;i<linii;i++)
    {
        for(j=0;j<coloane;j++)
        {
            B.mat[i][j]=mat[i][j]-A.mat[i][j];// Scad fiecare element cu elementul care se afla pe aceeasi pozitie cu el
        }
    }
    return B;
}
Matrice Matrice:: operator*(const Matrice &A)
{
    int i=0,j=0,k=0,t=0,p=0,s=0;// i si j pentru a parcurge prima matrice iar j si p pentru a o parcurge pe a doua iar k si t pentru a pozitiona pe matricea pe care o calculez
    if(coloane!=A.linii)
    {
        cout<<"Nu se poate efectua inmultirea\n";
        throw "Nu se poate efectua inmultirea";
    }
    Matrice B(linii,A.coloane);
    while(i<linii)
    {
        for(j=0;j<coloane;j++)
            {
                s=s+mat[i][j]*A.mat[j][p];// fac suma din produsul liniei i a matricei initiale si a coloanei p a matricei A
                // p != i deoarece daca matricea ar fi patratica nu merge
               // cout<<mat[i][j]<<" "<<A.mat[j][p];
            }
        B.mat[k][t]=s;
        t++;
        p++;
        s=0;
        if(p>=A.coloane)
        {
            i++;// cresc i-ul deoarece trec la cealalta linie a matricei initiale
            k++;// cresc k-ul deoarece trec la cealalta linie a matricei care rezulta din inmultire
            p=0;//il fac pe p 0 deoarece cand inmultesc plec de fiecare data de la prima coloana
            t=0;//il fac pe t 0 deoarece incep sa pun elemente in matricea rezultata de la prima coloana

        }

    }

    return B;
}
Matrice Matrice::operator*(float scalar)
{
    int i,j;// i si j pentru a parcurge matricea
    Matrice B(linii,coloane);
    for(i=0;i<linii;i++)
    {
        for(j=0;j<coloane;j++)
        {
            B.mat[i][j]=mat[i][j]*scalar;// Inmultesc fiecare element cu scalarul meu
        }
    }
    return B;
}
float Matrice::determinant()
{
    int i=0,j=0; // In i si j retin pozitiile pivotului;
    int k,l; // Cu k si l o sa pargurg matricea;
    float det;// In det tin o sa pun determinantul;
   if(linii!=coloane)
    {
        cout<<"Nu se poate calcula determinantul\n";
        throw "Nu se poate calcula determinantul" ;
    }
    float **mat1; //facem o matrice auxiliara ca sa nu o stricam pe cea principala
    mat1=new float*[linii];
    for(int i=0;i<linii;i++)
        mat1[i]=new float[coloane];
    for(i=0;i<linii;i++)
    {
        for(j=0;j<coloane;j++)
         {
             mat1[i][j]=mat[i][j];
         }
    }
    i=0;
    j=0;
    det=mat1[i][j];
    while(i<=linii-2)
    {
        if(mat1[i][j]==0)
        {
            for(k=i+1;k<linii;k++)
            {
                for(l=j;l<coloane;l++)
                    {
                        mat1[i][l]=mat1[i][l]+mat1[k][l];// ca sa evit cazul neplacut in care pivotul este 0 o sa adun pe linia i toate celelalte linii
                    }
            }
            //cout<<mat[i][j]<<" ";
            det=det*mat1[i][j];
            if(mat1[i][j]==0)
            {
                for(i=0;i<linii;i++)
                delete [] mat1[i];
                delete [] mat1;
                return 0;//Daca pivotul inca este 0 atunci este clar ca o coloana este plina de 0 iar determinantul este 0
            }
        }
        for(k=i+1;k<linii;k++)
        {
            if(mat1[k][j]!=0)
            {
            for(l=coloane-1;l>=j;l--)
            {
            //Parcurg in sens invers deoarece asa mi-as strica primul element de pe linia k si am nevoie de el ca sa il scad si din celelalte elemente
              //cout<<mat[k][l]<<"-"<<mat[k][j]<<"*"<<mat[i][l]<<"/"<<mat[i][j]<<"\n"<<k<<" "<<j<<"=";
                mat1[k][l]=mat1[k][l]-(mat1[k][j]*mat1[i][l])/mat1[i][j];

            // aici fac 0 -uri pe coloana pivotului meu si am scazut din fiecare element de pe fiecare linie (PrimulElem de pe linie * Elem de pe linia pivotului si de pe coloana elementului)/pivot
            }
            }

        }
        j++;
        i++;
        if(mat1[i][j]!=0)
        det=det*mat1[i][j];// daca e 0 sa nu imi strice det pentru ca va fi modificat mat[i][j]
    }
    if(mat1[linii-1][coloane-1]==0)
       {
        for(i=0;i<linii;i++)
        delete [] mat1[i];
        delete [] mat1;
      return 0;   //daca ultimul element e 0 inseamna ca la final nu o sa se inmulteasca cu el desi trebuie asta deci in concluzie det ar fi 0
       }

  for(i=0;i<linii;i++)
        delete [] mat1[i];
    delete [] mat1;
    return det;
}
bool Matrice::inversabilitate()
{
    bool inversabil=true;
    // O matrice este inversabila doar daca are determinantul diferit de 0
    if(determinant()==0)
        inversabil=false;
    if(inversabil==true)
    {
        cout<<"\nMatricea este inversabila\n";
        return inversabil;
    }
    cout<<"\nMatricea nu este inversabila\n";
    return inversabil;
}
void Matrice::EliminareLiniiSiColoane(int n,int m)
{
    int i,j;
    for(i=n;i<linii-1;i++)
    {

        for(j=0;j<coloane;j++)
        {
            mat[i][j]=mat[i+1][j];

        }
    }
    linii--;
    for(i=0;i<linii;i++)
    {
        for(j=m;j<coloane-1;j++)
        {
            mat[i][j]=mat[i][j+1];
        }
    }
    coloane--;
}
void Matrice::EliminareLinie(int n)
{
    int i,j;
    for(i=n;i<linii-1;i++)
    {

        for(j=0;j<coloane;j++)
        {
            mat[i][j]=mat[i+1][j];

        }
    }
    linii--;
}
void Matrice::EliminareColoana(int n)
{
    int i,j;
    for(i=0;i<linii;i++)
    {
        for(j=n;j<coloane-1;j++)
        {
            mat[i][j]=mat[i][j+1];
        }
    }
    coloane--;
}
int Matrice::GetLinii()
 {
     return linii;
 }
int Matrice::GetColoane()
{
    return coloane;
}
ostream &operator << (ostream &out, const Matrice &A)
{
    int i,j;
    for(i=0;i<A.linii;i++)
    {
        for(j=0;j<A.coloane;j++)
        {
            out<<A.mat[i][j]<<" ";
        }

        out<<"\n";
    }
    return out;
}
istream &operator >> (istream &in, Matrice &A)
{
    int i,j;
     for(i=0;i<A.linii;i++)
    {
        for(j=0;j<A.coloane;j++)
        {
            in>>A.mat[i][j];
        }
    }
    return in;
}


