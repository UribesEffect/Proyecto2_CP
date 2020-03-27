#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <omp.h>
#include <fstream>
#include <string>
using namespace std;

void MERGE(vector<long> &v, long ini, long fin, vector<long> &tmp){
    int mid = (fin + ini) / 2;
    int p1 = ini;
    int p2 = mid;
    int pt = ini;
    while(p1 < mid && p2 < fin){
      if(v[p1] < v[p2]){
            tmp[pt] = v[p1];
            pt++;
            p1++;
        }else{
            tmp[pt] = v[p2];
            pt++;
            p2++;
        }
    }

    while(p1 < mid){
        tmp[pt] = v[p1];
        pt++;
        p1++;
    }
    while(p2 < fin){
        tmp[pt] = v[p2];
        pt++;
        p2++;
    }
    for(int i = ini; i < fin; i++){
        v[i] = tmp[i];
    }
}

void BubbleSort(vector<long> &vec, long ini, long fin){
    for(long i = ini; i < fin; i++){
        for(long j = ini; j < fin-1; j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

void Helper_mergesort(vector<long> &v, long ini, long fin, vector<long> &tmp) {
  long test = fin - ini;
  if (test > 100) {
    long mid = (fin + ini) / 2;
    #pragma omp task shared( v, tmp)
    {
      Helper_mergesort(v, ini, mid, tmp);
    }
    #pragma omp task shared( v, tmp)
    {
      Helper_mergesort(v, mid, fin, tmp);
    }
    #pragma omp taskwait
    {
      MERGE(v, ini, fin, tmp);
    }
  }else{
    BubbleSort(v, ini, fin);
  }
}
void MERGESORT(vector<long> &v, long ini, long fin, vector<long> &tmp){
    #pragma omp parallel
    {
      #pragma omp single
      {
        Helper_mergesort(v, 0, v.size(), tmp);
      }
    }
}

void Display_vector(vector<long> v){
    printf("[ \n");
    for(long i = 0; i < long(v.size()); i++){
        printf("%ld ",v[i] );
    }
    printf(" ]\n");
}

vector<long> leer_vector(){
  string linea;
  vector<long> auxiliar;
  ifstream archivo("vector.dat");
  if(archivo.is_open()){
      while(getline(archivo, linea)){
              string palabra;
              for(long i = 0; i < long(linea.length()); i++){
                  if(linea[i] == ' ' || i == linea.length()){
                      long num = stol(palabra.c_str());
                      auxiliar.push_back(num);
                      palabra = "";
                  }
                  else{
                      palabra += linea[i];
                  }
              }
      }
      archivo.close();
  }else{
    cout << "No abre el vector.dat " << endl;
  }
  return auxiliar;
}

bool Verificador(vector<long> &v){
    for(long i = 0; i < long(v.size()) - 1; i++){
        if(v[i] > v[i + 1]){
            return false;
        }
    }
    return true;
}


////////////////////////////////////////////////////////////////////////////////

int main(){

    vector<long> v = leer_vector();

    printf("Tamaño del vector: %ld\n \n", v.size());

    vector<long> temporal(v.size(), 0);



    double t_start;
    double t_stop;
    if(v.size() <= 100){
        printf("Ordenando Vector por BubbleSort (size < 101)\n");
        BubbleSort(v, 0, v.size());
        temporal = v;
    }
    else{
      printf("Ordenando vector por MergeSort (size > 100)\n \n");
        t_start = omp_get_wtime();
        MERGESORT(v, 0, v.size(), temporal);
        t_stop = omp_get_wtime();
    }


    if(Verificador(temporal) == 1){
      printf("Vector ordenado y verificado\n \n");
    }
    else{
      printf("El vector fue  verificado y no esta ordenado\n \n");
    }
    double t_total = t_stop-t_start;
    printf("Tiempo Parallelo: %.8f\n \n",t_total);

    return 0;
}
