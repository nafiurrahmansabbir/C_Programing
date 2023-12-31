#include<stdio.h>
void marge(int a[],int lb,int mid,int ub){
    int new_a[ub+1];
    // printf("%d \n",ub);
    int i=lb;
    int j=mid+1;
    int k=lb;
    
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            new_a[k]=a[i];
            i++;
        }else{
            new_a[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            new_a[k]=a[j];
            j++;
            k++;
        }
    }else{
        while(i<=mid){
            new_a[k]=a[i];
            i++;
            k++;
        }
    }

    //array ec=xchang:
    int x;
    for(x=lb;x<=ub;x++){
        a[x]=new_a[x]; 
    }
}
void marge_sort(int a[],int lb,int ub){
    int mid;
    if(lb<ub){
        mid=(lb+ub)/2;
        marge_sort(a,lb,mid);
        marge_sort(a,mid+1,ub);
        marge(a,lb,mid,ub);
    }
}

void print(int a[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int array[]={76,34,6,54,2,54,1,58,62};
    int size=sizeof(array)/sizeof(array[0]);
    printf("Print before sorted: ");
    print(array,size);
    marge_sort(array,0,size-1);
    printf("Print after  sorted: ");
    print(array,size);
}