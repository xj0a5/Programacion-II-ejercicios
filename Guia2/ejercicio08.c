#include <stdio.h>
#include <string.h>

int main (void){
int i, j = 0;
int lista [10];
for (i = 1; i < 10; i++, j++){
lista [i] = j++;
}
for (i = 5; i < 10; i++){
printf (" %d\n", lista [i]);
}
return 0;
}