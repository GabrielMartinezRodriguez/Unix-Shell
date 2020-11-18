#include "command.h"

static char *commandName = "pwd";

int pwdExec(char **args) {
    ft_printf("ulises hijo de puta");
}

ExecCommand pwdParse(char **args) {
    if (args == NULL)
        return NULL;
    if (args[0] == NULL)
        return NULL;

    if (ft_strncmp(commandName, args[0], ft_strlen(commandName)) == 0)
        return &pwdExec;
    return NULL;
}

