#include<stdio.h>

int main(){
    int pages[50],frames[10];
    int n,f,i,j,fr = 0;
    int fo,pH = 0,pF = 0;

    printf("Enter no. of pages & frames (p f): ");
    scanf("%d %d",&n,&f);
    printf("Enter Page string : \n");
    for(i = 0;i < n;i++)  scanf("%d",&pages[i]);

    for(i = 0;i < f;i++) frames[i] = -1;
    printf("\nPage\tFrames\t\tStatus\n");
    for(i=0;i<n;i++){
        fo = 0;
        for (j = 0; j < f; j++){
            if(frames[j] == pages[i]){
                fo = 1;
                break;
            }
        }
        if(fo){
            pH++;
        }else{
            pF++;
            frames[fr] = pages[i];
            fr = (fr+1) % f;
        }
        printf("%d\t",pages[i]);
        for (j = 0; j < f; j++){
            if (frames[j] == -1)    printf("-");
            else    printf("%d", frames[j]);
        }
        if (fo) printf("\tHit");
        else
        printf("\tPage Fault");
        printf("\n");
    }

    printf("Total Page Hit : %d\n",pH);
    printf("Total Page Fault : %d\n",pF);
    return 0;
}