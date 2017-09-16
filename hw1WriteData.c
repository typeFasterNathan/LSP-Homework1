#include <stdlib.h>
#include <stdio.h>
#include "hw1Struct.h"

ProblemData processLine(char* lineStart, char lineEnd);

int main(int argc, char *argv[]) {

  if(argc != 3) {
     printf("error");
  }
  else {
     printf("normal execution\n");
     FILE * inFile = fopen (argv[1], "r" );
     FILE * outFile = fopen (argv[2], "w");
     fseek (inFile , 0 , SEEK_END); //get file size
     int lSize = (int)ftell (inFile);
     printf("%d", lSize);
     rewind (inFile);
     char* buffer = (char*) malloc (sizeof(char)*lSize);
     fread (buffer, 1, lSize, inFile);
     fclose(inFile);
     int lastNewLine = 0;
     int i;
     for(i = 0; i < lSize; i++) {
        while (buffer[i] != '\n') {
           i++;
        }
        ProblemData p = processLine(buffer + i, '\n');
     }
     fwrite (buffer , sizeof(char), lSize, outFile);
     free (buffer);
     fclose (outFile);
  }
  return 0;
}


ProblemData processLine(char* line, char lineEnd) {
   int i = 0;
   ProblemData lineProblem;
   while(line[i] != 'I' && line[i] != 'F') { i++; }
   char unionType = line[i];
   lineProblem.h.type = unionType == 'F' ? 1 : 0;
   return lineProblem;
}
