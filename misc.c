#include <string.h>

void klaud_ascii() {
    puts(                                                                               
    "                                        .       ,(       \r\n"             
    "                                     , (,.*/ ,,          \r\n"         
    "                      ,..         .****(,,,&#     ,,(    \r\n"          
    "                         ****, .,,&&&&&**#(##/.***       \r\n"               
    "                                 (,**/#((#(###/..,..../  \r\n"       
    "                     .....,,,***(((,,**#/*/###/          \r\n"                  
    "                             .*((,,,*,,..,*((#           \r\n"   
    "                       .,, /   **/,,*,***((((#*          \r\n"           
    "                               ,*,(./,#(######(          \r\n"                
    "                              **,,.,..*,,,**//(/         \r\n"               
    "                              /*,,,,**,.,,*(#&#(         \r\n"               
    "                             *,*,**#**,,**((#&&#(        \r\n"              
    "                            ,*,*,.....,**/#((//#(        \r\n"               
    );
}

void commands() {
    puts(
        "Commands:\r\n"
        "create: make the file system\r\n"
        "mount: mount file system\r\n"
        "info: file system info\r\n"
        "exit: leave cli\r\n"
    );
}

char * slice_str(const char * str, char * buffer, int start, int end) {
    int j = 0;
    for (int i = start; i <= end; ++i) {
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
    return buffer;
}