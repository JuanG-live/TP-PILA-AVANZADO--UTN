#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void actividad1();
void actividad2();
void actividad3();
void actividad4();
void actividad5();
void actividad6();
void actividad7();
void actividad8();
void actividad9();
void actividad10();
void actividad11();
void actividad12();


int main()
{
    actividad1();
    actividad2();
    actividad3();
    actividad4();
    actividad5();
    actividad6();
    actividad7();
    actividad8();
    actividad9();
    actividad10();
    actividad11();
    actividad12();
}
//1. sumar los elementos de una pila (usar variables)
void actividad1 ()
{
    printf("----EJERCICIO 1 DE PILA AVANZADO----\n");

    Pila pilaUno;
    Pila pilaDos;

    inicpila(&pilaUno);
    inicpila(&pilaDos);

    apilar(&pilaUno, 14);
    apilar(&pilaUno, 23);
    apilar(&pilaUno, 50);
    apilar(&pilaUno, 47);
    apilar(&pilaUno, 59);

    printf("\n\n----PILA UNO----");
    mostrar(&pilaUno);

    printf("\n\n----PILA DOS----");
    mostrar(&pilaDos);

    int suma = 0;
    while(!pilavacia(&pilaUno))
    {
        suma += tope(&pilaUno);
        apilar((&pilaDos), desapilar(&pilaUno));
    }

    printf("\n\nLa suma de los elementos es igual a: %i\n", suma);
    mostrar(&pilaDos);

    printf("----FIN DEL EJERCICIO----");
}
// 2.Contar los elementos de una pila (usar variables)
void actividad2()
{
    printf("----EJERCICIO 2 DE PILA AVANZADO----");

    Pila pilaUno;
    Pila pilaDos;

    inicpila(&pilaUno);
    inicpila(&pilaDos);

    apilar(&pilaUno, 10);
    apilar(&pilaUno, 20);
    apilar(&pilaUno, 30);
    apilar(&pilaUno, 40);

    int cn = 0;

    while (!pilavacia(&pilaUno))
    {
        cn++;
        apilar(&pilaDos, desapilar(&pilaUno));
    }


    printf("\n----PILA UNO----");
    mostrar(&pilaUno);
    printf("\n\nLa cantidad de elementos es: %i\n\n", cn);
    printf("\n----PILA DOS----");
    mostrar(&pilaDos);
}
// 3. Calcular el promedio de los valores de una pila (usar variables
void actividad3 ()
{
    printf("----EJERCICIO 3 DE PILA AVANZADO----");

    Pila pilaUno, pilaDos;

    inicpila(&pilaUno);
    inicpila(&pilaDos);

    apilar(&pilaUno, 10);
    apilar(&pilaUno, 20);
    apilar(&pilaUno, 30);


    int suma = 0;
    while(!pilavacia(&pilaUno))
    {
        suma += tope(&pilaUno);
        apilar((&pilaDos), desapilar(&pilaUno));
    }

    printf("\n\nLa suma de los elementos es igual a: %i \n\n", suma);
    mostrar(&pilaDos);

    int cn = 0;

    while (!pilavacia(&pilaDos))
    {
        cn++;
        apilar(&pilaUno, desapilar(&pilaDos));
    }

    float promedio = (float) suma / cn;

    printf("El promedio de los elementos de la pila es: %.2f \n", promedio);

    printf("\n----PILA UNO----");
    mostrar(&pilaUno);
    printf("\n----PILA DOS----");
    mostrar(&pilaDos);
}
// 4. Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)
void actividad4()
{
    printf("----EJERCICIO 4 DE PILA AVANZADO----");

    Pila pilaUno, pilaAux, pilaTres;

    inicpila(&pilaUno);
    inicpila(&pilaAux);
    inicpila(&pilaTres);

    apilar(&pilaUno, 3);
    apilar(&pilaUno, 20);
    apilar(&pilaUno, 30);
    apilar(&pilaUno, 40);
    apilar(&pilaUno, 50);


    printf("\n----PILA UNO----\n");
    mostrar(&pilaUno);

    apilar(&pilaAux, desapilar(&pilaUno));

    while(!pilavacia(&pilaUno))
    {
        if (tope(&pilaUno)<tope(&pilaAux))
        {
            apilar(&pilaTres, desapilar(&pilaAux));
            apilar(&pilaAux, desapilar(&pilaUno));
        }
        else
        {
            apilar(&pilaTres, desapilar(&pilaUno));
        }
    }
    printf("\n---PILA UNO----");
    mostrar(&pilaUno);

    printf("\nEl menor elemento es el: %i\n", tope(&pilaAux));
    mostrar(&pilaAux);

    printf("\n----PILA TRES----");
    mostrar(&pilaTres);

}
// 5. Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal
// que se conserve el orden. (sin variables, solo pilas)
void actividad5 ()
{
    printf("----EJERCICIO 5----");

    Pila pilaOriginal;
    Pila pilaAux;
    Pila pilaTres;

    inicpila(&pilaOriginal);
    inicpila(&pilaAux);
    inicpila(&pilaTres);

    apilar(&pilaOriginal, 10);
    apilar(&pilaOriginal, 20);
    apilar(&pilaOriginal, 30);
    apilar(&pilaOriginal, 40);
    apilar(&pilaOriginal, 50);

    printf("\n\n----PILA ORIGINAL----");
    mostrar(&pilaOriginal);

    printf("\n\n----PILA AUXILIAR");
    apilar(&pilaAux, 35);

    while (!pilavacia(&pilaOriginal)&&(!pilavacia(&pilaAux)))
    {
        while(tope(&pilaOriginal)>(tope(&pilaAux)))
        {
            apilar(&pilaTres, desapilar(&pilaOriginal));
        }

        {
            apilar(&pilaOriginal, desapilar(&pilaAux));
        }
        while (!pilavacia(&pilaTres))
        {
            apilar(&pilaOriginal, desapilar(&pilaTres));
        }
    }
    printf("\n\n----PILA ORIGINAL----\n");
    mostrar(&pilaOriginal);
}
// 6. Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que
// la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de
// ordenación por selección.
void actividad6()
{
    printf("\n\n----EJERCICIO 6----\n");

    Pila pilaUno, pilaAux, pilaTres;

    inicpila(&pilaUno);
    inicpila(&pilaAux);
    inicpila(&pilaTres);

    apilar(&pilaUno, 3);
    apilar(&pilaUno, 20);
    apilar(&pilaUno, 30);
    apilar(&pilaUno, 40);
    apilar(&pilaUno, 50);


    printf("\n----PILA UNO----\n");
    mostrar(&pilaUno);

    apilar(&pilaAux, desapilar(&pilaUno));

    while(!pilavacia(&pilaUno))
    {
        if (tope(&pilaUno)<tope(&pilaAux))
        {
            apilar(&pilaTres, desapilar(&pilaAux));
            apilar(&pilaAux, desapilar(&pilaUno));
        }
        else
        {
            apilar(&pilaTres, desapilar(&pilaUno));
        }
    }
    printf("\nEl menor elemento es el: %i\n");
    mostrar(&pilaAux);



    while(!pilavacia(&pilaTres))
    {
        apilar(&pilaAux, desapilar(&pilaTres));
    }
    printf("\n----PILA AUX----");
    mostrar(&pilaAux);
}
// 7. Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la
// búsqueda
void actividad7 ()
{
    printf("----EJERCICIO 7----\n\n");

    Pila pilaOriginal;
    Pila pilaAux;

    inicpila (&pilaOriginal);
    inicpila (&pilaAux);

    apilar(&pilaOriginal, 40);
    apilar(&pilaOriginal, 30);
    apilar(&pilaOriginal, 20);
    apilar(&pilaOriginal, 10);

    int numeroBuscado = 0;
    printf("ingrese el valor que desea buscar:");
    scanf("%i", &numeroBuscado);


    printf("\n\nPILA ORIGINAL:");
    mostrar(&pilaOriginal);


    int flag = 0;
    while(!pilavacia(&pilaOriginal)&&flag==0)
    {
        if(tope(&pilaOriginal)==numeroBuscado)
        {
            flag=1;
        }
        else
        {
            apilar(&pilaAux, desapilar(&pilaOriginal));
        }
    }
    if(flag==1)
    {
        printf("el numero buscado esta en la pila\n\n");
    }
    else
    {
        printf("el numero buscado no esta en la pila\n\n");
    }
}
// 8. Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.
void actividad8 ()
{
    printf("----EJERCICIO 8----\n\n");
    Pila pilaOriginal;
    Pila pilaAux;

    inicpila (&pilaOriginal);
    inicpila (&pilaAux);

    apilar(&pilaOriginal, 40);
    apilar(&pilaOriginal, 30);
    apilar(&pilaOriginal, 20);
    apilar(&pilaOriginal, 10);

    printf("PILA ORIGINAL:");
    mostrar(&pilaOriginal);

    int numeroBuscado = 0;
    printf("ingrese el valor que desea eliminar: ");
    scanf("%i", &numeroBuscado);

    int flag = 0;
    while(!pilavacia(&pilaOriginal)&&flag==0)
    {
        if(tope(&pilaOriginal)==numeroBuscado)
        {
            flag=1;
            desapilar(&pilaOriginal);
        }
        else
        {
            apilar(&pilaAux, desapilar(&pilaOriginal));
        }
    }
    while(!pilavacia(&pilaAux))
    {
        apilar(&pilaOriginal, desapilar(&pilaAux));
    }
    if(flag==1)
    {
        printf("pila original sin el numero eliminado:\n");
        mostrar(&pilaOriginal);
    }
    else
    {
        printf("ERROR408: EL NUMERO INGRESADO NO ESTA EN LA PILA");
    }
}
// 9. Verificar si una pila DADA es capicúa.
void actividad9 ()
{
    printf("----EJERCICIO 9----");


    Pila dada,copia,aux2;
    inicpila(&dada);
    inicpila(&copia);
    inicpila(&aux2);

    apilar(&dada,1);
    apilar(&dada,2);
    apilar(&dada,3);
    apilar(&dada,2);
    apilar(&dada,2);

    while (!pilavacia(&dada))
    {
        apilar(&copia,tope(&dada));
        apilar(&aux2,desapilar(&dada));
    }
    while (!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }
    puts("\n\n---PILA DADA---\n");
    mostrar(&dada);
    puts("\n\n----PILA COPIA----");
    mostrar(&copia);

    int flag = 0;
    while (!pilavacia(&dada)&&flag==0)
    {
        if(tope(&dada)==tope(&aux2))
        {
            apilar(&aux2, desapilar(&dada));
            desapilar(&copia);
        }
        else
        {
            flag = 1;
        }
    }

    if (flag==0)
    {
        printf("\n\n----LA PILA ES CAPICUA----\n");
    }
    else
    {
        printf("\n\n----LA PILA NO ES CAPICUA----\n");
    }
}
// 10. Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos
// sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión
// A: 1 2 3 tope
// AuB 3 2 1 7 5
void actividad10 ()
{
    printf("----EJERCICIO 10----\n");

    Pila A;
    Pila B;
    Pila AUB;
    Pila auxA;
    Pila auxB;
    Pila auxAUB;

    inicpila(&A);
    inicpila(&B);
    inicpila(&AUB);
    inicpila(&auxB);
    inicpila(&auxA);
    inicpila(&auxAUB);

    apilar(&A, 1);
    apilar(&A, 2);
    apilar(&A, 3);

    apilar(&B, 2);
    apilar(&B, 3);
    apilar(&B, 5);
    apilar(&B, 7);

    printf("PILA A");
    mostrar(&A);

    printf("PILA B");
    mostrar(&B);

    /// Paso la pila A a Union
    while(!pilavacia(&A))
    {
        apilar(&auxA, tope(&A));
        apilar(&AUB, desapilar(&A));
    }

    /// rearmo pila A
    while(!pilavacia(&auxA))
    {
        apilar(&A, desapilar(&auxA));
    }

    /// Recorrer pila B y comparar si esta en Pila A

    while(!pilavacia(&B))
    {
        int flag = 0; /// flag = 1 significa que ya se encuentra en union
        /// Recorer pila union para ver si estan repetido con b
        while(!pilavacia(&A)  && flag == 0)
        {
            if(tope(&B) == tope(&A))
            {
                apilar(&auxB, desapilar(&B));
                flag = 1 ;
            }
            else
            {
                apilar(&auxA, desapilar(&A));
            }
        } /// termine de comparar ultimo de b con todos de union
        if(flag == 0)
        {
            apilar(&auxB, tope(&B));
            apilar(&AUB, desapilar(&B));
        }

        /// rearmar union
        while(!pilavacia(&auxA))
        {
            apilar(&A, desapilar(&auxA));
        }
    }

    /// Rearmar Pila B
    while(!pilavacia(&auxB))
    {
        apilar(&B, desapilar(&auxB));
    }

    printf("\n\n >> La pila original A es:\n");
    mostrar(&A);
    printf("\n\n >> La pila original B es:\n");
    mostrar(&B);
    printf("\n\n >> La union de las pilas ingresadas es:\n");
    mostrar(&AUB);
}
// 11. Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando
// el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).
void actividad11 ()
{
    printf("----EJERCICIO 11-----\n\n");


    Pila ordenada1, aux1, ordenada2, aux2, ordenadaFinal;

    inicpila(&ordenada1);
    inicpila(&ordenada2);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&ordenadaFinal);

    apilar(&ordenada1, 2);
    apilar(&ordenada1, 5);
    apilar(&ordenada1, 6);
    apilar(&ordenada1, 7);
    apilar(&ordenada1, 11);

    apilar(&ordenada2, 1);
    apilar(&ordenada2, 3);
    apilar(&ordenada2, 4);
    apilar(&ordenada2, 9);
    apilar(&ordenada2, 10);

    printf("----PILA ORDENADA 1----");
    mostrar(&ordenada1);
    printf("----PILA ORDENADA 2----");
    mostrar(&ordenada2);

    while(!pilavacia(&ordenada1))
    {
        apilar(&aux1, desapilar(&ordenada1));
    }
    while(!pilavacia(&ordenada2))
    {
        apilar(&aux2, desapilar(&ordenada2));
    }

    while(!pilavacia(&aux1))
    {
        if(tope(&aux1)<tope(&aux2))
        {
            apilar(&ordenadaFinal, desapilar(&aux1));
        }
        else
        {
            apilar(&ordenadaFinal, desapilar(&aux2));
        }

    }
    while(!pilavacia(&aux2))
    {
        apilar(&ordenadaFinal, desapilar(&aux2));
    }

    printf("\n----PILA ORDENADA----");
    mostrar(&ordenadaFinal);
}
// 12. Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el
//resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.
void actividad12()
{
    printf("----EJERCICIO 12-----\n\n");

    Pila origen, destino, auxiliar;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&auxiliar);

    apilar(&origen, 2);
    apilar(&origen, 21);
    apilar(&origen, 34);
    apilar(&origen, 8);
    apilar(&origen, 7);

    if(!pilavacia(&origen))
    {
        /// Si la pila origen no esta vacia, le paso el primer elemento...
        apilar(&destino, desapilar(&origen));

        printf("pila origen");
        mostrar(&origen);
        printf("pila Destino");
        mostrar(&destino);
        printf("pila Auxiliar");
        mostrar(&auxiliar);

        while(!pilavacia(&origen))
        {
            /// Recorro la pila origen y voy poniendo en el orden que va
            while(!pilavacia(&origen))
            {
                if(tope(&origen) > tope(&destino))
                {
                    apilar(&auxiliar, desapilar(&destino));
                    apilar(&destino, desapilar(&origen));
                    printf("pila origen");
                    mostrar(&origen);
                    printf("pila Destino");
                    mostrar(&destino);
                    printf("pila Auxiliar");
                    mostrar(&auxiliar);

                }
                else
                {
                    apilar(&auxiliar, desapilar(&origen));
                    printf("pila origen");
                    mostrar(&origen);
                    printf("pila Destino");
                    mostrar(&destino);
                    printf("pila Auxiliar");
                    mostrar(&auxiliar);
                }
            }

            /// rearmo origen
            while(!pilavacia(&auxiliar))
            {
                apilar (&origen, desapilar(&auxiliar));
                printf("pila origen");
                mostrar(&origen);
                printf("pila Destino");
                mostrar(&destino);
                printf("pila Auxiliar");
                mostrar(&auxiliar);
            }
            ///Paso el tope para comparar si es el "nuevo menor"
            if(!pilavacia(&origen))
            {
                apilar(&destino, desapilar(&origen));
                printf("pila origen");
                mostrar(&origen);
                printf("pila Destino");
                mostrar(&destino);
                printf("pila Auxiliar");
                mostrar(&auxiliar);
            }
        }
    }
    else
    {
        printf("\nLa pila se encuentra vacia.\n");
    }
    while(!pilavacia(&destino))
    {
        apilar(&origen,desapilar(&destino));
    }
    mostrar(&origen);
}


