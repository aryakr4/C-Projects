#include <stdio.h>
#include <stdlib.h>

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

int StringLength(char *str)
/*Use as stand in function*/{
    int index =  0; 
    int length = 0;
    while(str[index] != '\0'){
	    length++;
	    index++;
    }
    return length;
}


MathOperation GetOperation(char *op)
{
    /* Implement me! */
    if(StringLength(op)  > 1){
	    IssueBadOperationError();
    }
    if(*op == '+'){
return ADD;
    }
    if(*op == '-'){
 return SUBTRACT;
    }
    if(*op == '/'){
	  return DIV;
    }
    if(*op == 'x'){
	 return MULT;
     } else {
	     return UNSUPPORTED;
     }}
    



double StringToDouble(char *str)
{
    int i = 0;
    if(str[0] == '-'){
	   i = 1;}
    double sum = 0;
    double temp = 0;
    int power;
    for(i; i < StringLength(str); i++){
	if(str[i] > 57|| str[i] < 45 || str[i] == 47){
		IssueBadNumberError();
	}	
	if(str[i] == '.'){
		power = 1;
		i +=  1;
		for(i; i < StringLength(str); i++){
			if(str[i] == '-'|| str[i] == '.' || str[i] < 45 || str[i] > 57 || str[i] == 47){
				IssueBadNumberError();
			}
			temp = temp * 10  + (str[i] - '0');
			power = power * 10;	
		}
		break;

	}
	sum = sum * 10 + (str[i] - '0'); 

    }
    
    temp = temp/ power;
    double result = sum + temp;
    if(str[0] == '-'){
	    result = result * -1;
	}
    return result;
    
}


int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
       case ADD:
         result = v+v2;
         break;
       case MULT:
	 result = v*v2;
	 break;
       case SUBTRACT:
	 result = v-v2;
	 break;
       case DIV:
	result = (double)v/(double)v2;
        break;
       case UNSUPPORTED:
	IssueBadOperationError();
    }
    printf("%d\n", (int) result);
 
    return 0;
}
