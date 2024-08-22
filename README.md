# Project Simple Shell

**Description**

The Simple Shell project is a Unix command interpreter implemented in C, created as part of the Holberton School curriculum. This project provides an in-depth understanding of how shells work, including process creation, command parsing, and handling environment variables. The shell replicates basic functionalities found in the Bourne shell (sh) and adheres to the constraints of the project, such as memory management and code style.

## Installation

1. Clone repository

        git clone https://github.com/UsagerLambda/holbertonschool-simple_shell.git

2. Compile the source files

        gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Features

- **Interactive Mode:**
  - Displays a prompt and waits for the user to enter a command.
  - Executes commands in a loop until the user exits.
- **Non-Interactive Mode:**
  - Executes commands from a file or a piped input.
- **Built-in Commands:**
  - 'exit': Exits the shell.
  - 'env': Prints the current environment.
- **Path Handling:**
  - Searches and executes commands located in the directories listed in the 'PATH' environment variable. 
- **Error Handling:**
  - Displays appropriate error messages when commands fail.

## Examples

*Interactive Mode Example:*

        $ ./hsh
        ($) /bin/ls
        file1 file2 file3
        ($) exit
        $

*Non-Interactive Mode Example:*

        $ echo "/bin/ls" | ./hsh
        file1 file2 file3
        $

## Running Tests

*Test Interactive Mode:*

        ($) /bin/ls

*Test Non-Interactive Mode:*

        echo "/bin/ls" | ./hsh

*Test Built-in Commands:*

        ($) env

*Test PATH Handling:*

        ($) ls

*Test Exit Command:*

        ($) exit

## Compilation

        gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Files

- *header.h*: Header file containing function prototypes and type definitions.

- *main.c*: The entry point for the simple shell program. It initializes the shell, either in interactive or non-interactive mode, based on command-line arguments.

- *open_shell.c*: Implements the `open_shell` function, which runs the shell in interactive mode, displaying a prompt and processing user input.

- *check_line_ptr.c*: Checks if a string is non-empty and non-whitespace.

- *use_argv.c*: Handles command-line arguments for non-interactive mode, tokenizing them and executing the corresponding commands.

- *parse.c*: Contains the `parse` function, which tokenizes the input command line into individual arguments.

- *builtin_cmd.c*: Contains the implementations of built-in shell commands, including `shell_env` (prints environment variables) and `shell_exit` (exits the shell).

- *execute_builtin.c*: Implements the `execute_builtin` function, which checks if a command is a built-in command and executes it if it is.

- *which_path.c*: Implements the `which_path` function, which searches for the command in the directories listed in the PATH environment variable and executes it.

- *it_exist.c*: Contains the `it_exist` function, which checks if a command exists in a specified directory and executes it if found.

- *execute.c*: Contains the `execute` function, which forks a process and runs a command using `execve`.

- *errors.c*: Implements the `errors` function, which prints error messages and exits the program when a critical failure occurs.

## Function Descriptions

`int execute_builtin(char **args, char *command, char *envp[], char *line_ptr);`
- *Executes a built-in shell command if it matches the input.*

`int shell_exit(char **args, char *line_ptr, int exit_status);`
- *Exits the shell.*

`int shell_env(char **args, char *envp[]);`
- *Prints the environment variables.*

`int open_shell(int argc, char *argv[], char *envp[]);`
- *Runs the shell in interactive mode, displaying a prompt and processing user input.*

`int check_line_ptr(char *str);`
- *Checks if a string is non-empty and non-whitespace.*

`int use_argv(int argc, char *argv[], char *envp[]);`
- *Handles command-line arguments in non-interactive mode.*

`void parse(char *line_ptr, char *tokens[], int *nb_tokens);`
- *Tokenizes a command line into individual arguments.*

`void which_path(char **tokens, int nb_tokens, char *envp[]);`
- *Finds the full path of a command and executes it.*

`void errors(int code, char *str, char *tok[]);`
- *Prints an error message and exits the program.*

`int it_exist(char *dir, char *tokens[], int nb_tokens, char *envp[]);`
- *Checks if a command exists in a specified directory and executes it if found.*

`void execute(char *path, char *tokens[], char *envp[]);`
- *Forks a child process to execute a command.*

## Authors

- [@UsagerLambda](https://www.github.com/UsagerLambda)

- [@EmaD3c](https://www.github.com/EmaD3c)

## Flowchart

```mermaid
flowchart TD
    A[Début] --> B{Nombre d'arguments < 2 ?}
    B -- Oui --> C[Appeler open_shell]
    B -- Non --> D[Appeler use_argv]
    C --> E[Afficher le prompt]
    E --> F[Lire la ligne de commande avec getline]
    F --> G{EOF ou Ctrl + D}
    G -- Oui --> H[Libérer mémoire et quitter]
    G -- Non --> I[Supprimer le saut de ligne]
    I --> J[Diviser la ligne en tokens]
    J --> K{Commande intégrée ?}
    K -- Oui --> L[Exécuter commande intégrée]
    K -- Non --> M[Trouver le chemin de la commande]
    L --> E
    M --> N{Chemin trouvé ?}
    N -- Oui --> P[Exécuter la commande]
    N -- Non --> Q[Afficher une erreur]
    P --> E
    Q --> E
    D --> R[Diviser argv en tokens]
    R --> M
    H --> S[Fin]

    classDef startEnd fill:#ff5733,stroke:#333,stroke-width:2px;
    classDef condition fill:#ffff99,stroke:#333,stroke-width:2px;
    class A,H,S startEnd;
    class B,G,K,N condition;
