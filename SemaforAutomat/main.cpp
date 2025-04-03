#include "SemaforDKA.h"

#define dugiTajmer 2 //Vrijeme trajanja Crvenog/Zelenog Svjetla
#define kratkiTajmer 1 //Vrijeme Trajanja Zutog svijetla

void Pravila();
void PokreniAutomat(SemaforDKA T);

int main() {
    SemaforDKA Semafor(dugiTajmer, kratkiTajmer);
    Pravila();
    PokreniAutomat(Semafor);
}

void PokreniAutomat(SemaforDKA T) {
    char slovo;
    while ((slovo = std::getchar()) != 'q') {
        if (slovo == 'c') {
            T.SenzorInfo(true);
            LOG(" - Auto Detektovano na Sporednoj Cesti - ");
        }
        if (slovo == 'v') {
            T.SenzorInfo(false);
           LOG(" - Nema vise auta na Sporednoj Cesti - ");
        }

        T.loop();
        Cekaj(1s);
    }

};

void Pravila() {
    LOG ( "Dobrodosli u Implementaciju Semafora kao Konacni automat" );
    LOG ( "Autor: Adin Jahic, Broj Indexa: II-80, Predmet: Automati i Formalni Jezici" );
    LOG ( "Datum izrade: 29.04.2024" );
    LOG ( "-----------------------------------------------------------------------------" );
    LOG ( "Pravila i Pretpostavke:" );
    LOG ( "1.) Glavna i Sporedna cesta imaju 4 stanja: " );
    LOG ( "   S1) GlavnaCestaZeleno (Sporedna Crveno)" );
    LOG ( "   S2) GlavnaCestaZuto (Sporedna Crveno)" );
    LOG ( "   S3) SporednaCestaZeleno (Glavna Crveno)" );
    LOG ( "   S4) SporednaCestaZuto (Glavna Crveno)" );
    LOG ( "2.) Dok se auto ne detektuje senzorom na sporednoj cesti glavna cesta ostaje u Stanju S1" );
    LOG ( "3.) Detekcija Auta sa sporedne ceste se simulira pritiskom tipke 'c' " );
    LOG ( "4.) Dok je pritisnuta tipka stanja se mijenjaju od S1-S2-S3-S4 " );
    LOG ( "5.) Duzina Trajanja stanja (zelenog/crvenog i zutog svijetla) je odredjena tajmerima" );
    LOG ( "6.) Pritiskom na tipku 'v' sklanjamo auta sa sporedne ceste i vracamo se u stanje S1" );
    LOG ( "7.) Pritiskom na tipku 'q' Prekidamo simulaciju" );
    LOG ( "-----------------------------------------------------------------------------" );
    LOG ( "Polazno stanje: (pritisnite c za detekciju auta sa sporedne ceste) " );
    LOG ( "{S1} - Glavna Cesta Zeleno, Sporedna Crveno ")
}
