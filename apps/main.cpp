/// Programme LogisSim :
/// -------------------------------------------------
///
/// INFO 7-9-10
///
/// Date création : 23/03/2022
///
/// Date de dernière modification : 28/03/2022
///
/// Auteurs : Antonin CLAUD, Raphaël DE MAGALHAES
///
/// Polytech Clermont
///
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstring>

#include "composant.h"
#include "AND.h"
#include "OR.h"
#include "NAND.h"
#include "NOR.h"
#include "BUFFER.h"
#include "NOT.h"
#include "SIGNAL.h"

using namespace std;

// Fonction de génération de la pile d'Entrée/Sortie
vector<vector<string> > gen_pile_es(string chemin_fichier){
    vector<vector<string> > ENTREE;
    string temp;
    ifstream fin(chemin_fichier);

    while (!fin.eof()){
        getline(fin,temp,'\n');
        stringstream ss(temp);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> IN(begin, end);

        ENTREE.push_back(IN);
        IN.clear();
    }
    fin.close();
    return ENTREE;
}

// Fonction de génération de la pile d'Event
vector<string> gen_pile_event(string chemin_fichier){
    vector<string> SIG;
    ifstream fin(chemin_fichier);
    char ch;
    while (fin.get(ch)){
        //cout << ' ' << ch;
        if(ch == '-'){
            SIG.push_back("1");
        }
        else if (ch == '_') {
            SIG.push_back("0");
        }
    }
    fin.close();
    return SIG;
}

// Fonction d'affichage des infos de la pile
void affiche_pile(vector<vector<string> > pile){
    vector<vector<string> > temp_q = pile;
    vector<string> q_element;
    for (int i=0;i<temp_q.size();i++)
    {
        q_element = temp_q[i];

        cout << "[";
;        for (int j=0;j<q_element.size();j++){
            cout << q_element[j] << ",";
        }
        cout << "]" << endl;
    }
    cout << endl;
}

// Fonction d'affichage des données d'un vector
void affiche_vector(vector<string> vect){
    cout << "[";
    for (int j=0;j<vect.size();j++){
        cout << vect[j] << ",";
    }
    cout << "]" << endl;
    cout << endl;
}

// Fonction pour rechercher les composants contenant un noeud donné en entrée
vector<vector<string> > recherche_composant(string noeud,vector<vector<string> > Pile_ES){
    vector<vector<string> > composants_trouver;
    for (int i = 0;i<Pile_ES.size();i++){
        vector<string>::iterator it = find(Pile_ES[i].begin(), Pile_ES[i].end(), noeud);
        if (it != Pile_ES[i].end()){
            composants_trouver.push_back(Pile_ES[i]);
        }
    }
    return composants_trouver;
}

// Fonction d'affectation des infos de la pile Event sur les composants (PAS UTILISEE)
void affect_ev_pile(vector<vector<string>> Pile_EVENT,Composant &porte)
{
    vector<string> q_element;
    for (int i=0;i<Pile_EVENT[0].size();i++)
    {
        porte.A = Pile_EVENT[0][i];
        porte.B = Pile_EVENT[1][i];
        porte.Afficher();
    }
}

// Fonction d'affectation des données des piles sur les signaux
void affect_signaux_pile(vector<vector<string>> Pile_ES,vector<vector<string>> Pile_EVENT,SIGNAL &obj)
{
    vector<string> q_element;
    for (int i=0;i<Pile_ES.size();i++)
    {
        q_element = Pile_ES[i];
        for (int j=0;j<q_element.size();j++)
        {
            if (q_element[j] == obj.nom)//if ((q_element[j] == "INPUT") || (q_element[j] == "OUTPUT"))
            {
                //if (obj.nom == "")
                //{
                    obj.Afficher();
                    obj.type = q_element[j+2];
                    obj.noeud = q_element[j+1];
                    cout << "-------------------" << endl << endl;
                    obj.Afficher();
                    cout << "-------------------" << endl << endl;
                //}
            }
        }
    }
}

// Fonction d'affectation des noeuds des piles sur les composants
void affect_noeud_pile(vector<vector<string>> Pile_ES,vector<vector<string>> Pile_EVENT,Composant &obj)
{
    vector<string> q_element;
    for (int i=0;i<Pile_ES.size();i++)
    {
        q_element = Pile_ES[i];
        for (int j=0;j<q_element.size();j++)
        {
            if (q_element[j] == obj.type)
            {
                if ((q_element[j] == "NOT") || (q_element[j] == "BUFFER"))
                {
                    obj.Afficher();
                    obj.nom = q_element[j-3];
                    obj.AffecterNoeud(q_element[j-2],"",q_element[j-1]);
                    obj.Afficher();
                }
                else
                {
                    obj.Afficher();
                    obj.nom = q_element[j-4];
                    obj.AffecterNoeud(q_element[j-3],q_element[j-2],q_element[j-1]);
                    obj.Afficher();
                }
                cout << "-------------------" << endl << endl;
            }
        }
    }
}

