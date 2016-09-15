
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../ourhdr.h"

int main() {

	char *line;
	char *prompt = "dash>";

	using_history();
	while ((line=readline(prompt))) {
		printf("%s\n",line);
		add_history(line);
		free(line);
	}
	exit(0);

}
