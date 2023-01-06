
typedef struct RomanSymValue{
    char *sym;
    int value;
} RomanSymValue;

void decimal_to_roman(int input){
    int quotient;
    RomanSymValue ValueArr[14] = 
    {{"I",1},{"IV",4},{"V",5},{"IX",9}, {"X",10},{"XL",40},{"L",50},{"XC",90},
    {"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}};
    printf("%d: ", input);
    for(int j=12;j>=0;j--){
        if (input >= ValueArr[j].value){
            quotient = input / ValueArr[j].value;
            input = input % ValueArr[j].value;
            for (int i=0; i < quotient;i++){
                printf("%s", *&ValueArr[j].sym);

            }
        }
    }
}