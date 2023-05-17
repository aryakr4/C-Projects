#include <stdio.h>

int composite(int num){
	int i;
	for (i = 2; i <=num / 2; i++){
		if (num % i ==0) {
			return 1;
		}
	}
	return 0;
}

int odd(){
	int i;
	for(i=11; i<=500; i+=2){
		if (composite(i)){
			printf("%d is a composite number.\n", i);
		}
	}
}

int main(){
	odd();
}
