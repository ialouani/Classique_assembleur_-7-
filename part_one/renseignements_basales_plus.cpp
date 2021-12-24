#include <cpuid.h>//pour recuperer des infos comme retour fonctionnel
//de __get_cpuid avec les registres de 32 bits classiques en entrees:
//eax,ebx,ecx,edx.(__=>fct.ASM)...
#include <iostream>//TJRS en c++.
#include <map>//for using map<string,string> dict
//ca devient le dict de type map<string,string> un dictionnaire
//telque dict[string s1?]=string s2?.
#include <string>

using namespace std;//pour utiliser std hors du main
//on tape tjrs: using namespace std;(reconnue depuis iostream.h) . ///

//definition d'une structure contenant une fonction
//de protototype: string (renvoie string) nom_fct(::toString()) const
//->ret_CONSTANTE__VALEUR(#).
struct CPUVendorID {
    unsigned int ebx;
    unsigned int edx;
    unsigned int ecx;

    string toString() const {
      //utilisation de la fonction typecast depuis un const char*
      //vers un string (char[] plus facile..(&...))
      //elle s'appelle : reinterpret_cast<const char*(argument$<<>>////.).
      //argument(comme la generecite ### appli. en JS): this(cette
      //structure..)
      //summary: reinterpret_cast<type_avant(const char* ici)>(this)
      //rq: this est un mot cle utilise aussi pour initialiser des objets
      //depuis des classes en Node.js.
        return string(reinterpret_cast<const char *>(this), 12);
    }
};

int main() {
    unsigned int level = 0;
    unsigned int eax = 0;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;

    __get_cpuid(level, &eax, &ebx, &ecx, &edx);//recuperer avec eax=0
    //(accumulateur) et level=0(~core===core0~~~~) l'id du CPU actuel.
    //via un code asm(underscore) (-lib?=>gestionnaire g++ depuis iostream.h)
    //effet de bord sur eax normal car retour sur registre eax<-le nombre
    /*de valeurs maximale que peut ecrire 
le OS sur le registre du cpu eax specifique a cet instant a eax du cpuid
pour obtenir desinfos sur le processeur.
i.e. que par exemple si *(eax)=22 cela voudrait dire que le noyau kernel (noyau
//DE gnu/Linux doit ecrire 22 valeurs un par un (compteur traditionnel) pour faire des operations alternatives et ainsi obtenir un max d'informations sur ce cpu cest a dire sur $(cpuid)| grep nomination_de_valeur_conventionnel1/..__2/... ainsi de suite,etc...   .

    */
    
    CPUVendorID vendorID { .ebx = ebx, .edx = edx, .ecx = ecx };
    //debut avec ebx=ecx=edx=0.(en type.. syntaxe juste en c++)

    map<string, string> vendorIdToName;
    //identificateur du vendeur cad. la section speciale
    ///dans l'entreprise petite qui a cree le cpu en question.
    //ou bien ce dictionnaire(clefs,valeurs) represente::
    //          { (nom_vendeur_commerce,entreprise_gerant_ce__vendeur) }.
    vendorIdToName["GenuineIntel"] = "Intel";
    vendorIdToName["AuthenticAMD"] = "AMD";
    vendorIdToName["CyrixInstead"] = "Cyrix";
    vendorIdToName["CentaurHauls"] = "Centaur";
    vendorIdToName["SiS SiS SiS "] = "SiS";
    vendorIdToName["NexGenDriven"] = "NexGen";
    vendorIdToName["GenuineTMx86"] = "Transmeta";
    vendorIdToName["RiseRiseRise"] = "Rise";
    vendorIdToName["UMC UMC UMC "] = "UMC";
    vendorIdToName["Geode by NSC"] = "National Semiconductor";

    string vendorIDString = vendorID.toString();//actualisation d'un champ de type string en transformant le vendorID en type string sur 12 octets(fait plus sa taille normalement, c'est ok!)
    //this c'est la structure formée a savoir: vendorID (type: (rappel)::
    //struct CPUVendorID{};)
    //=>reinterpreter avec tous les champs en 0 permet
    //de construire sur 12 octets la chaine de type const char* qui vaut en
    //entier: "0..0" (12 0) avec la fonction suivante vendorIdToName.find
    //de l'objet vendorIdToName de type map<string,string> on recupere
    //en type it la recherche de "0..0" dans le dict===vendorIdToName
    //donc it sera=à: **vendorIdToName[0];first_element_DECLARE** et donc
    //par effet de bord, vendorIDString qui etait au debut '0' en sum 12FOIS
    //DEVIENDRA la clef du dictionnaire numero 0(0..0 12 fois en binaire ca
    //fait 0) => vendorIDString vaut "GenuineIntel".

    auto it = vendorIdToName.find(vendorIDString);//valeur de retour
    //type auto permet en parcours fonctionnel de faire un effet de bord
    //sur $1__fct:--vendorIdToName.find / .. .FIND deja definie dans
    //quelconque dict de type map<string,string> (#include<map>).
    //dans tous les cas ca renvoie une valeur DE "Unknown" car le type auto
    //###DU TYPE::     string.((apres un type casting depuis une const d'adresse
    //classique: const char* (un entier sur nbr_champs__structure_ICI:: <=8
    //ca ne sert a rien d'agrandir vue le but de serial_number.cpp)))
    string vendorName = (it == vendorIdToName.end()) ? "Unknown" : it->second;

    //vendorName deviendra tjrs it->second<=>valeur dans le dict de la cle it
    //it->second avec typeof(it)==auto
    //   <=> vendorIdToName[it]==second.(et DONC:: it->second represente
    //selon la structure de VendorIdToName le nom du commercialiseur
    //de ce genre de cpu.)/////
    //affichage des infos avec la cmd. (c++)::: cout << "valeur de a :" <<$a
    //<<   endl .
    cout << "Max instruction ID: " << eax << endl;
    cout << "Vendor ID: " << vendorIDString << endl;
    cout << "Vendor name: " << vendorName << endl;
}
