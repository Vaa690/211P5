#include "system_utilities.h"
#include "definitions.h"
#include "stdlib.h"
#include "string.h"
#include <iostream>

using namespace std;

int parseCommandLine(char cline[], char *tklist[]) {
	int string_length, token_length, i, j;
	int next_Token = 0;

	string_length = strlen(cline);
	i = 0;

	while(cline[i] !=0) {

		// Find the next Blank
		while(cline[i]==' ') i++;
		j=i+1; // Set j to the next character

		if(cline[i] !='"') {
			// Keep going through the characters while cline[j] isn't blank
			while(cline[j]!=' ' && cline[j] != 0) j++;
			token_length=j+1 - i;
		}

		else {
			i = i+1;
			j = i+1;
			while(cline[j] != '"') j++;
			token_length = j+1 - i;
			j=j+1;
		}

		tklist[next_Token] = (char* )malloc(token_length);
		memcpy(tklist[next_Token], cline+i, token_length-1);
		tklist[next_Token][token_length-1] = 0;
		next_Token++;
		i = j;
	}

	return next_Token;
}

class COMMAND {

private:
	char *pointer;
	int cmd_num;

public:
	COMMAND();
	COMMAND(char *, int);
	int amIThisCommand(char *);
};

COMMAND::COMMAND() {
	pointer = "null";
	cmd_num = 0;
}
COMMAND::COMMAND(char *cmd, int cmd_int) {
	pointer = cmd;
	cmd_num = cmd_int;
}

int COMMAND::amIThisCommand(char *check_pnt) {
	if(strcmp(pointer, check_pnt) == 0)
		return cmd_num;
	else
		return 0;
}

COMMAND *systemCommands[NUMBER_OF_COMMANDS];

void fillSystemCommandList() {
	systemCommands[0] = new COMMAND("halt", HALT);
	systemCommands[1] = new COMMAND("status", STATUS);
	systemCommands[2] = new COMMAND("time_click", TIME_CLICK);
	systemCommands[3] = new COMMAND("create_device", CREATE_DEVICE);
	systemCommands[4] = new COMMAND("create_event", CREATE_EVENT);
	systemCommands[5] = new COMMAND("set_device_value", SET_DEVICE_VALUE);
	systemCommands[6] = new COMMAND("process_events", PROCESS_EVENTS);
}

int getCommandNumber(char *s) {
	if(strcmp(s, "halt") == 0) 
		return HALT;
    if(strcmp(s, "status") == 0) 
		return STATUS;
    if(strcmp(s, "time_click") == 0) 
		return TIME_CLICK;
    if(strcmp(s, "create_device") == 0) 
		return CREATE_DEVICE;
    if(strcmp(s, "create_event") == 0) 
		return CREATE_EVENT;
    if(strcmp(s, "set_device_value") == 0) 
		return SET_DEVICE_VALUE;
    if(strcmp(s, "process_events") == 0) 
		return PROCESS_EVENTS;
	else
		return UNDEFINED_COMMAND;
}

int convertIntToValue(char* s) {
	// Write an Algorithm that accepts a string and returns an integer value that represents the same number
	int pre_val = 0;
	int conv_val;
	for(int i=0; s[i] != NULL; i++) {
		 conv_val = s[i] - 48;
		 pre_val = (10 * pre_val) + conv_val;
	}
	return pre_val;
}