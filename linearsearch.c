
#include <stdio.h>

float store[20];
void introduction(void) {
    printf("This program reads numbers from a file called input.dat, ");
    printf("sorts the numbers.");
};

void readInput(void) {
    FILE *fp = NULL;
    char filename[20];
    printf("Please input the filename: ");
    scanf("%s", filename);

    fp= fopen(filename, "r");
    for(int i = 0; i < 20; i++) {
        fscanf(fp, "%f", &store[i]);
    }

}

int min(int start) {
    int temp;
    temp = start;
    for (int i = start + 1; i < 20; i++){
        if (store[i] < store[temp]) {
            temp = i;
        }
    }
    return temp;
}

void swap(float *l, float *r) {
    float temp;
    temp = *l;
    *l = *r;
    *r = temp;
}

void sort(void) {
    for (int i = 0; i < 20; i++) {
        swap(&store[i], &store[min(i)]);
    }
}

void display(void) {
    for(int i = 0; i < 20; i++) {
        printf("%.2f\n", store[i]);
    }
}

int main(void) {
introduction();
readInput();
sort();
display();
}