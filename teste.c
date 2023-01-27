#include <stdio.h>
#include <stdlib.h>
void func(int a){
    a = 15;
    printf("%d",a);
}
int main(){

    func(5);
}