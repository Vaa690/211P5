#ifndef system_utilities
#define system_utilities

int parseCommandLine(char cline[], char *tklist[]);

void fillSystemCommandList();
int getCommandNumber(char* s);
int convertIntToValue(char* s);

#endif