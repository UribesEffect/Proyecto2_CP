27/03/20

Computacion Paralela, concurrente y distribuida.

Proyecto que ordena un vector de numeros aleatorios con un tamaño dado usando MergeSort.

Santiago Uribe Luna

Link del GitHub: https://github.com/UribesEffect/Proyecto2_CP

NOTA: lo suguiente comandos se deben compilar en el cluster.

$ make generate : El siguiente comando se utiliza para generar un vector.dat donde este 
tiene un vector con numeros aleatorios los cuales los coloca uno por uno.

$ make MergeSort_serial : compila el MergeSort de forma serial tomando los datos que 
generaste en el vector.dat .

$ make MergeSort_parallel : compila el MergeSort de forma paralela tomando los datos 
que generaste en el vector.dat .





$ sbatch GENERATE.sh generate argv1 : Manda a correr el programa en la cola de cluster, 
note que argv1 se refiere a la cantidad de numeros aleatoreos que vas a meter en el
vector.dat(porfavor usar argv1 = 100000000 '100Mill' ) .

$ sbatch SERIAL.sh MergeSort_serial : Compila el MergeSort de forma serial usando solamente 
1 nucleo y tomando como parametro vector.dat, mete la ejecucion a la cola del cluster .

$ sbatch PARALLEL_4.sh MergeSort_parallel : Compila el MergeSort de forma paralela usando
4 nucleos del cluster y tomando como parametro vector.dat, mete la ejecucion a la cola
del cluster.

$ sbatch PARALLEL_8.sh MergeSort_parallel : Compila el MergeSort de forma paralela usando
8 nucleos del cluster y	tomando	como parametro vector.dat, mete	la ejecucion a la cola  
del cluster.

$ sbatch PARALLEL_12.sh MergeSort_parallel : Compila el MergeSort de forma paralela usando
12 nucleos del cluster y tomando como parametro vector.dat, mete la ejecucion a la cola  
del cluster.

$ sbatch PARALLEL_16.sh MergeSort_parallel : Compila el MergeSort de forma paralela usando
16 nucleos del cluster y tomando como parametro vector.dat, mete la ejecucion a la cola  
del cluster.


NOTA: Los sbatch generan una salida la cual debe ser mostrada en la consola.


Existe un SpeedUP.txt el cual tiene los tiempos generados y su respectivo SpeedUP.
