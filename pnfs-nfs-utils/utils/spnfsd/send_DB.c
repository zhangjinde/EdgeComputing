#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/include/mysql/mysql.h"

int main(int argc, char *argv[]){
	MYSQL *connect;
	MYSQL_RES *result;
	MYSQL_ROW row;
	
	char *server = "192.168.163.163"; // mysql_server IP address
	char *user = "root";	// mysql_server Account
	char *password ="system"; // mysql_server Password
	char *database = "tracking"; // use database
	char input[100]; // Query

	printf("[+] Send_DB Start [+]\n");
	connect=mysql_init(NULL);

	//Connect MySQL Server	//Create Session
	if(!mysql_real_connect(connect, server, user, password, "tracking", 0, NULL, 0)){ 
		fprintf(stderr, "%s\n", mysql_error(connect));
		return ;
	}
	printf("FileName : %s\n", argv[1]);
	printf("DS_IP : %s\n", argv[2]);

	sprintf(input, "insert into spnfs (name, DS_IP) VALUES ('%s', '%s')", argv[1], argv[2]);
	
	//send MySQL_Query(insert into)
	mysql_query(connect, input);

	result=mysql_use_result(connect);

	mysql_close(connect); //Close MySQL Server //Close Session

	printf("[+] Send_DB End [+]\n\n");
	
	return 0;
}
