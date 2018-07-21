#include <stdio.h>
#include "gnim.h"
#define true 1
#define false 0

int main(){
    int arr[3];
    printf("Please enter 3 numbers: ");
    
    scanf("%i",&arr[0]);
    scanf("%i",&arr[1]);
    scanf("%i",&arr[2]);

    playGame(arr);
}

void playGame(int arr[]){
    
    int CompTurn = 1;
    int gameOver = false;
    int packet = 0;
    int newPacket = 0;
    
        if(arr[0]==arr[1]+arr[2] || (arr[0]==1 && arr[1]==1 && arr[2]==1))
            CompTurn=0;
        
    while(gameOver==0){
        
    sort(arr);

        if(CompTurn==1){
        printf("Packet sizes are: %i, %i, %i\n",arr[0],arr[1],arr[2]);
        printf("computer turn!\n");
        
        if(arr[0]>1 && arr[1]==0 && arr[2]==0){
            printf("I turned: %i to:%i\n",arr[0],1);
            arr[0] = 1;
            printf("Game Over - You Lost !!");
            gameOver=true;
        }
        else if(arr[0]>1 && arr[1]==1 && arr[2]==0){
            printf("I turned: %i to:%i\n",arr[0],0);
            arr[0] = 0;
            printf("Game Over - You Lost !!\n");
            gameOver=true;
        }
        else if(arr[0]>1 && arr[1]==1 && arr[2]==1){
            printf("I turned: %i to:%i\n",arr[0],1);
            arr[0] = 1;
            CompTurn=0;
        }
        else if(arr[0]==1 && arr[1]==1 && arr[2]==0){
            printf("I turned: %i to:%i\n",arr[0],0);
            arr[0] = 0;
            printf("Game Over - You Lost !!\n");
            gameOver=true;
            return;
        }
        else{
        int a = arr[0];
        printf("I turned: %i to:%i\n",arr[0],arr[1]-arr[2]);
        arr[0] = arr[1]-arr[2];
        CompTurn=0;
        }
        
        }
        
        sort(arr);
        
        if(CompTurn==0){
        printf("Packet sizes are: %i, %i, %i\n",arr[0],arr[1],arr[2]);
        printf("Player turn!\n");
        printf("Choose packet:");
        scanf("%i",&packet);
        while(packet!=arr[0] && packet!=arr[1] && packet!=arr[2]){
            printf("Error! choose real packet: ");
            scanf("%i",&packet);
        }
        printf("Change to:");
        scanf("%i",&newPacket);
        while(newPacket>=packet || newPacket<0){
            printf("Error! please choose another number(0-%i):\n",packet-1);
            scanf("%i",&newPacket);
        }

        for(int i=0; i<3;i++){
            if(arr[i]==packet){
                arr[i] = newPacket;
                i=3;
            }
        }
        sort(arr);
        if(arr[0]==1 && arr[1]==0 && arr[2]==0){
            printf("Game Over - You Won !!\n");
            gameOver=true;
            return;
            
        }
        
        CompTurn=1;
        }
    }
    
    
}

void sort(int arr[]){
    for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
            if(arr[i]<arr[j]){
                int tepm = arr[j];
                arr[j] = arr[i];
                arr[i] = tepm;
            }
            }
        }
}