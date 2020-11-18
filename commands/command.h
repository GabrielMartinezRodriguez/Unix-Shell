#ifndef COMMAND_H
# define COMMAND_H

# include "../lib/lib.h"

typedef     int         (*ExecCommand)(char **);
typedef     ExecCommand (*ParseCommand)(char **);

typedef enum {
    ALWAYS,
    SUCCESSFUL,
    FAILED
} Condition;

typedef struct {
    Condition   condition;
    char        **args;
    ExecCommand exec;
} Command;

typedef enum {
    PIPE,
    FILE,
    FILE_APPEND
} OutputType;

typedef struct {
    Command         *command;
    int             inputFile; 
    OutputType      outputType;
    CommandBuffer   *next;
} CommandBuffer;

ExecCommand pwdParse(char **args);

ParseCommand CommandParseList[] = {
    &pwdParse
};
 

#endif