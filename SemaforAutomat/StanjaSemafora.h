#pragma once
// Pretpostavka:
// Ako je na glavnoj Zeleno ili Zuto na sporednoj mora biti Crveno i obrnuto 
enum class StanjaSemafora {
    GLAVNA_ZELENO,  // (Glavna cesta Zeleno, Sporedna Crveno) 
    GLAVNA_ZUTO, // (Glavna cesta Zuto, Sporedna Crveno)
    SPOREDNA_ZELENO, // (Sporedna cesta Zeleno, Glavna Crveno)
    SPOREDNA_ZUTO // (Sporedna cesta Zuto, Glavna Crveno)
};
