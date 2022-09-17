#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned long long sec; 
    unsigned long long min;
    unsigned long long hr;
    int j; 
    int stopPoint=0, stopMin=0;
    printf("\nDigital Clock\n");
    
    printf("\nEnter Hour/Minute/Second:\n");    
    scanf("%llu%llu%llu", &hr, &min, &sec);
    if(hr == 0|| hr > 12 || min > 59 || sec > 59){
        printf("\nERROR !\n");
        exit(0);
    } else {
        do{
            printf("In how many minutes do you want it to stop running?\n");
            scanf("%i", &stopMin);

            if(stopMin > 0){
                stopPoint = stopMin * 60;
                for(j=0; j<=stopPoint; j++){
                    printf("Time: %02llu:%02llu:%02llu\n", hr, min, sec);
                    sleep(1);
                    if(sec == 59){
                        sec = 0;
                        if(min == 59){
                            min = 0;
                            if(hr==12){
                                hr=1;
                            } else {
                                hr++;
                            }
                        } else {
                            min++;
                        }
                    } else {
                        sec++;
                    }
                }
            } else {
                printf("\nThe stop time must be higher than 0.\n");
            }
            
        } while (stopMin==0);

        if(stopMin==1){
            printf("\nTime's up! %i minute has passed!", stopMin);
        } else {
            printf("\nTime's up! %i minutes have passed!", stopMin);
        }
    }
    
    return 0;
}