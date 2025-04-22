#include "shell.h"

/**
 * _strcmp - Compara dos cadenas de caracteres.
 * @s1: Primera cadena a comparar.
 * @s2: Segunda cadena a comparar.
 *
 * Return: Un valor negativo si s1 es menor que s2, un valor positivo si
 * s1 es mayor que s2, o 0 si ambas cadenas son iguales.
 *
 * Descripción: Esta función compara dos cadenas de caracteres de mara
 * lexicográfica. Recorre ambas cadenas carácter por carácter y delve
 * la diferencia entre el primer par de caracteres que no son iguales,
 * Si las cadenas son iguales, retorna 0.
 */
int _strcmp(const char *s1, const char *s2)
{
	/* Recorremos ambas cadenas mientras ambos caracteres sean diferentes*/
	while (*s1 && *s2)
	{
		/* Si los caracteres no son iguales, retornamos la diferencia*/
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		/* Avanzamos al siguiente carácter de s*/
		s2++;
		/* Avanzamos al siguiente carácter de s*/
	}

	/* Si las cadenas son iguales hasta un punto, se compara el último carácr*/
	return (*s1 - *s2);
	/* Si son iguales, devuelve 0, si no, la diferencia*/
}
