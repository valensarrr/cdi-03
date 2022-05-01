#include <stdio.h>

int main(void) {

    int monto;

    printf ("monto a retirar (entre 20 y 5000 pesos)");
    scanf ("%d", &monto);

    if(monto < 20) {

        printf ("no se puede retirar esa cantidad");
        return 1;
    } 
    else if(monto > 5000) {
        printf ("no se puede retirar esa cantidad");
        return 2;
    }

    int billete1;
    int billete5;
    int billete10;
    int billete20;
    int billete50;
    int billete100;


    for(billete100=0; monto >= 100; billete100++) {
        monto = monto - 100;
    }
    
    for(billete50=0; monto >= 50; billete50++) {
        monto = monto - 50;
    }
    
    for(billete20=0; monto >= 20; billete20++) {
        monto = monto - 20;
    }

    for(billete10=0; monto >= 10; billete10++) {
        monto = monto - 10;
    }

    for(billete5=0; monto >= 5; billete5++) {
        monto = monto - 5;
    }

    for(billete1=0; monto >= 1; billete1++) {
        monto = monto - 1;
    }


        printf("%d\n", billete100);
        printf("%d\n", billete50);
        printf("%d\n", billete20);
        printf("%d\n", billete10);
        printf("%d\n", billete5);
        printf("%d\n", billete1);

    return 0;
}
