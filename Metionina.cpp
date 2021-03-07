/*
    Autômato que simula a síntese de proteínas.
    Simula um Ribosomo lendo um RNA
    em busca do Códon de inicialização (Metionina)
    O autômato aceita se o RNA menssageiro
    ou regeita caso contrário. 
*/

#include <iostream>
#include <map>
#include <set>

using   namespace       std;
typedef unsigned int    ui;
typedef string          state;
typedef char            sigma;

int main()
{
    //Inicializando a quíntupla

    //1. S = Estados do autômato
    map<state, ui> ST = {
        {"s0", 0},
        {"s1", 1},
        {"s2", 2},
        {"s3", 3}};

    //Nucleotídeos {Adenina, Guanina, Citosina, Uracila};
    //2. Sigma = alfabeto do autômato
    map<sigma, ui> SG = {
        {'A', 0},
        {'C', 1},
        {'G', 2},
        {'U', 3}};

    //3. delta = tablea de transição do autômato
    state delta[4][4] =
                {/*A,  C,  G,  U*/
         /*s0*/ {"s1", "s0", "s0", "s0"},
         /*s1*/ {"s1", "s0", "s0", "s2"},
         /*s2*/ {"s1", "s0", "s3", "s0"},
         /*s3*/ {"s3", "s3", "s3", "s3"}};

    //4. s0 = Estado inicial
    state start = "s0";

    //5. F = conjunto dos estados finais.
    set<state> final{"s3"};

    string RNAm[10] = {
        {"CGCAUGUAACCUCACUG"},
        {"UCGACUCCGCCACCUGA"},
        {"CAGCACGUUGCAAGGCC"},
        {"AUGCAAUUCGUAGCUG"},
        {"AUGCAACGUUGCAUCG"},
        {"CGAUCAUUAUACGAUG"},
        {"GCCGAUGAUCAUGUGA"},
        {"CGAUUGCAAGCGUCCA"},
        {"UCAGACAUGUCUAGG"},
        {"GCCACUAGUGGUAUA"}};

    //Variáveis auxiliares
    state current;
    ui opt;
    ui idx;

    
    //Escola e impressão da cadeia de RNA a ser testada
    cout << "Escolha um RNA [0-9]: ";
    cin >> opt;
    for(int i = 0; i < RNAm[opt].size(); i++)
        cout << RNAm[opt][i] << " ";
    cout << endl;


    //Inicializando variáveis auxiliares
    current = start;
    idx = 0;
    while (idx < RNAm[opt].size())
    {
        cout << "delta(" << current << ", " << RNAm[opt][idx] << ") = ";
        current = delta[ST[current]][SG[RNAm[opt][idx]]];
        cout << current << endl;
        idx++;
    }

    //Aceita ou Regeita
    if(final.count(current) == true)
        cout << "Aceito:  Sim eh RNA mensageiro!" << endl;
    else
        cout << "Regeita: Nao eh RNA mensageiro!" << endl; 

    return 0;
}