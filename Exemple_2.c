#include <stdio.h>
#include <string.h>

// Funció per validar el número de sèrie
int validarSerial(const char *serial) {
    // Valor predefinit per a la suma dels caràcters ASCII del número de sèrie
    const int valorPredefinit = 1000;
    
    // Calcular la suma dels valors ASCII dels caràcters del número de sèrie
    int suma = 0;
    for (int i = 0; i < strlen(serial); i++) {
        suma += (int)serial[i]; // Sumar el valor ASCII de cada caràcter
    }

    // Comparar la suma calculada amb el valor predefinit
    if (suma == valorPredefinit) {
        return 1; // Número de sèrie vàlid
    } else {
        return 0; // Número de sèrie no vàlid
    }
}

int main() {
    char serialUsuari[20];

    printf("Type serial number: ");
    scanf("%s", serialUsuari);

    // Cridar a la funció per validar el número de sèrie
    if (validarSerial(serialUsuari)) {
        printf("Serial number correct. REGISTRED.\n");
    } else {
        printf("Serial number incorrect.\n");
    }

    return 0;
}