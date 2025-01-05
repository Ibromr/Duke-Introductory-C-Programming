#include <stdlib.h>
#include <stdio.h>

typedef struct _retire_info { 
    int months;
    double contribution;
    double rate_of_return;
} retire_info;

void retirement(int startAge,       // in months
                double initial,      // initial savings in dollars
                retire_info working, // info about working
                retire_info retired)  // info about being retired
                                    {
     double balance = initial;
    
    // Total number of months to run the loop (working + retired)
    int totalMonths = working.months + retired.months;

    // Loop over all months (working + retired)
    for (int i = 0; i < totalMonths; i++){
        // Printing balance for the current month
        printf("Age %3d month %2d you have $%.2lf\n", startAge / 12, startAge % 12,
                                               balance);
        
        if ( i < working.months){
            // Working period: calculate for each month
            balance = balance + (balance * working.rate_of_return) 
                           + working.contribution;
        } else {
            // Retired period for each month
            balance = balance + (balance * retired.rate_of_return) 
                           + retired.contribution;
        }
        startAge++;
    }
}

int main(void){

    retire_info working = {489, 1000, 0.045 / 12};   // 489 months, $1000/month, 4.5% annual return
    retire_info retired = {384, -4000, 0.01 / 12};  // 384 months, -$4000/month, 1% annual return
  
    // _retire_info working;
    // working.months = 489;
    //working.contribution = 1000;
    //working.rate_of_return = 0.045/12;

    //_retire_info retired;
    //retired.months = 384;
    //retired.contribution = -4000;
    //retired.rate_of_return = 0.01/12;

    // Starting conditions
    int Age = 327;  // 27 years, 3 months
    double Savings = 21345;

    retirement(Age, Savings, working, retired);
    return EXIT_SUCCESS;
}
