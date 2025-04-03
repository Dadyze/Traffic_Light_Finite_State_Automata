#include "SemaforDKA.h"

SemaforDKA::SemaforDKA(int longTimer, int shortTimer)
{
    this->trenutnoStanje = StanjaSemafora::GLAVNA_ZELENO;
    this->SenzorAuta =false;
    this->longTimer = longTimer;
    this->shortTimer = shortTimer;
}

void SemaforDKA::loop()
{
    switch (trenutnoStanje) {
    case StanjaSemafora::GLAVNA_ZELENO:
    {
        LOG("{S1} - Glavna Cesta je Zeleno, Sporedna je Crveno.");
        if (SenzorAuta) {
            Cekaj(longTimer*1s);
            trenutnoStanje = StanjaSemafora::GLAVNA_ZUTO;
            break;
        }
        trenutnoStanje = StanjaSemafora::GLAVNA_ZELENO;
        break;

    }
    case StanjaSemafora::GLAVNA_ZUTO:
        LOG("{S2} - Glavna Cesta je Zuto, Sporedno je jos Crveno.");
        Cekaj(shortTimer * 1s); // ZUTO SVIJETO 
        trenutnoStanje = StanjaSemafora::SPOREDNA_ZELENO;
        break;

    case StanjaSemafora::SPOREDNA_ZELENO:
        if (SenzorAuta) {
            LOG("{S3} - Sporedna Cesta je Zeleno (Auta prolaze), Glavna Cesta je Crveno.");
            Cekaj(longTimer * 1s);
            trenutnoStanje = StanjaSemafora::SPOREDNA_ZUTO;
            break;
        }

        break;
    case StanjaSemafora::SPOREDNA_ZUTO:
        LOG("{S4} - Sporedna Cesta je Zuta, Glavna Cesta je Crvena.");
        Cekaj(longTimer * 1s);
        trenutnoStanje = StanjaSemafora::GLAVNA_ZELENO;
        break;
    }
}

void SemaforDKA::SenzorInfo(bool detected)
{
    this->SenzorAuta = detected;
    if(!detected)
        this->trenutnoStanje = StanjaSemafora::GLAVNA_ZELENO;
}
