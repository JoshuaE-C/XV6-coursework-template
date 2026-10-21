#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

void execute_line(char** args) { // takes an array of strings
  int f = fork();

  if(f==0) {
    //child process
    exec(args[0],args); // arg1: command, arg2: pointers holding command in [0] and args after
  } else {
    //parent process
    wait(0);
  }

  // Use fork() to create a child process. Determine if the process
  // is a parent or a child, and run exec() if it is a child, and
  // run wait() if it is a parent.
  // For guidance, the model solution has 9 lines of code.
}


int main(int argc, char *argv[]) {

  // Two pointers: to a command and to a null terminator.
  char *args[2] = {0};
  // Fixed-size storage for reading in a line of input, and a pointer
  // to a particular character in this storage.
  char buf[512], *b;
  // Point b to the first character in the line.

  // Read characters from the standard input. When we find '\n' that
  // means one line has terminated - execute the command.
  fprintf(2, "Please enter command and press enter (type 'q' to exit):\n");
  while (read(0, b, 1) > 0) {
    if (*b != '\n') { //*b = value at pointer, b = current value OF pointer
      buf[b] = *b
      b++;
    } else {
      // store the entered command
      if (buf[0] == 'q' && buf[1] == '') {
        exit()
      }

      execute_line();  
    }
    // Check the current character in b. If it is not special, move the pointer
    // b to the next character and continue reading. If the command string has
    // been fully entered ('\n' is found in b), execute the command by calling
    // execute_line().

    // For guidance, the model solution has 10 lines of code in this loop.
  }
  exit(0);
}