int main()
{
    // Permet de rentrer les fichier à la main
    /*string dossier = "LogicSim_TXT\\";
    string extension_cir =".cir";
    string nom_circuit;
    cout << "Entrer le nom du circuit(.cir)" << endl;
    cin >> nom_circuit;
    string fichier1 = dossier+nom_circuit+extension_cir;*/

    /*string extension_stm =".stm";
    string entree_a;
    cout << "Entrer le nom du fichier de l'entree A (.stm)" << endl;
    cin >> entree_a;
    string entree_b;
    cout << "Entrer le nom du fichier de l'entree A (.stm)" << endl;
    cin >> entree_b;

    string fichier2 = dossier+entree_a+extension_stm;
    string fichier3 = dossier+entree_b+extension_stm;*/

    string fichier1 = "LogicSim_TXT\\circuit_10.cir";

    vector<vector<string> > Pile_ES = gen_pile_es(fichier1);

    cout << "AFFICHAGE DE LA PILE D'ENTREE/SORTIE : " << endl;
    affiche_pile(Pile_ES);

    string fichier2 = "LogicSim_TXT\\circuit_10_IN_A.stm";
    string fichier3 = "LogicSim_TXT\\circuit_10_IN_B.stm";

    vector<vector<string> > Pile_EVENT;
    Pile_EVENT.push_back(gen_pile_event(fichier2));
    Pile_EVENT.push_back(gen_pile_event(fichier3));

    cout << "AFFICHAGE SIGNAL IN_A: " << endl;
    affiche_vector(Pile_EVENT[0]);

    cout << "AFFICHAGE SIGNAL IN_B: " << endl;
    affiche_vector(Pile_EVENT[1]);

    /*
    string nA = "1000";
    cout << "Recherche des composants contenant le noeud A : " << nA << endl;
    vector<vector<string> > composants_trouver = recherche_composant(nA,Pile_ES);
    affiche_pile(composants_trouver);

    nA = "1001";
    cout << "Recherche des composants contenant le noeud A : " << nA << endl;
    composants_trouver = recherche_composant(nA,Pile_ES);
    affiche_pile(composants_trouver);

    nA = "1003";
    cout << "Recherche des composants contenant le noeud A : " << nA << endl;
    composants_trouver = recherche_composant(nA,Pile_ES);
    affiche_pile(composants_trouver);

    cout << "Taille Pile Event " << Pile_EVENT.size() << endl;
    cout << "EVENT      |IN_A|IN_B" << endl;
    for (int j = 0;j<Pile_EVENT[0].size();j++){
        cout << "event " << j+1 <<"000" << " : "<< Pile_EVENT[0][j] << " | " << Pile_EVENT[1][j] <<endl;
    }
    cout << endl;
    */

    SIGNAL A("IN_A","","","");
    SIGNAL B("IN_B","","","");
    SIGNAL C("OUT_C","","","");
    SIGNAL D("OUT_D","","","");

    NAND porte1;
    OR porte2;
    NOT porte3;
    BUFFER porte4;
    NOR porte5;
    AND porte6;


    cout << endl << "Affectation noeud : " << endl;
    affect_signaux_pile(Pile_ES,Pile_EVENT,A);
    affect_signaux_pile(Pile_ES,Pile_EVENT,B);
    affect_signaux_pile(Pile_ES,Pile_EVENT,C);
    affect_signaux_pile(Pile_ES,Pile_EVENT,D);
    affect_noeud_pile(Pile_ES,Pile_EVENT,porte1);
    affect_noeud_pile(Pile_ES,Pile_EVENT,porte2);
    affect_noeud_pile(Pile_ES,Pile_EVENT,porte3);
    affect_noeud_pile(Pile_ES,Pile_EVENT,porte4);
    affect_noeud_pile(Pile_ES,Pile_EVENT,porte5);
    affect_noeud_pile(Pile_ES,Pile_EVENT,porte6);


    A.Afficher();
    vector<vector<string> > comp1,comp2;
    vector<string> s1,s2;
    vector<vector<string> >t_s;
    int taille_vect =0;

    // Propagation des valeurs sur les portes

    for (int i = 0; i<Pile_EVENT[0].size();i++){

        A.val = Pile_EVENT[0][i];
        B.val = Pile_EVENT[1][i];
        cout << "EVENT VALUE A: " << A.val << " EVENT VALUE B: " << B.val << endl;
        comp1 = recherche_composant(A.noeud,Pile_ES);
        affiche_pile(comp1);
        for (int j = 0;j<comp1.size();j++){
            taille_vect = comp1[j].size();
            if (comp1[j][taille_vect-1]=="AND"){
                porte6.AffecterEntree(A.val,B.val);
                porte6.propagation();
            }
            else if (comp1[j][taille_vect-1]=="NAND"){
                porte1.AffecterEntree(A.val,B.val);
                porte1.propagation();
            }
            else if (comp1[j][taille_vect-1]=="NOR"){
                porte5.AffecterEntree(A.val,B.val);
                porte5.propagation();
            }
            else if (comp1[j][taille_vect-1]=="OR"){
                porte2.AffecterEntree(A.val,B.val);
                porte2.propagation();
            }
            else if (comp1[j][taille_vect-1]=="NOT"){
                porte3.AffecterEntree(A.val,B.val);
                porte3.propagation();
            }
            else {
                porte4.AffecterEntree(A.val,B.val);
                porte4.propagation();
            }

            comp2 = recherche_composant(C.noeud,Pile_ES);
            if(comp2[1][comp2[1].size()-1]=="AND"){
                C.val = porte6.S;
            }
            else if(comp2[1][comp2[1].size()-1]=="NAND"){
                C.val = porte1.S;
            }
            else if(comp2[1][comp2[1].size()-1]=="NOR"){
                C.val = porte5.S;
            }
            else if(comp2[1][comp2[1].size()-1]=="OR"){
                C.val = porte2.S;
            }
            else if(comp2[1][comp2[1].size()-1]=="NOT"){
                C.val = porte3.S;
            }
            else {
                C.val = porte4.S;
            }
        }
        s1.push_back(C.val);
    }
    t_s.push_back(s1);

    // Affichage du signal de sortie
    for (int i = 0;i<t_s.size();i++){
        cout << "SORTIE_" << i << endl;
        for (int j = 0;j<t_s[i].size();j++){
                if (t_s[i][j]=="1"){
                    cout << "-";
                }
                else {
                    cout << "_";
                }
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
