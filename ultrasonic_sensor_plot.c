// Vasile-Daniel DAN
// 02 - May - 2024 
// Project 10: Ultrasonic Sensor Module
#include <stdio.h>

int main(){


    // ============ GNU PLOT ==================== // 

    FILE *gnuplotPipe = NULL; 
    gnuplotPipe = popen("gnuplot -persist", "w");

    if (gnuplotPipe == NULL){
        printf("Error opening the file.");
        return 1; 
    }

    fprintf(gnuplotPipe, "set terminal png\n");
    fprintf(gnuplotPipe, "set output 'ultrasonic_sensor_plot.png'\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "set title 'Ultrasonic Sensor Module'\n");
    fprintf(gnuplotPipe, "set xlabel 'number of data achisition '\n");
    fprintf(gnuplotPipe, "set ylabel 'distance [mm]' \n");


    fprintf(gnuplotPipe, "plot 'CoolTerm Capture (Untitled_0) 2024-05-02 12-12-37-964.txt' using 1 with lines linewidth 2 linecolor rgb 'red'\n");

    return 0; 
} 