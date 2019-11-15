#include <stdio.h>
#define max 10


void radixsort(int *vet, int n) {
	int i, exp = 1, m = 0, bucket[n], temp[n];

	for(i = 0; i < n; i++) {
		if(vet[i] > m) {
			m = vet[i];
		}
	}

	while((m/exp) > 0) {
		for (i = 0; i < n; i++) {
			bucket[i] = 0;
		}
		for(i = 0; i < n; i++) {
			bucket[(vet[i] / exp) % 10]++;
		}
		for(i = 1; i < n; i++) {
			bucket[i] += bucket[i-1];
		}
		for(i = (n - 1); i >= 0; i--) {
			temp[--bucket[(vet[i] / exp) % 10]] = vet[i];
		}
		for(i = 0; i < n; i++) {
			vet[i] = temp[i];
		}
		exp *= 10;
	}
}

int main() {
	int vetor[max] = {65055372, 65919190, 65147145, 65892478, 65055214, 65452870};
	int i;
	radixsort(vetor,max);
	printf("Vetor ordenado: [ ");
	for (i = 4; i < max; i++) {
		printf("%d ", vetor[i]);
	}
	printf("]");
	return(0);
}
