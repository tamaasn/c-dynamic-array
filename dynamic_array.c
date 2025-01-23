#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *values;
    size_t count;
    size_t capacity;
}Numbers;

void add_item(Numbers *num, int item){
    if (num->count >= num->capacity){
        if (num->capacity == 0) num->capacity=1;
        num->capacity *= 2;
        num->values = realloc(num->values,num->capacity*sizeof(*num->values));
    }
    num->values[num->count++]=item;
}

void delete_item(Numbers *num, int item){
    for(int i=0;i<num->count;i++){
        if (num->values[i] == item){
            for(int j=i;j<num->count;j++){
                num->values[j]=num->values[j+1];
            }
            num->count--;
            num->capacity--;
            break;
        }
    }
    num->values = realloc(num->values,num->capacity*sizeof(*num->values));
}

int search_index(Numbers *num, int item){
    int result=-1;
    for(int i=0;i<num->count;i++){
        if (num->values[i] == item){
            result = i;
            break;
        }
    }
    return result;
}

int main(){
    Numbers num = {0};

    for(int i=0;i<10;i++){
        add_item(&num,i);
    }

    for(int i=0;i<num.count;i++){
        printf("%d\n",num.values[i]);
    }

    delete_item(&num, 7);
    delete_item(&num,9);
    printf("After delete : \n");

    for(int i=0;i<num.count;i++){
        printf("%d\n",num.values[i]);
    }

    printf("index from item 3 : %d\n",search_index(&num,3));
    free(num.values);
    return 0;
}

