#include "shit.h"

int		main(void)
{
	char	**line;

	line = (char **)ft_calloc(1, sizeof(char *));
	get_next_line(0, line);
	ft_strtrim(*line, ' ');
	printf("%s", line[0]);
	return (0);
}