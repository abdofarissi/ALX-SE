
#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI 3.14159265358979323846

// Number of samples to process
// In a real application, this would be the buffer size
#define N 16 

/**
 * dft_compute
 * * Performs the Discrete Fourier Transform (DFT) algorithm.
 * Formula: X[k] = sum(x[n] * e^(-i * 2 * pi * k * n / N))
 * * @param in  Array of complex numbers representing the input signal (time domain)
 * @param out Array of complex numbers to store the result (frequency domain)
 * @param n   The number of samples
 */
void dft_compute(double complex in[], double complex out[], int n) {
    for (int k = 0; k < n; k++) {
        double complex sum = 0.0 + 0.0 * I;
        
        for (int t = 0; t < n; t++) {
            // Calculate the angle theta = -2 * pi * k * t / N
            double theta = -2.0 * PI * k * t / n;
            
            // Euler's formula: e^(i*theta) = cos(theta) + i*sin(theta)
            // This represents the "testing frequency"
            double complex w = cos(theta) + I * sin(theta);
            
            // Multiply input sample by the testing frequency and accumulate
            sum += in[t] * w;
        }
        
        out[k] = sum;
    }
}

int main() {
    double complex time_domain[N];
    double complex freq_domain[N];

    printf("--- Input Signal (Time Domain) ---\n");
    printf("Sampling function: f(t) = 1.0*sin(t) + 0.5*sin(3t)\n\n");

    // 1. Generate a signal
    // We sample a function composed of two sine waves:
    // One at a base frequency (1x) and one at 3 times that frequency (3x)
    for (int t = 0; t < N; t++) {
        // Create a 'time' value mapped from 0 to 2*PI
        double time_val = (2.0 * PI * t) / N;
        
        // The function: sin(x) + 0.5*sin(3x)
        double signal_value = 1.0 * sin(time_val) + 0.5 * sin(3.0 * time_val);
        
        // Store as a complex number (imaginary part is 0 for real signals)
        time_domain[t] = signal_value + 0.0 * I;
        
        printf("Sample %2d: %+.4f\n", t, signal_value);
    }

    // 2. Perform the Fourier Transform
    dft_compute(time_domain, freq_domain, N);

    // 3. Output the results
    printf("\n--- Output Signal (Frequency Domain) ---\n");
    printf("%-5s %-15s %-15s %-10s\n", "k", "Real", "Imag", "Magnitude");

    for (int k = 0; k < N; k++) {
        // Extract real and imaginary parts
        double real_part = creal(freq_domain[k]);
        double imag_part = cimag(freq_domain[k]);
        
        // Calculate magnitude (absolute value) = sqrt(real^2 + imag^2)
        // This tells us "how much" of this frequency is in the signal
        double magnitude = cabs(freq_domain[k]);

        // Clean up very small floating point errors for cleaner printing
        if (magnitude < 1e-10) magnitude = 0.0;
        if (fabs(real_part) < 1e-10) real_part = 0.0;
        if (fabs(imag_part) < 1e-10) imag_part = 0.0;

        printf("%-5d %-15.4f %-15.4f %-10.4f", k, real_part, imag_part, magnitude);

        // Highlight the peaks found
        if (magnitude > 1.0) {
            printf(" <-- Peak Detected");
        }
        printf("\n");
    }

    printf("\nInterpretation:\n");
    printf("You should see peaks at k=1 and k=3 (and their mirrors at N-1 and N-3).\n");
    printf("These correspond to the sin(t) and sin(3t) components we created.\n");

    return 0;
}