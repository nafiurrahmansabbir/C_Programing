#include<stdio.h>

void display(float a[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%.2f   ",a[i]);
    }
    printf("\n");
}
int  main(){
    // int weight[]={5,5,3,2};
    // int profit[]={3,4,5,6};
    float weight[]={2,3,5,7,1,4,1};
    float profit[]={10,5,15,7,6,8,3};
    int size=sizeof(weight)/sizeof(weight[0]);
    float pw[size];
    int i;
    for(i=0;i<size;i++){
        pw[i]=profit[i]/weight[i];
    }
    printf("------Given the data------\n\n");
    printf("Print weight : ");
    display(weight,size);
    printf("Print profit : ");
    display(profit,size);
    printf("Print P/W    : ");
    display(pw,size);


    //sorting
    // int size=sizeof(pw)/sizeof(pw[0]);
    int max_index,j;
    for(i=0;i<size;i++){
        max_index=i;
        for(j=i+1;j<size;j++){
            if(pw[j]>pw[ max_index]){
                max_index=j;
            }
        }
        float temp=pw[i];
        pw[i]=pw[max_index];
        pw[max_index]=temp;
    //swap profit;
        int temp2;
        temp2=profit[i];
        profit[i]=profit[max_index];
        profit[max_index]=temp2;

        //swap weight
        temp2=weight[i];
        weight[i]=weight[max_index];
        weight[max_index]=temp2;
    }
    //swap complete
    printf("\nAfter sorted Decending order of p/w : \n\n");
    printf("Print weight : ");
    display(weight,size);
    printf("Print profit : ");
    display(profit,size);
    printf("Print P/W    : ");
    display(pw,size);
    printf("\n\n");

    //gready calculation part: 
    printf("--------Gready Part---------\n\n");
    float capacity=15;

  
    int top=0;
    float maxp=0,maxw=0;
    float reminder=0;
    // int br=0;
    while(capacity>maxw){
        printf("Take %d :\n",top+1);

        maxw=maxw+weight[top];
        maxp=maxp+profit[top];
        
        printf("taken weight : %.2f\n",weight[top]);
        printf("taken profit: %.2f\n",profit[top]);
        printf("Total profit %.2f and total weight %.2f \n",maxp,maxw);
        reminder=capacity-maxw;
        printf("Remaining capacity : %.2f \n",reminder);
        printf("\n");
        top++; 

        if(reminder<weight[top]){
            break;
        }       
    }

    if(reminder>0){
        float frac_profit;
        frac_profit=pw[top]*reminder;
        maxw=maxw+reminder;
        maxp=maxp+frac_profit;
        printf("Take %d :\n",top+1);

        printf("taken weight : %.2f\n",reminder);
        printf("taken profit: %.2f\n",frac_profit);
        printf("Total profit %.2f and total weight %.2f \n",maxp,maxw);
        reminder=capacity-maxw;
        printf("Remaining capacity : %.2f \n",reminder);
        printf("\n");
    }
    
}