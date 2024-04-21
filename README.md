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
#### Ejemplo:

1. **Determina el número promedio de nodos por nivel**: Esto se hace basado en la probabilidad de promoción. Por ejemplo, si empezamos con 100 nodos y cada nodo tiene una probabilidad del 50% de ser promovido al siguiente nivel, el número de nodos por nivel sería aproximadamente:
   - Nivel 0: 100 nodos
   - Nivel 1: 50 nodos
   - Nivel 2: 25 nodos
   - Continúa hasta que el número sea menor que 1.

2. **Suma la memoria usada por todos los nodos en todos los niveles**: Calculando con cada nodo ocupando 10 unidades de memoria:
   - Memoria en Nivel 0: 1000 unidades de memoria (100 nodos × 10 unidades/nodo)
   - Memoria en Nivel 1: 500 unidades de memoria (50 nodos × 10 unidades/nodo)
   - Memoria en Nivel 2: 250 unidades de memoria (25 nodos × 10 unidades/nodo)
   - Y así sucesivamente...

   Sumando todas estas cantidades obtenemos la memoria total utilizada por la skiplist.

3. **Compara esta suma con la memoria que usaría una lista simple para determinar la eficiencia**: Si una lista simple de 100 nodos utiliza 1000 unidades de memoria, la skiplist en este ejemplo utiliza 1970 unidades de memoria, indicando un uso más alto pero proporcionando beneficios en velocidad de operaciones de búsqueda, inserción y eliminación.


## Comparaciones con otras estructuras de datos

### Comparación con Treaps, Árboles Rojo y Negro, y Tablas Hash

| Estructura        | Eficiencia | Uso de Memoria | Casos de Uso Típicos              |
|-------------------|------------|----------------|-----------------------------------|
| **Skiplists**     | Alta       | Moderada       | Búsquedas, inserciones y eliminaciones eficientes |
| **Treaps**        | Moderada   | Alta           | Optimización de rendimiento en operaciones mixtas |
| **Árboles Rojo y Negro** | Alta   | Alta           | Mantenimiento de balance en inserciones y eliminaciones |
| **Tablas Hash**   | Muy alta   | Variable       | Búsqueda rápida, inserción y eliminación con buen hash |

Como se puede ver, las skiplists son particularmente útiles cuando se necesitan inserciones y eliminaciones eficientes junto con búsquedas rápidas y eficaces, siendo una alternativa menos compleja en términos de implementación comparada con estructuras más rígidas como los árboles rojo y negro.
#### Definición de Eficiencia

La eficiencia en estructuras de datos se puede calcular en términos de:
- **Complejidad de Tiempo**: Tiempo que tarda realizar operaciones clave como búsqueda, inserción y eliminación.
- **Uso de Memoria**: Cantidad de memoria requerida para almacenar los datos.

#### Comparación de Eficiencia

##### 1. **Skiplists**
   - **Búsqueda, Inserción, Eliminación**: O(log n) en promedio.
   - **Memoria**: Memoria adicional requerida debido a múltiples niveles de punteros.

##### 2. **Treaps**
   - **Búsqueda, Inserción, Eliminación**: O(log n) en promedio, pero puede degradarse a O(n) en el peor caso.
   - **Memoria**: Alta debido a almacenamiento de prioridades aleatorias junto con las claves.

##### 3. **Árboles Rojo y Negro**
   - **Búsqueda, Inserción, Eliminación**: O(log n), muy consistente debido al estricto balanceo.
   - **Memoria**: Alta, cada nodo requiere almacenar información adicional para el balanceo de color.

##### 4. **Tablas Hash**
   - **Búsqueda, Inserción, Eliminación**: O(1) en promedio, sujeto a una buena función de hash y manejo de colisiones.
   - **Memoria**: Variable, depende de la carga y el método de manejo de colisiones (como encadenamiento o direccionamiento abierto).

#### Evaluación Práctica

Para calcular la eficiencia, consideramos un caso de uso típico en que se realizan múltiples operaciones de búsqueda, inserción y eliminación. Supongamos que realizamos 1 millón de operaciones en una estructura con 10,000 elementos.

- **Skiplists**: La complejidad promedio de O(log n) significa que cada operación toma aproximadamente 13.3 pasos (log2(10,000)).
- **Treaps, Árboles Rojo y Negro**: Similar a skiplists en tiempo, pero los árboles rojo y negro ofrecen mejor peor caso.
- **Tablas Hash**: Idealmente O(1) por operación, pero depende de factores de carga y colisión.

Para evaluar memoria, simplemente se multiplica el número total de elementos por el uso de memoria por elemento, considerando cualquier estructura adicional necesaria como se hizo en el ejemplo anteriormente mostrado.
### Cálculo Paso a Paso de la Eficiencia de las Skiplists

#### Entendiendo el Logaritmo

La eficiencia de búsqueda en una skiplist se calcula generalmente en términos de O(log n), donde "n" es el número de elementos en la skiplist. El logaritmo, denotado como log, es una función matemática que determina cuántas veces un número (la base) debe ser multiplicado por sí mismo para obtener otro número. En el contexto de las skiplists, generalmente se usa el logaritmo base 2, porque cada "salto" en la estructura potencialmente reduce a la mitad el número de elementos a considerar.

#### Proceso de Cálculo de la Eficiencia

1. **Estructura de Niveles**: La skiplist se construye con múltiples niveles, donde cada nivel es una versión más "adelgazada" del nivel inferior. La probabilidad de que un nodo sea incluido en el siguiente nivel superior es generalmente del 50% $(p = 0.5)$.

2. **Número de Niveles**: La cantidad de niveles en una skiplist es típicamente proporcional a log₂(n), donde n es el número total de nodos. Esto significa que el número de niveles aumenta logarítmicamente con el número de elementos.

   $$\text{Número de niveles} = \lceil \log_2 n \rceil$$

3. **Búsqueda de un Elemento**: Para buscar un elemento, comienzas en el nivel más alto y avanzas horizontalmente hasta que encuentras un valor mayor al que buscas o hasta el final del nivel. Luego, bajas un nivel y continuas. Este proceso se repite hasta llegar al nivel más bajo.

   $$\text{Pasos promedio} = O(\log n)$$

4. **Inserción y Eliminación**: Estas operaciones siguen un proceso similar al de búsqueda para localizar la posición donde se insertará o eliminará un nodo. Después de localizar la posición, la inserción o eliminación puede requerir actualización de enlaces en múltiples niveles, lo que también incurre en un costo logarítmico.



