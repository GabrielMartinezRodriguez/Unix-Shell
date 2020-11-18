#include "command.h"

CommandBuffer *processInput(char *input) {
    //Trim y quitar espacios
    //Separadores logicos && || ;
    //Separadores de redireccionamiento de salida y entrada | > < >>
    // Tener en cuenta que dentro de comillas "" '' no afectan los separadores 

    char            *trimed;
    char            **words;
    CommandBuffer   *commandBuffer;

    trimed = ft_strtrim(input, ' ');
    if (trimed == NULL)
        return NULL;
    words = ft_split(trimed, ' ');
    if (words == NULL)
        return NULL;
    commandBuffer = getCommandBuffer(words);


    
}


//Devuelve la lista de comandos ya procesada
CommandBuffer *getCommandBuffer(char **words) {
    int         i;
    int         ini;
    Condition   lastCondition = ALWAYS; // Guarda el operador logico de la ultima division de comandos

    i = 0;
    ini = 0;
    while (words[i] != NULL) { //Cuando encuentra una division logica, procesa la el comando ya pendiente y almacena la condicion logica para ejecutar el comando posterior
        if (words[i + 1] == NULL)
            processCommand(&words[ini], i + 1 - ini, lastCondition);
        else if (ft_strncmp(words[i], "&&", 3) == 0) {
            processCommand(&words[ini], i - ini, lastCondition);
            lastCondition = SUCCESSFUL;
        }
        else if (ft_strncmp(words[i], "||", 3) == 0) {
            processCommand(&words[ini], i - ini, lastCondition);
            lastCondition = FAILED;
        }
        else if (ft_strncmp(words[i], ";", 2) == 0) {
            processCommand(&words[ini], i - ini, lastCondition);
            lastCondition = ALWAYS;
        }
        else if (ft_strncmp(words[i], "|", 2) == 0) {
            processCommand(&words[ini], i + 1 - ini, lastCondition); // el length de process command incluye el | ya que no solo es separador logico tambien es redireccionador de output
            lastCondition = ALWAYS;
        }
        i++;
    }
}

CommandBuffer *processCommand(char **words, int length, Condition condition) {

}


