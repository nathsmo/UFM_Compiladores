/* Este file deberia de leer los datos del .txt para poder saber el sistema de referencia que va a 
tomar 
El orden de las cosas es que el nombre del archivo siempre va primero y despues viene el string que 
se quiere probar pero tiene que ser sin espacios.*/

#include <stdio.h>

#define MAXCHAR 1000

int isi(char* point, int index)
{
	index++;
	if (point[index] == '*')
		return 1;
	return 0;	
}

int	match(char *s1, char *s2)
{
	int i1 = 0;
	int i2 = 0;
	int out = 0;
	int continu = 1;
	if (s1[i1] == 'e' && s2[i2] == '\0')
	{
		if (s2[i2] == '\0' && s1[i1] == 'e' && s1[i1+1] == '\0')
			return 1;
		return 0;
	}
	while(s1[i1] && s2[i2] && out == 0)
	{

		if (isi(s1, i1) == 1)
		{
			continu = 0;	
		}
		if (s1[i1] == s2[i2])
		{
			/*printf("Match\n");*/
			if (continu == 1)
				i1++;
			i2++;
		}
		else if (s1[i1] != s2[i2])
		{
			/*printf("No match entre %c y %c\n", s1[i1], s2[i2]);*/
			if (continu == 1 | s1[i1] != '*')
			{
				out = 1;
				return (0);
			}
			i1++;
		}
	}
	return (1);
}

int main(int argc, char** argv) 
{
	char var[100];
	FILE *file;
	int result;
	if (argc != 3)
		return 0;
	file = fopen(argv[1],"r");
	while(fgets(var, sizeof(var), file)!=NULL)
	/*printf("Data read = %s",var);*/
	result = match(var, argv[2]);
	printf("Salio de match con: %d\n", result);
	fclose(file);
	return 0;
}
