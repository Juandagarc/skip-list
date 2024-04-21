# Documento sobre Skiplists

## Introducción a las Skiplists

### ¿Qué son las Skiplists?

Las skiplists son una estructura de datos probabilística que permite realizar operaciones de inserción, eliminación y búsqueda de manera eficiente. Funcionan mediante niveles múltiples de enlaces que permiten saltar sobre partes de la lista, facilitando búsquedas rápidas similar a como funcionan los árboles balanceados.

### Funcionamiento y relación con la distribución binomial

El funcionamiento de las skiplists se basa en la decisión aleatoria de elevar nodos a niveles superiores, lo que se relaciona con la distribución binomial. Cada elemento tiene una probabilidad independiente de ser promovido al siguiente nivel, lo cual introduce aleatoriedad en la altura y estructura de la skiplist.

## Eficiencia en memoria de las Skiplists

### Cálculo de la eficiencia en memoria

Para calcular la eficiencia en memoria de las skiplists, consideramos la cantidad de nodos promovidos a cada nivel y la probabilidad de promoción. Generalmente, se asume que la memoria adicional requerida es proporcional al número de niveles y nodos en cada nivel.

#### Paso a paso del cálculo

1. Determina el número promedio de nodos por nivel: Esto se hace basado en la probabilidad de promoción.
2. Suma la memoria usada por todos los nodos en todos los niveles.
3. Compara esta suma con la memoria que usaría una lista simple para determinar la eficiencia.

## Comparaciones con otras estructuras de datos

### Comparación con Treaps, Árboles Rojo y Negro, y Tablas Hash

| Estructura        | Eficiencia | Uso de Memoria | Casos de Uso Típicos              |
|-------------------|------------|----------------|-----------------------------------|
| **Skiplists**     | Alta       | Moderada       | Búsquedas, inserciones y eliminaciones eficientes |
| **Treaps**        | Moderada   | Alta           | Optimización de rendimiento en operaciones mixtas |
| **Árboles Rojo y Negro** | Alta   | Alta           | Mantenimiento de balance en inserciones y eliminaciones |
| **Tablas Hash**   | Muy alta   | Variable       | Búsqueda rápida, inserción y eliminación con buen hash |

Como se puede ver, las skiplists son particularmente útiles cuando se necesitan inserciones y eliminaciones eficientes junto con búsquedas rápidas y eficaces, siendo una alternativa menos compleja en términos de implementación comparada con estructuras más rígidas como los árboles rojo y negro.


