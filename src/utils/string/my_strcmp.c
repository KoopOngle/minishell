/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** str cmp
*/

int my_strcmp(char *s1, char *s2)
{
	int i = 0;
	int calcul = 0;

	while (s1[i] != '\0' && s2[i] != '\0') {
		calcul += s1[i] - s2[i];
		if (s1[i] == s2[i])
			i++;
		else
			break;
	}
	return (calcul);
}
