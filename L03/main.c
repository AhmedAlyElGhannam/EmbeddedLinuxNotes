#include <stdio.h>
#include <stdlib.h>

#define str(X) #X

int main(int argc, char *argv[])
{
	printf("%d\n", argc);
	
	if (argv[1] != NULL)
		dprintf(2, "%s\n", argv[1]);

	//while(1);
	return 0;
}
