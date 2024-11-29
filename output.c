#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **paths;
    int *path_size;
    int num_citezens_atended;
    int capacity;
} Global;

void global_initializer(Global *global, int initial_capacity) {
    global ->num_citezens_atended = 0;
    global ->capacity = initial_capacity;
    global ->paths = (int **)malloc(initial_capacity * sizeof(int *));
    global ->path_size = (int *)malloc(initial_capacity * sizeof(int));

}

//Adicionar caminhos ao global
void add_path(Global *global, int path[], int size){
    if(global ->num_citezens_atended >= global->capacity){
        global->capacity = global->capacity * 2;
        global->paths = (int **)realloc(global->paths, global->capacity * sizeof(int *));
        global->path_size = (int *)realloc(global->path_size, global->capacity * sizeof(int));
    }
    global->paths[global->num_citezens_atended] = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {                                                       //copia elementos do array caminho, que representa o trajeto de um cidadão, para o local correspondente no global, armazenando o caminho como parte dos resultados.
        global->paths[global->num_citezens_atended][i] = path[i];
    }
    global->path_size[global->num_citezens_atended] = size;
    global ->num_citezens_atended++;

}