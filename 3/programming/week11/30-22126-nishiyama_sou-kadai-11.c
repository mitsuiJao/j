#include<stdio.h>

void maximum(int n, double arr[], double* result){
	double tmp = arr[0];
    for (int i=1; i<n; i++){
		if (tmp < arr[i]){
			tmp = arr[i];	
		}	
	}
	*result = tmp;
}

void minimum(int n, double arr[], double* result){
	double tmp = arr[0];
    for (int i=1; i<n; i++){
		if (tmp > *(arr+i)){
			tmp = *(arr+i);	
		}	
	}
	*result = tmp;
}

void sum(int n, double* arr, double* result){
	double tmp = 0;
    for (int i=0; i<n; i++){
		tmp += *(arr+i);	
	}
	*result = tmp;
}

void sum(int n, double *arr, double* result){
	double tmp = 0;
    for (int i=0; i<n; i++){
		tmp += arr[i];	
	}
	*result = tmp/n;
}

int main(void){
    int n;
    scanf("%d", &n);
    
    double arr[n];
    for (int i=0; i<n; i++){
        scanf("%lf", &arr[i]);
    }
    
    double result;
	minimum(n, arr, &result);
	printf("%lf", result);
	return 0;
}
