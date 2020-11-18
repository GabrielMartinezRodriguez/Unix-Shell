#ifndef COMMAND_H
# define COMMAND_H

# include "../lib/lib.h"

typedef enum {
    ALWAYS,
    SUCCESSFUL,
    FAILED
} Condition;

typedef struct {
    Condition   condition;
    char        **args;
} Command;

typedef struct {
    Command         *command;
    int             pipe; //Debe crear un pipe para el siguiente comando
    int             inputFile; // Debe leer de fichero
    int             outputFile; // Debe escribir en fichero - Tiene mayor prioridad que el pipe
    CommandBuffer   *next;
} CommandBuffer;

typedef     int         (*ExecCommand)(char **);
typedef     ExecCommand (*ParseCommand)(char **);


extern ParseCommand ls; 
extern ParseCommand pwd;


#endif