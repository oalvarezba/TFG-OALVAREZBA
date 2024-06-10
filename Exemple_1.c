#include <stdio.h>
#include <string.h>

// Funció per validar el número de sèrie
int validarSerial(const char *serial) {
    // Número de sèrie predeterminat
    const char *serialCorrecte = "TFG_OALVAREZBA";

    // Comparar el número de sèrie entrat amb el número de sèrie correcte
    if (strcmp(serial, serialCorrecte) == 0) {
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
        printf("Serial number correct. REGISTRED\n");
    } else {
        printf("Serial number incorrect.\n");
    }

    return 0;
}


