#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int		main()
{
	int		*i;
	/*
	 * printf("%0+++++++++++++++++++5d", 8);
	 * printf("\n");
	 * printf("%+++++++++++++++0++++5d", 8);
	 * printf("\n");
	 * printf("%+++++0000+++++0+++++0++++5d", 8);
	 * printf("\n");
	 */
	/*
	 * printf("%+++++++++   ++++++0++++5d", 8);
	 * printf("\n");
	 */
	/*
	 * printf("%55d", 8);
	 * printf("\n");
	 */
/*
**	printf("%15mdma");
**printf("\n");
**	printf("%-15mdma");
**printf("\n");
**	printf("%1s", "pute");
 */
// printf("%-2-s\n", "Щ不");
// printf("%0s\n", "cgcgcgc");
	/*
	**printf("4567 |%-105d| plip\n", 1);
	**printf("4567 |%105d| plip\n", 1);
	**printf("|%10.5d|\n", -12);
	**printf("|%10d|\n", -12);
	**printf("|%010d|\n", -12);
	**printf("|%-10.5d|\n", -12);
	**printf("|%-010.5d|\n", -12);
	**printf("%3y");
	 */
	//  printf("%####+++++50.1hhhhs", "jujou");
	// printf("%022+55s", "coucouc");
	setlocale(LC_ALL, "");
	printf("1 %ls\n", L"ڤڴط");
	printf("2 %lls\n", L"ڤڴط");
	printf("3 %llls\n", L"ڤڴط");
	printf("4 %lllls\n", L"ڤڴط");
	printf("5 %llllls\n", L"ڤڴط");

	return (0);
}
