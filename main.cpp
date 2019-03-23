#include <iostream>
#include <cassert>
#include "Matrice.h"
using namespace std;
void MatriceTest();
void Demo();
int main()
{
    MatriceTest();
    Demo();
    return 0;
}
void MatriceTest()
{

    Matrice A(3,3);
    assert(A.GetColoane()==3);
    assert(A.GetLinii()==3);
    A.EliminareColoana(1);
    assert(A.GetColoane()==2);
    A.EliminareLinie(1);
    assert(A.GetLinii()==2);
    A.EliminareLiniiSiColoane(1,1);
    assert(A.GetLinii()==1);
    assert(A.GetColoane()==1);


}
void Demo()
{
    int n,m,p,q,t;
    cout<<"Scrieti numarul de linii si de coloane a matricei\n";
    cin>>n>>m;
    Matrice A(n,m);
    cout<<"Scrieti elementele matricei \n";
    cin>>A;
    cout<<"\nMatricea scrisa este: \n";
    cout<<A;
    cout<<"\n Numarul de linii al matricei A este: \n";
    cout<<A.GetLinii();
    cout<<"\n Numarul de coloane al matricei A este: \n";
    cout<<A.GetColoane();
    cout<<"\n Scrieti linia la care doresti sa ajungi \n";
    cin>>p;
    float *v=new float[m];
    v=A[p];
    for(int i=0;i<m;i++)
        cout<<v[i]<<" ";
    cout<<"\n";
    Matrice B;
    B=A;
    cout<<"\nMatricea B pentru care am folosit B=A este \n";
    cout<<B;
    cout<<"\nScrieti coloana pe care o sa o eliminam lui B\n";
    cin>>t;
    B.EliminareColoana(t);
    cout<<"\n"<<B;
    cout<<"\nScrieti linia pe care o sa o eliminam lui B\n";
    cin>>t;
    B.EliminareLinie(t);
    cout<<"\n"<<B;
    cout<<"\nScrieti linia si coloana pe care o sa o eliminam din A\n";
    cin>>t>>p;
    A.EliminareLiniiSiColoane(t,p);
    cout<<"\n"<<A<<"\n";
    cout<<"\nScrieti numarul de linii si coloane pentru inca 2 matrice cu care o sa facem adunarea si scaderea(Numarul de linii trebuie sa fie egal cu numarul de coloane)\n";
    cin>>n>>m;
    Matrice C(n,m),D(n,m);
    cout<<"\n Scrieti elementele primei matrice\n";
    cin>>C;
    cout<<"\n Scrieti elementele celei de-a doua matrice\n";
    cin>>D;
    cout<<"\n Suma lor este : \n";
    cout<<C+D;
    cout<<"\n Diferenta lor este: \n";
    cout<<C-D;
    cout<<"\n Scrieti numarul de linii si coloane pentru 2 matrice ce vor fi inmultite(coloanele primei trebuie sa fie egale cu liniile celei de-a doua matrice \n";
    cin>>n>>m;
    cin>>p>>q;
    Matrice E(n,m),F(p,q);
    cout<<"\n Scrieti matricele ce vor fi inmultite\n";
    cin>>E>>F;
    cout<<E*F;
    cout<<"\n Scrieti scalarul cu care va fi inmultita prima matricea E \n";
    cin>>t;
    cout<<E*t;
    cout<<"\n";
    cout<<"Scrieti numarul de linii si de coloane al matricei careia doriti sa ii calculati determinantul si sa ii studiati inversabilitatea\n";
    cin>>n>>m;
    Matrice G(n,m);
    cout<<"\nScrieti elementele matricei\n";
    cin>>G;
    cout<<"\nDeterminantul este: ";
    cout<<G.determinant();
    cout<<"\n si \n";
    G.inversabilitate();
}
