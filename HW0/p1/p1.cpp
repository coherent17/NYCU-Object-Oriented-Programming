#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

typedef struct _point{
    int x; 
    int y;
}point;

typedef struct _partial_image{
    point p;
    int joint[4];         //leftJoint, topJoint, rightJoint, downJoint
    char *character;     //image
} partial_image;

void parser(char *filename, int *partial_image_size, int *partial_image_count){
    FILE *input = fopen(filename, "r");
    fscanf(input, "%d", &(*partial_image_size));
    fgetc(input);

    //calculate how many partial image first:
    char buffer[BUFFER_SIZE];
    while(fscanf(input, "%[^\n]", buffer) != EOF){
        fgetc(input);
        (*partial_image_count)++;
    }
    fclose(input);

    //store the partial image
    partial_image *ret = (partial_image *)malloc(sizeof(partial_image) * (*partial_image_count));
    input = fopen(filename, "r");
    fscanf(input, "%d", &(*partial_image_size));
    fgetc(input);

    for(int i = 0; i < (*partial_image_count); i++){
        int leftJoint, topJoint, rightJoint, downJoint;
        fscanf(input, "%d %d %d %d %s", &leftJoint, &topJoint, &rightJoint, &downJoint, buffer);
        
        partial_image temp;
        temp.p
    }

}

int main(int argc, char *argv[]){
    int partial_image_size = 0;
    int partial_image_count = 0;
    parser(argv[1], &partial_image_size, &partial_image_count);
    printf("%d %d\n", partial_image_size, partial_image_count);
    return 0;
}