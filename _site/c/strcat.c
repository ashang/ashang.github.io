#include <stdlib.h> // for malloc
#include <string.h> // for strlen strcpy strcat
#include <stdio.h> // for printf

int main () {
    //char * s1, * s2; 

    char *s1, *s2; 
    s1="foo";
    s2="bar"; 

    char *mystr = malloc(strlen(s1)+strlen(s2)+1);

    strcpy(mystr, s1);
    strcat(mystr, s2);

    printf("mystr is %s\n", mystr);
    free(mystr);
    printf("mystr is %s\n", mystr);

}

/**
* in ruby, python

$ python -c 'word = "foo" + "bar"; print(word)'
foobar

$ ruby -e 'word = "foo" + "bar"; puts word'
foobar

$ python -c 'mystr = "foo" + "bar"; print("mystr is ", mystr)'
('mystr is ', 'foobar')

$ ruby -e 'mystr = "foo" + "bar"; puts "mystr is #{mystr}"'
mystr is foobar


*/
