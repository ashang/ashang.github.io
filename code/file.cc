#include <sys/file.h>
#include <stdio.h>
//#include <stdlib.h>

int main(){

    FILE* fp = fopen("/tmp/commands.log", "a+");

    //std::string exec_command="hold a while";
    //const char* exec_command="hold a while";
    ////fputs(exec_command.c_str(), fp);
    fputs("next ", fp);
    fputs("\n", fp); fflush(fp);

    fclose(fp);

    return 0;
}
