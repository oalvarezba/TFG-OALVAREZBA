#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIDA_SERIAL 11 // Longitud màxima de la clau (10 caràcters + '\0')

// Funció per generar una combinació de 10 caràcters utilitzant els caràcters vàlids.
char* generarCombinacio(const char *caracteresValids) {
    char* combinacio = (char*)malloc(MIDA_SERIAL * sizeof(char));

    if (combinacio == NULL) {
        fprintf(stderr, "Error: Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < 10; i++) {
        int indexAleatori = rand() % strlen(caracteresValids);
        combinacio[i] = caracteresValids[indexAleatori];
    }
    
    combinacio[10] = '\0';

    return combinacio;
}

// Funció per sumar tots els caràcters ASCII d'una cadena de text.
int sumaAscii(const char* text) {
    int suma = 0;

    for (int i = 0; i < strlen(text); i++) {
        suma += (int)text[i];
    }

    return suma;
}

// Funció que crea cadenes de text fins que una coincideixi amb el valor predeterminat.
char* generarSerial(const char* valorPredeterminat, const char *caracteresValids) {
    int valor = strtol(valorPredeterminat, NULL, 16);
    char* combinacio = generarCombinacio(caracteresValids);

    while (sumaAscii(combinacio) != valor) {
        free(combinacio); // Allibera la memòria de la combinació anterior.
        combinacio = generarCombinacio(caracteresValids);
    }

    return combinacio;
}

int main() {
    srand(time(NULL)); // Inicialitzar la llavor per generar nombres "aleatoris"

    const char caracteresValids[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char *valorPredeterminat;
    
    printf("Predeterminated value (Hex): ");
    scanf("%ms", &valorPredeterminat);

    char* serial = generarSerial(valorPredeterminat, caracteresValids);
    printf("Valid key: %s\n", serial);
    
    free(valorPredeterminat); // Alliberar la memòria assignada al valor predeterminat.
    free(serial); // Alliberar la memòria assignada al serial.

    return 0;
}