#include <stdlib.h>
#include <stdio.h>
#include "hw1Struct.h"

#define LINE_SIZE 82
/* usage: executable_name file_name */
int main(int argc, char**argv) {
 	
	FILE *fp = NULL;	

	char buf[LINE_SIZE];

	if(argc !=2){
	
	   snprintf(buf, LINE_SIZE, "Usage: %s filename\n", argv[0]);	
	   fputs(buf, stderr);

	   return 1; 
	}
	
	/* comment */
	fp = fopen(argv[1], "r");

	if(fp==NULL){
	
	   /* can use errno?? */

	   perror("File Open");
	   return 2;
	}

	/* get a line at a time and write to a temporary file
 	 * so that we can handle each of the "records" */
	int len = sizeof(ProblemData);
	ProblemData *temp_buf = (ProblemData*)(malloc(len));
	ProblemData* temp;
	fseek(fp, (long) 0, SEEK_END);
	long pos = ftell(fp);
	while(fread(temp_buf,len ,1, fp) != 0){

	   if(temp_buf[0].h.type == 1){

	   }	

 	}	
  return 0;
}	
