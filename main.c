#include <stdio.h>
#include <string.h>

int main() {

	// Telling
	int tel = 1;
	int count;
	char done[20];

	// Opslaan van woorden
	int c = 0;		  // Index van de array in de main array.
	int d = 0;	      // Index in de 1e array.
	char arr[20][20]; // 2D Array, (20 woorden en 20 in lengte max).

	// Input
	char *woord;
	char zin[75];

	printf("Geef een zin op: ");
	fgets(zin, 75, stdin);

	for (int i = 0; i < strlen(zin)+1; ++i)
	{
		if (zin[i] == ' ' || zin[i] == '\0') { // Einde van woord gevonden
			arr[c][d] = '\0';
			d = 0; 							  // Volgende [c] beginnen bij 0 oftewel de eerste letter.
			c++;
		} else {
			arr[c][d] = zin[i];				  // Letter van het woord opslaan
			d++; 							  // Index voor de volgende letter 
		}
	}
	
	for (int i = 0; i < c; i++) {
		tel = 1;
		count = 0;
        woord = arr[i];

        // Als het woord al geteld is, continue
        for (int z = 0; z < strlen(done); ++z) {
        	if (*woord == done[z]) {
        		tel = 0;
        		break;
        	}
        }

        if (tel) {
			for (int y = 0; y < c; ++y) {
				if (*woord == *arr[y]) {
					count++;
				}
			}
			printf("%s: %d\n", woord, count);
			done[i] = *woord;
		}
    }

	return 0;
}
